const ROOT_PATH = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main";

const PERSISTENT_STATE = [
    "is_admin",        // modify cities/foods
    "is_plan_active",   // jump to active plan
    "is_plan_complete", // jump to plan record
    "is_plan_drafted"   // jump to saved plan
];

PERSISTENT_STATE.forEach(state_key =>
{
    if(local_storage.getItem(state_key) == null)
    {
        local_storage.setItem(state_key, "false")
    }
});