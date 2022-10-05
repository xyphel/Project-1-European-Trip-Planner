//#ifndef TRAVELPLAN_H
//#define TRAVELPLAN_H

//#include <QtSql/QSqlDatabase>
//#include <vector>
//#include <string>

//using namespace std;

//struct Location
//{
//    string cityName;
//    int distance;
//};


//class TravelPlan
//{
//protected:
//    // currentLocation is composed of
//    //  1. cityName: string of city name
//    //  2. distance: total number of km traveled
//    Location currentLocation;
//    vector<string> destinations;
//public:
//    // Construct & Destruct
//    TravelPlan();
//    ~TravelPlan();
//    // Read-only properties
//    string currentCity();
//    int distanceTraveled();
//    // Mutators include a recursive sort
//<<<<<<< HEAD
//    void addDestination(string city);
//    void removeDestination(string city);
//    //void GetDatabase(); ???
//=======
//>>>>>>> e960ce450a589a15eab2be34385a25753824025e

//    // TravelPlan already owns detinations, so only
//    // SQL database handle is needed.
//    Location findNearestDestination(QSqlDatabase* db);
//    vector<Location> findQuickestRoute(vector<string> destinations, QSqlDatabase* db);
//};

//#endif // TRAVELPLAN_H
