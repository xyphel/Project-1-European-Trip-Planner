// SQLim.js
// 
// Includes Hash Map

/**
 * CommandQueue
 * \brief Priority Queue. Convenience container to organize and iterate over each command in a commandList string.
 *//*
class CommandQueue
{
    constructor(commandList)
    {
        commandList.split(";").forEach((command, index) =>
        {
            let commandSplit = command.split(" ");
            this.command[index].operator = commandSplit[0];
            this.command[index].target = commandSplit[1];
            this.command[index].value = commandSplit[3];
        });
    }
}*/

const TABLE_SIZE = 25;

class SQLDatabase
{
    // Properties
    name;
    database;
    hash_table;

    syncDatabase()
    {
        const database_request = window.indexedDB.open(this.name, 0);
        database_request.onerror = (event) =>
        {
            console.error(`${this.name} database request exception: ${event}`);
        }
        database_request.onsuccess = (event) =>
        {
            this.database = event.target.result;
        }
        database_request.onupgradeneeded = (event) =>
        {
            this.database = event.target.result;
            const objectStore = this.database.createObjectStore(this.name, { keyPath: "name" });
            objectStore.createIndex("name", "name", { unique: true });
        }
}
    constructor(name, table_configuration)
    {
        this.name = name;
        syncDatabase();

        if(table_configuration !== undefined)
        {
            for( let i = 0; i < (table_configuration.length / 2); i++)
            {
                this.hash_table[i] = {
                    name: table_configuration[i],
                    size: table_configuration[i + 1]
                }
            }
        }
    }

    async hash()
    {
        
    }

    /**
     * A transaction with the DB
     * @param[in] commandList {List of SQL commands}
     */
    async query(commandList)
    {
        

        let command_buffer = new CommandQueue(commandList);
        for(const command of command_buffer)
        {
            switch(command.shift())
            {
                // getter "SELECT plan_name WHERE item_name IN table_name"
                case "SELECT":
                    if( command === "*" )
                    {
                        this.database.transaction([this.name], "read").objectStore(this.name).getAll().onsuccess = (event) =>
                        {
                            return event.target.result;
                        };
                    }
                    else
                    {
                        this.database.transaction([this.name], "read").objectStore(this.name).get(command.shift()).onsuccess = (event) =>
                        {
                            if( command.shift() === "WHERE" )
                            {
                                command.splice(1, 1);// IN keyword
                                return hash(command.shift(), command.shift());
                            }
                            return event.target.result;
                        };
                    }
                    break;
                // setter "UPDATE plan_name value"
                case "UPDATE":
                    this.database.transaction([this.name], "readwrite").objectStore(this.name).get(command.target);
                    break;
                case "INSERT":
                    this.database.transaction([this.name], "readwrite").objectStore(this.name).get(command.target);
                    break;
                case "DELETE":
                    this.database.transaction([this.name], "readwrite").objectStore(this.name).get(command.target);
                    break;
                default:
                    console.log(`Unknown SQL command used: ${command.operator}`)
            }
        }
    }
    async addFromJSON(jsonFile)
    {
        
    }
}