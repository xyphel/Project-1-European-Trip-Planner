#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QtSql/QSqlDatabase>
#include <vector>
#include <QString>

using namespace std;

/// TravelPlan class
///
/// Holds the functionality and the data used for the different
/// travel plans
class TravelPlan
{
private:
    /// Compare cities
    ///
    /// Checks if two city strings are the same
    /// @param city1 first city name
    /// @param city2 second city name
    /// @returns if they are the same or not
    bool Compare(const QString& city1, const QString& city2);
public:
    /// Contains previosly visited cities' names.
    vector<QString> visitedCities;
    /// Pointer to primary, shared sql database.
    QSqlDatabase& db;
    /// Index of current city.
    int cityIndex;
    /// Number of cities in this plan.
    int cityCount;
public:
    /// Receipt struct
    ///
    /// Holds the items needed to display the receipt
    struct Receipt
    {
        /// Cost of each purchased item. Order synced with itemsBought
        std::vector<double> costOfItems;
        /// Name of each purchased item. Order synced with costOfItems
        std::vector<QString> itemsBought;
        /// Total travel expenses
        double cost;
        /// Total distance traveled.
        int distanceTraveled;
    };
    /// Name of current city
    QString currentCity;
    /// This plan's receipt
    Receipt receipt;
    /// This plan's current city receipt
    Receipt cityReceipt;

    /// TravelPlan constructor
    ///
    /// Constructs TravelPlan object needs database
    TravelPlan(QSqlDatabase& db);

    ~TravelPlan();

    /// Finds closest city
    ///
    /// This method recursively finds the closest city
    /// @param city city to find closest city to
    /// @param cities vector of cities that will be visisted
    /// @param size amount of cities wanting to visit
    /// @param berlin if the method is being used for the initial berlin plan
    /// @param custom if the method is being used for the custom plan
    /// @param customCities custom set of cities to visit
    void FindClosestCity(const QString& city, std::vector<QString> &cities, int size = 11, bool berlin = false, bool custom = false,
                         vector<QString> customCities = vector<QString>());

    /// Checks if city was visited
    ///
    /// Goes through the vector of cities to see if the passed city was already visited
    /// @param city city to check if visited
    /// @param visitedCities vector of cities already visited
    bool CheckIfCityVisited(const QString& city, std::vector<QString>& visitedCities);

};

#endif // TRAVELPLAN_H
