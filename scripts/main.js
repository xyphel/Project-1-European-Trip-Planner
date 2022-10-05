// index.js
// Function Dependencies
import { loadPage } from "./pages.js";
import {
  createDatabase,
  listDistance, listFood, listCities, listPlans,
  getDistance, lowestDistance, getFood,
  addDistance, addFood, addCity,
  parseDistanceFile, parseFoodFile
} from "./database.js";


// Global State
let persistentStorage = window.localStorage;
const persistentState = [
  "isAdmin",        // modify cities/foods
  "isPlanActive",   // jump to active plan
  "isPlanComplete", // jump to plan record
  "isPlanDrafted"   // jump to saved plan
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
  // Ensure global state exists
  persistentState.forEach(stateKey =>
  {
    if(persistentStorage.getItem(stateKey) == null)
    {
      persistentStorage.setItem(stateKey, "false")
    }
  });
}

// Runs after DOM is finished loading
function main()
{
  // DOM (HTML) Elements
  const nav_settings = document.querySelector("#nav-settings");
  const nav_home = document.querySelector("#nav-settings");
  const nav_create = document.querySelector("#nav-settings");
  const page_content = document.querySelector("main");

  // Select landing page based on global state
  if(persistentStorage.getItem("isPlanActive") == true)
  {
    loadPage("tripViewer");
  }
  else if( persistentStorage.getItem("isPlanCompleted") == true )
  {
    loadPage("tripRecord");
  }
  else if( persistentStorage.getItem("isPlanDrafted") == true )
  {
    loadPage("tripSelector");
  }


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