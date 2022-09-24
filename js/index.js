// index.js
// Code

// https://javascript.info/keys-values-entries
function testPrint(inputMap)
{
  Object.keys(inputMap).forEach( startCity =>
  {
    for( const [ endCity, distance] of  Object.entries(inputMap[startCity]) )
    {
      console.log(`From ${startCity} to ${endCity} is ${distance} miles.`);
    }
  });
}

function main()
{
  const distanceRequest = new Request("../data/distances.json");
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
  }
  // catching possible exceptions
  ).catch(console.error);


}
// extending - file & storage apis
