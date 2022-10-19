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
        // opens database
        db.open();
        std::list<QString> End;
        QSqlQuery q;
        QString string;

        // if berlin plan or custom plan execute a different sql statement
        if(berlin || custom)
        {
            // if custom add each city the user wants to visit into the sql statement
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
                // if berlin excluded the added cities from the sql statement
                string = "SELECT DISTINCT Ending_City FROM Distances WHERE Starting_City = \'" + city + "\'"
                        + "AND NOT ENDING_CITY = 'Stockholm' AND NOT ENDING_CITY = 'Vienna' ORDER BY Distance ASC";
            }

            qDebug() << string;
        }
        else
        {
            // default sql statement
            string = "SELECT DISTINCT Ending_City FROM Distances WHERE Starting_City = \'" + city + "\' ORDER BY Distance ASC";
        }
        q.exec(string);

        // get first closest city from current city and add it to list
        while(q.next())
        {
            End.push_back(q.value(0).toString());
        }

        // check if the city has been visisted
        for(; !CheckIfCityVisited(End.front(), cities); End.pop_front());

        // add to the vector if it hasn't
        cities.push_back(End.front());

        // recall function until you reach amount of cities wanted to visit
        FindClosestCity(End.front(), cities, size, berlin, custom, customCities);
    }

    db.close();
}

bool TravelPlan::CheckIfCityVisited(const QString& city, std::vector<QString>& visitedCities)
{
    // checks the cities vector to if the city passed has been visited before
    for(unsigned int i = 0; i < visitedCities.size(); i++)
    {
        if(Compare(city, visitedCities[i]))
            return false;
    }
    return true;
}

bool TravelPlan::Compare(const QString& city1, const QString& city2)
{
    // returns true if they are equal
    if(city1.size() != city2.size())
        return false;

    for(int i = 0; i < city1.size(); i++)
    {
        if(city1[i] != city2[i])
            return false;
    }
    return true;
}
