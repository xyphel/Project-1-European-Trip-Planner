const dataRemotePath = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main/data";
const initSqlJs = window.initSqlJs;
let destinationsDB;
//let distanceDB;
//let foodDB;
let planDB;

/* createDatabase()
  initializes 
*/
function createDatabase()
{
  let databaseObject;
  fetch(`${dataRemotePath}/distances.json`).then(
    // Parse JSON into Object: the contents of the file may not be valid JSON, so another promise must be handled
    (response) => response.json()).then(
    // what to do with the city distances object once received
    (destinationsObject) =>
  {
    databaseObject = Uint8Array.from(destinationsObject);
  }
  // catching possible exceptions
  ).catch(console.error);
  const SQL = await initSqlJs({
    locateFile: file => `https://sql.js.org/dist/${file}`;
  });
  destinationsDB = new SQL.Database(databaseObject);
  /* ======= IndexedDB is not relational =======
  const requestPlanDB = window.indexedDB.open("TravelPlan", 0);
  requestPlanDB.onerror = (event) =>
  {
    console.error(`PlanDB request exception: ${event}`);
  }
  requestPlanDB.onsuccess = (event) =>
  {
    planDB = event.target.result;
  }
  requestPlanDB.onupgradeneeded = (event) =>
  {
    planDB = event.target.result;
    // Create object stores for each origin city
    fetch(`${dataRemotePath}/plan-templates.json`).then(
      // Parse JSON into Object: the contents of the file may not be valid JSON, so another promise must be handled
      (response) => response.json()).then(
      // what to do with the city distances object once received
      (plansFileObject) =>
    {
      Object.keys(plansFileObject).forEach( planName =>
        {
          const planStore = distanceDB.createObjectStore(planName);
          cityOriginStore.createIndex("food", "", {unique: true});
          for( const [ cityDestination, distance] of  Object.entries(distancesFileObject[cityOrigin]) )
          {
            cityOriginStore.
          }
        });
      for (let cityDistancesObject in distancesFileObject)
      {
        
        cityOriginStore
      }
    }
    // catching possible exceptions
    ).catch(console.error);
    
    
  }

  destinationDB.onerror = (event) =>
  {
    console.error(`DistanceDB database exception: ${event}`);
  }*/
}

/*  ==== LocationDB ====  */
/// Samplers
/* listDestinations

*/
function listDistances(cityOrigin)
{}
function listFoods(cityOrigin)
{}
function listCities(planName)
{}
function listPlans()
{}
function getDistance(cityOrigin, cityDestination)
{}
function efficientCityOrder(cityOrigin, cityDestinationList)
{
  let orderedCities = [cityOrigin];
  if(cityDestinationList.length == 0)
  {
    return cityOrigin;
  }
  else
  {
    let lowestDistance = getDistance(cityOrigin, cityDestinationList[0]);
    let lowestDistanceIndex = 0;
    for(let i = 1; i < cityDestinationList.length; i++)
    {
      let currentDistance = getDistance(cityOrigin, cityDestinationList[i]);
      if( currentDistance < lowestDistance)
      {
        lowestDistance = currentDistance;
        lowestDistanceIndex = i;
      }
    }
    const cityNext = cityDestinationList[lowestDistanceIndex];
    orderedCities = orderedCities.concat(efficientCityOrder(city))
  }
}
function getFoodCost(cityOrigin, foodName)
{}

/// Mutators (Admin Only)
function addDistance(cityOrigin, cityDestination, distance)
{}
function addFood(cityOrigin, foodName, cost)
{}
function delDistance( cityOrigin, cityDestination )
{}
function delFood(cityOrigin, foodName)
{}
function delCity( cityOrigin )
{}

function modDistance(city1Name, city2Name, distance)
{}
function modFoodCost(cityName, foodName, cost)
{}


function parseDistanceFile( fileContent )
{}
function parseFoodFile( fileContent )
{}
/*  ========  */

/*  ==== Plan DB ====  */
/// Custom Plan Helpers
function addPlan( planName, planObject = null )
{}
function delPlan( planName )
{}
function modPlanName( planOldName, planNewName )
{}
function addCityToPlan(planName, cityName)
{}
function removeCityFromPlan(planName, cityName)
{}
/*  ========  */



export {
  createDatabase,
  listDistances, listFoods, listCities, listPlans,
  getDistance, efficientCityOrder, getFoodCost,
  addDistance, addFood, delDistance, delFood, delCity, modDistance, modFoodCost,
  parseDistanceFile, parseFoodFile,
  addPlan, delPlan, modPlanName, addCityToPlan, removeCityFromPlan
};


/*
// https://web.dev/indexeddb/
function initIndexedDB
 {
// Check for support.
if (!("indexedDB" in window)) {
    console.log("This browser doesn't support IndexedDB.");
    return;
  }
  
  const dbPromise = window.indexedDB.open("EuropeanDestinations", 1, function (upgradeDb) {
    if (!upgradeDb.objectStoreNames.contains("food") {
      upgradeDb.createObjectStore("food", { keyPath: "food" });
    }
    if (!upgradeDb.objectStoreNames.contains("distances")) {
      upgradeDb.createObjectStore("distances", { keypath: "distances", autoIncrement: true });
    }
    if (!upgradeDb.objectStoreNames.contains("logs")) {
      upgradeDb.createObjectStore("logs", { keyPath: "id", autoIncrement: true });
    }
  });
 }
*/

