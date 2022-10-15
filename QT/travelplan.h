#ifndef TRAVELPLAN_H
#define TRAVELPLAN_H

#include <QtSql/QSqlDatabase>
#include <vector>
#include <QString>

using namespace std;

class TravelPlan
{
private:
    /*! func Compare
     * brief Returns whether two QStrings are equal.
     */
    bool Compare(const QString& str1, const QString& str2);
public:

    vector<QString> visitedCities; /*!< Contains previosly visited cities' names. */
    QSqlDatabase& db; /*!< Poimter to primary, shared sql database. */
    int cityIndex; /*!< Index of current city. */
    int cityCount; /*!< Number of cities in this plan. */
public:
    /*! struct Receipt
     * brief Container for receipt-specific data members.
     */
    struct Receipt
    {
        std::vector<double> costOfItems; /*!< Cost of each purchased item. Order synced with itemsBought */
        std::vector<QString> itemsBought; /*!< Name of each purchased item. Order synced with costOfItems */
        double cost; /*!< Total travel expenses. */
        int distanceTraveled; /*!< Total distance traveled. */
    };
    QString currentCity; /*!< Name of current city. */
    Receipt receipt; /*!< This plan's receipt. */

    /*! func TravelPlan
     * brief Constructor requires a QSqlDatabase reference.
     */
    TravelPlan(QSqlDatabase& db);
    /*! func ~TravelPlan
     * brief Destructor.
     */
    ~TravelPlan();
    /*! func FindClosestCity
     * brief Constructor requires a QSqlDatabase reference.
     */
    void FindClosestCity(const QString& CITY, std::vector<QString>& cities);
    bool CheckIfCityWasVisited(const QString& CITY, std::vector<QString>& visitedCities);

};

#endif // TRAVELPLAN_H
