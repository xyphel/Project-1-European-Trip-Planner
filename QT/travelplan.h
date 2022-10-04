#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QtSql/QSqlDatabase>
#include <vector>
#include <string>

using namespace std;

struct Location
{
    string cityName;
    int distance;
};


class TravelPlan
{
protected:
    // currentLocation is composed of
    //  1. cityName: string of city name
    //  2. distance: total number of km traveled
    Location currentLocation;
    vector<string> destinations;
public:
    // Construct & Destruct
    TravelPlan();
    ~TravelPlan();
    // Read-only properties
    string currentCity();
    // Mutators include a recursive sort
    void addDestination();
    void removeDestination();

    // TravelPlan already owns detinations, so only
    // SQL database handle is needed.
    Location findNearestDestination(QSqlDatabase* db);

};

#endif // TRAVELPLAN_H
