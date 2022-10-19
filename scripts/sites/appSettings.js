import {
    addDestinationsFromFile,
    resetDestinationsDB
  } from `${ROOT_PATH}/scripts/data/destinationsDB.js`;
import {
    resetPlanOptionsDB
  } from `${ROOT_PATH}/scripts/data/destinationsDB.js`;
import {
    resetPlanRecordsDB
  } from `${ROOT_PATH}/scripts/data/destinationsDB.js`;

function load()
{
    const IN_SEARCH = document.querySelector("#in-search");
    const IN_FILE = document.querySelector("#in-file");
    const IN_RESET = document.querySelector("#in-reset");

    IN_SEARCH.onchange = (event) =>
    {

    }
    IN_FILE.onchange = (event) =>
    {
        addDestinationsFromFile(event.target.files[0]);
        this.value = null;
    }
    IN_RESET.onchange = (event) =>
    {
        resetDestinationsDB();
        resetPlanOptionsDB();
        resetPlanRecordsDB();
    }
}

window.onload = load();