const pageRemotePath = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main/sites"

function loadHTML( pageName, pageContainer )
{
    fetch(`${pageRemotePath}/${pageName}.html`).then(
        (response) => 
        {
            pageContainer.replaceWith(response);
        }
        // catching possible exceptions
        ).catch(console.error);
}

function pageAppSettings()
{
    // Before document is parsed
    document.title = "Settings"
    // After HTML is fully parsed
    pageContainer.onload = () =>
    {

    };
}
function pageTripSelector()
{
    document.title = "Selector"
    pageContainer.onload = () =>
    {

    };
}
function pageTripCostomizer()
{
    document.title = "Customizer"
    pageContainer.onload = () =>
    {

    };
}
function pageTripViewer()
{
    document.title = "Viewer"
    pageContainer.onload = () =>
    {

    };
}
function pageTripRecord()
{
    document.title = "Record"
    pageContainer.onload = () =>
    {

    };
}
/* loadPage
params:
    pageName - string
    pageContainer - container DOM (HTML) Element
*/
function loadPage( pageName, pageContainer )
{
    loadHTML(pageName);
    switch (pageName)
    {
        case "appSettings":
            pageAppSettings();
            break;
        case "tripSelector":
            pageTripSelector();
        default:
            console.error(`Sorry, page ${pageName} does not yet exist!`)
    }
}

export { loadPage };