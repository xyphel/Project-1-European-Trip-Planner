const ROOT_PATH = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main";

const PERSISTENT_STATE = [
    "is_admin",        // modify cities/foods
    "is_plan_active",   // jump to active plan
    "is_plan_complete", // jump to plan record
    "is_plan_drafted"   // jump to saved plan
];
const LOCAL_STORAGE = window.localStorage;

PERSISTENT_STATE.forEach(state_key =>
{
    if(LOCAL_STORAGE.getItem(state_key) === null)
    {
        LOCAL_STORAGE.setItem(state_key, "false")
    }
});

if(LOCAL_STORAGE.getItem("is_plan_active") === "true")
  {
    location.replace(`${ROOT_PATH}/sites/tripViewer`);
  }
  else if( LOCAL_STORAGE.getItem("is_plan_completed") === "true" )
  {
    location.replace(`${ROOT_PATH}/sites/tripRecord`);
  }
  else if( LOCAL_STORAGE.getItem("is_plan_drafted") === "true" )
  {
    location.replace(`${ROOT_PATH}/sites/tripCustomizer`);
  }
  else
  {
    location.replace(`${ROOT_PATH}/sites/tripSelector`);
  }