// index.js
// Code

// Database Handle
let destinationDB;
let volatileStorage = window.sessionStorage;
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


async function main()
{
  initDestinationDB();
  initConfigurationDB();
  initGlobals(idb);
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

main();