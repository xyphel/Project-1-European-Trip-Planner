#include "travelplan.h"

#include <vector>
#include <list>
#include <QString>
#include <QSqlQuery>

using namespace std;

TravelPlan::TravelPlan(QSqlDatabase& db): db{db}
{}
TravelPlan::~TravelPlan()
{}
void TravelPlan::FindClosestCity(const QString& city, std::vector<QString> &cities)
{
    // Base Case
    if(cities.size() != 10)
    {
        db.open();
        std::list<QString> End;
        QSqlQuery q;
        QString string = "SELECT Ending_City FROM Distances WHERE Starting_City = \'" + city + "\' ORDER BY Distance ASC";
        q.exec(string);

        while(q.next())
        {
            End.push_back(q.value(0).toString());
        }

        for(; !CheckIfCityWasVisited(End.front(), cities); End.pop_front());

        cities.push_back(End.front());

        FindClosestCity(End.front(), cities);
    }

    db.close();
}

bool TravelPlan::CheckIfCityWasVisited(const QString& CITY, std::vector<QString>& visitedCities)
{

    for(unsigned int i = 0; i < visitedCities.size(); i++)
    {
        if(Compare(CITY, visitedCities[i]))
            return false;
    }
    return true;
}

bool TravelPlan::Compare(const QString& str1, const QString& str2)
{
    // returns true if they are equal
    if(str1.size() != str2.size())
        return false;

    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}

//string TravelPlan::currentCity()
//{
//    return currentLocation.cityName;
//}
//int TravelPlan::distanceTraveled()
//{
//    return currentLocation.distance;
//}
//// Mutators include a recursive sort
//void TravelPlan::addDestination(string city)
//{

//}
//void TravelPlan::removeDestination(string city)
//{
//    for(auto it = destinations.begin(); it != destinations.end(); it++)
//    {
//        if(*it == city)
//        {
//            destinations.erase(it);
//            break;
//        }
//    }
//}


//Location TravelPlan::findNearestDestination(vector<string> destinations, QSqlDatabase* db)
//{

//}
//vector<Location> TravelPlan::findQuickestRoute(vector<string> destinations, QSqlDatabase* db)
//{}
