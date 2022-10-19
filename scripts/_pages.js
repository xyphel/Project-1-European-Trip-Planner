const pageRemotePath = "https://raw.githubusercontent.com/xyphel/Project-1-European-Trip-Planner/main/sites";

let page_content;

function helperCreateTitleCards()
{

}





function loadHTML( page_name )
{
    fetch(`${pageRemotePath}/${page_name}.html`,
    {
        method: "GET",
        mode: "cors",
        cache: "no-cache"
    }).then(
        (response) => 
        {
            console.log(response);
            response.text();
        }).then(
        (htmlString) =>
        {
            let parser = new DOMParser();
            console.log(htmlString);
            document.getElementsByTagName("main").innerHTML = htmlString;
            parser.parseFromString("<main><div>Hi<br></div></main>", "text/html");
            
        }
        // catching possible exceptions
        ).then((html) => {
            console.log(html);
            document.body.replaceChildren
        }).catch(console.error);
}

function pageAppSettings()
{
    // Before document is parsed
    document.title = "Settings";
    // After HTML is fully parsed
    page_content.onload = () =>
    {
        if(window.localStorage.getItem("is_admin") === "true")
        {
            document.getElementById("admin-container").style.display = "inline";
        }
    };
}
function pageTripSelector()
{
    document.title = "Selector";
    page_content.onload = () =>
    {

    };
}
function pageTripCostomizer()
{
    document.title = "Customizer";
    page_content.onload = () =>
    {

    };
}
function pageTripViewer()
{
    document.title = "Viewer";
    page_content.onload = () =>
    {

    };
}
function pageTripRecord()
{
    document.title = "Record";
    page_content.onload = () =>
    {

    };
}
/* loadPage
params:
    pageName - string
    pageContainer - container DOM (HTML) Element
*/
function loadPage( page_name )
{
    page_content = document.getElementById("main");
    console.log(`Loading ${page_name}`);
    loadHTML(page_name);
    //page_content.replaceWith( loadHTML(page_name) );


    switch (page_name)
    {
        case "appSettings":
            pageAppSettings();
            break;
        case "tripSelector":
            pageTripSelector();
        case "tripCustomizer":
            pageTripCostomizer();
            break;
        case "tripViewer":
            pageTripViewer();
        case "tripRecord":
            pageTripRecord();
            break;
        default:
            console.error(`Sorry, page ${page_name} does not yet exist!`)
    }
}
window.addEventListener("load", (e) => page_content = document.getElementsByTagName("main"), true);

export { loadPage };