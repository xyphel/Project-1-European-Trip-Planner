// index.js
// Function Dependencies
import { loadPage } from "./pages.js";
import {
  createDatabase,
  listDistances, listFoods, listCities, listPlans,
  getDistance, efficientCityOrder, getFoodCost,
  addDistance, addFood, delDistance, delFood, delCity, modDistance, modFoodCost,
  parseDistanceFile, parseFoodFile,
  addPlan, delPlan, modPlanName, addCityToPlan, removeCityFromPlan
} from "./database.js";


// Global State
let local_storage = window.localStorage;
const local_state = [
  "is_admin",        // modify cities/foods
  "is_plan_active",   // jump to active plan
  "is_plan_complete", // jump to plan record
  "is_plan_drafted"   // jump to saved plan
];
// ---

// const localPath = ".."
// const remotePath = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main"



// https://javascript.info/keys-values-entries
/*function testPrint(inputMap)
{
  Object.keys(inputMap).forEach( startCity =>
  {
    for( const [ endCity, distance] of  Object.entries(inputMap[startCity]) )
    {
      console.log(`From ${startCity} to ${endCity} is ${distance} miles.`);
    }
  });
}*/


// Runs immediately after Javascript is parsed
async function init()
{
  // Ensure database exists
  createDatabase();
  // Ensure persistent state exists
  local_state.forEach(state_key =>
  {
    if(local_storage.getItem(state_key) == null)
    {
      local_storage.setItem(state_key, "false")
    }
  });
  if(local_storage.getItem("target_plan") == null)
  {
    local_storage.setItem("target_plan", "false");
  }
}

// Runs after DOM is finished loading
function main()
{
  // DOM (HTML) Elements
  const nav_settings = document.querySelector("#nav-settings");
  const nav_home = document.querySelector("#nav-home");
  const nav_create = document.querySelector("#nav-create");

  // Select landing page based on global state
  if(local_storage.getItem("is_plan_active") === "true")
  {
    loadPage("tripViewer");
  }
  else if( local_storage.getItem("is_plan_completed") === "true" )
  {
    loadPage("tripRecord");
  }
  else if( local_storage.getItem("is_plan_drafted") === "true" )
  {
    loadPage("tripCustomizer");
  }
  else
  {
    loadPage("appSettings");
  }
  //loadPage("appSettings");

  /*
  // replace "remotePath" with "localPath" for local testing
  const distanceRequest = new Request(`${remotePath}/data/distances.json`);
  var cityDistances;
  
  // fetch returns a promise, which   must be handled, in case file is not found
  fetch(distanceRequest).then(

  // Parse JSON into Object: the contents of the file may not be valid JSON, so another promise must be handled
  (response) => response.json()).then(

    // what to do with the city distances object once received
  (distancesObj) =>
  {
    cityDistances = distancesObj;
    testPrint(cityDistances);

      // A temporary HTML demonstration of data
      let tempDisplay = document.getElementById("tempDisplay");
      tempDisplay.textContent = JSON.stringify(cityDistances);
  }
  // catching possible exceptions
  ).catch(console.error);
*/
}

document.body.onload = main();
init();