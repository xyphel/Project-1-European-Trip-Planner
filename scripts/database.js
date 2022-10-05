/* createDatabase()
  initializes 
*/
let destinationDB;
let planDB;

function createDatabase()
{}
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


function parseDistanceFile()
{}
function parseFoodFile()
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

