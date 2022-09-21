// index.js
// Code

// https://javascript.info/keys-values-entries
function testPrint(inputMap)
{
  for( let startCity of Object.keys(inputMap) )
  {
    for( let endCity of Object.entries(startCity) )
    {
      console.log(”From %s to %s is %i miles.”, startCity, endCity[0], endCity[1]);
    }
  }
}

function main()
{
  const distanceRequest = new Request(“distances.json”);
  var cityDistances;
  
  // fetch returns a promise, which   must be handled, in case file is not found
  fetch(distanceRequest).then(

  // the contents of the file may not be valid JSON, so another promise must be handled
  (response) => response.json()).then(

    // what to do with the city distances object once received
  (distancesObj) =>
    cityDistances = distancesObj

  // catching possible exceptions
  ).catch(console.error);

testPrint(cityDistances);
}
// extending - file & storage apis
