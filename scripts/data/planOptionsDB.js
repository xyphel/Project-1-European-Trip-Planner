const DB_PLAN_OPTIONS = new SQLDatabase("plan_options");

function listPlanOptions()
{
    return DB_PLAN_OPTIONS.query(
        "SELECT *"
    );
}
function getPlanOption(plan_name)
{
    return DB_PLAN_OPTIONS.query(
        "SELECT *"
    );
}
async function addPlanOption(plan_object)
{
    return DB_PLAN_OPTIONS.query(
        "INSERT *"
    );
}
async function delPlanOption(plan_name)
{
    return DB_PLAN_OPTIONS.query(
        "DELETE "
    );
}
function resetPlanOptionsDB()
{
  
}

export {
    listPlanOptions,
    getPlanOption, addPlanOption, delPlanOption,
    resetPlanOptionsDB
  };