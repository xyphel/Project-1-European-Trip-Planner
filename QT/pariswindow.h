#ifndef PARISWINDOW_H
#define PARISWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"

namespace Ui {
class pariswindow;
}

/// parisWindow class
///
/// The window that goes through the paris travel plan
/// gets the amount of cities the user wanted to visit
/// and goes through those cities
class pariswindow : public QMainWindow
{
    Q_OBJECT

public:
    /// holds the database for the program
    QSqlDatabase db;

    /// Sets database
    ///
    /// This method gets a path from the administrator and looks for the database
    /// in that given path and sets the database variable to that database
    void SetDataBase()
    {
        // opens database and outputs if it opened sucessfully
        db = QSqlDatabase::addDatabase("QSQLITE");
        QString path = "C:/Users/andre/Documents/GitHub/Project-1-European-Trip-Planner/QT/DB/Cities.sqlite3";
        qInfo() << path;
        db.setDatabaseName(path);

    }

    /// Opens database
    ///
    /// Calls database method to open database and returns to console
    /// if opened properly
    void ConnOpen()
    {
        // opens database and outputs if it opened sucessfully
        if(db.open())
        {
            qDebug() << ("Connected.");

        } else {

            qDebug() << ("Not Connected.");
        }
    }

    /// Closes database
    ///
    /// Calls databse method to close database
    void ConnClose() { db.close();}

    /// Display Receipt
    ///
    /// This method displays the receipt of the items
    /// purchased at the current city
    void DisplayReceipt();

    /// Constructor
    ///
    /// Constructs customWindow takes a int as input which stores the number of cities the user wants to visit
    explicit pariswindow(QWidget *parent = nullptr, int numCities = 1);
    ~pariswindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    Ui::pariswindow *ui;
    TravelPlan *paris;
    summarypage *summaryWindow;
    TravelPlan::Receipt cityReceipt;
    int cities;
};

#endif // PARISWINDOW_H
