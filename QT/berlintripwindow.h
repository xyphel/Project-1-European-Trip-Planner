#ifndef BERLINTRIPWINDOW_H
#define BERLINTRIPWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVector>
#include "summarypage.h"
#include "travelplan.h"

namespace Ui {
class berlinTripWindow;
}

/// berlinTripWindow
///
/// Displays the initial berlin trip plan
class berlinTripWindow : public QMainWindow
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
        // sets database path and name for the database variable
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

    explicit berlinTripWindow(QWidget *parent = nullptr);
    ~berlinTripWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    Ui::berlinTripWindow *ui;
    TravelPlan *berlin;
    summarypage *summaryWindow;
    TravelPlan::Receipt cityReceipt;
};

#endif // BERLINTRIPWINDOW_H
