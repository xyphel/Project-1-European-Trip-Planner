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
    const IN_SEARCH = document.getElementById("#in-search");
    const IN_FILE = document.getElementById("#in-file");
    const IN_RESET = document.getElementById("#in-reset");

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