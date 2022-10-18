class CommandQueue
{

}

class SQLDatabase
{
    query(command)
    {
        let commandBuffer = new CommandQueue(command);
        commandBuffer.forEach((value) =>
        {
            
        });
    }
}