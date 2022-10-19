const DB_PLAN_RECORDS = new SQLDatabase("plan_records");

function listPlanRecords()
{
    return DB_PLAN_RECORDS.query(
        "SELECT *"
    );
}
function listCities()
{
    return DB_PLAN_RECORDS.query(
        "SELECT *"
    );
}
function addPlanRecord()
{
    return DB_PLAN_RECORDS.query(
        "INSERT *"
    );
}
function delPlanRecord()
{
    return DB_PLAN_RECORDS.query(
        "DELETE *"
    );
}
function modPlanRecord()
{
    return DB_PLAN_RECORDS.query(
        "UPDATE *"
    );
}
function addCityToPlan()
{
    return DB_PLAN_RECORDS.query(
        "SELECT *"
    );
}
function removeCityFromPlan()
{
    return DB_PLAN_RECORDS.query(
        "SELECT *;" +
        "DELETE "
    );
}

export {
    listPlanRecords, listCities,
    addPlanRecord, delPlanRecord, modPlanRecord,
    addCityToPlan, removeCityFromPlan
  };