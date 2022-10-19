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
void TravelPlan::FindClosestCity(const QString& city, std::vector<QString> &cities, int size, bool berlin, bool custom, vector<QString> customCities)
{
    // Base Case
    if(cities.size() < size)
    {
        db.open();
        std::list<QString> End;
        QSqlQuery q;
        QString string;
        if(berlin || custom)
        {
            if(custom)
            {

                string = "SELECT DISTINCT Ending_City FROM Distances WHERE Starting_City = \'" + city + "\'"
                        + "AND ENDING_CITY = \'";
                for(int i = 0; i < customCities.size(); i++)
                {
                    string += customCities[i] + "\' OR Starting_City = \'" + city + "\'"
                            + "AND ENDING_CITY = \'";
                }
                string += "\' ORDER BY Distance ASC";
            }
            else
            {
                string = "SELECT DISTINCT Ending_City FROM Distances WHERE Starting_City = \'" + city + "\'"
                        + "AND NOT ENDING_CITY = 'Stockholm' AND NOT ENDING_CITY = 'Vienna' ORDER BY Distance ASC";
            }

            qDebug() << string;
        }
        else
        {
            string = "SELECT DISTINCT Ending_City FROM Distances WHERE Starting_City = \'" + city + "\' ORDER BY Distance ASC";
        }
        q.exec(string);

        while(q.next())
        {
            End.push_back(q.value(0).toString());
        }

        for(; !CheckIfCityWasVisited(End.front(), cities); End.pop_front());

        cities.push_back(End.front());

        FindClosestCity(End.front(), cities, size, berlin, custom, customCities);
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
