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