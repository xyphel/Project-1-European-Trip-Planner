const pageRemotePath = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main/sites"

function loadHTML( pageName )
{
    fetch(`${pageRemotePath}/${pageName}.html`).then(
        (response) => 
        {
            document.body.replaceChildren(response)
        }
        // catching possible exceptions
        ).catch(console.error);
}

function pageAppSettings()
{
    loadHTML("appSettings");
}
function pageTripSelector()
{
    loadHTML("tripSelector");
}
function pageTripCostomizer()
{
    loadHTML("tripCustomizer");
}
function pageTripViewer()
{
    loadHTML("tripViewer");
}
function pageTripRecord()
{
    loadHTML("tripRecord");
}

export { pageAppSettings, pageTripSelector, pageTripCostomizer, pageTripViewer, pageTripRecord };