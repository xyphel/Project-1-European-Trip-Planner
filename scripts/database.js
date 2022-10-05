/* createDatabase()
  initializes 
*/
let destinationDB;
let planDB;

function createDatabase()
{}
function listDistance(cityName)
{}
function listFood(cityName)
{}
function listCities(planName)
{}
function getDistance(city1Name, city2Name)
{}
function lowestDistance(cityList)
{}
function getFood(cityName)
{}
function addDistance(city1Name, city2Name, distance)
{}
function addFood(cityName, foodName, cost)
{}
function addDestination(planName, cityName, cityObject = null)
{

  // Guard statement in case city destinations are not provided
  if( cityObject == null )
  {
    return;
  }

}

function parseDistanceFile()
{}
function parseFoodFile()
{}





export {};



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


