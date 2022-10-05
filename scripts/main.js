// index.js
// Dependencies
import { pageAppSettings, pageTripSelector, pageTripCostomizer, pageTripViewer, pageTripRecord } from "./pages";
import { createDatabase, listDistance, listFood, listCities, getDistance, lowestDistance, getFood, addDestination, addFood } from "./database"

// Database Handle
let destinationDB;
let persistentStorage = window.localStorage;
// Global State
let isPlanActive; // jump to active plan
let isPlanDrafted; // jump to saved plan
let isPlanComplete; // jump to plan record

// ---

const localPath = ".."
const remotePath = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main"

async function initDestinationDB()
{

}
async function initConfigurationDB()
{
  volatileStorage.setItem(1);
  sessionStorage.setItem();
}

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
  createDatabase();
  if(persistentStorage.getItem("isAdmin") == null)
  {
    persistentStorage.setItem("isAdmin", "false")
  }
  
}

// Runs after DOM is finished loading
function main()
{
  // DOM (HTML) Elements
  const nav_settings = document.querySelector("#nav-settings");
  const nav_home = document.querySelector("#nav-settings");
  const nav_create = document.querySelector("#nav-settings");

  // Volatile State
  

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

init();