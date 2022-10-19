const DB_DESTINATIONS = new SQLDatabase("destinations", ["distances", 30, "foods", 10]);

function listDistances()
{
  return DB_DESTINATIONS.query(
    "SELECT * FROM distances"
  );
}
function listFoods()
{
  return DB_DESTINATIONS.query(
    "SELECT * FROM distances"
  );
}
function getDistance()
{
  
}
function getFoodCost()
{
  
}
function efficientCityOrder()
{
  
}
function addDistance()
{
  
}
function addFood()
{
  
}
function delDistance()
{
  
}
function delFood()
{
  
}
function delCity()
{
  
}
function modDistance()
{
  
}
function modFoodCost()
{
  
}
function parseDestinationFile()
{
  
}
function resetDestinationsDB()
{
  
}


export {
    listDistances, listFoods,
    getDistance, getFoodCost, efficientCityOrder,
    addDistance, addFood,
    delDistance, delFood, delCity,
    modDistance, modFoodCost,
    parseDestinationFile,
    resetDestinationsDB
  };