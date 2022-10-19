#ifndef NEWBERLINWINDOW_H
#define NEWBERLINWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"

namespace Ui {
class newberlinwindow;
}

/// newBerlinWindow
///
/// Class goes through the new berlin travel plan
/// that uses the newly inserted cities
class newberlinwindow : public QMainWindow
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

    explicit newberlinwindow(QWidget *parent = nullptr);
    ~newberlinwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    Ui::newberlinwindow *ui;
    TravelPlan *berlin;
    summarypage *summaryWindow;
    TravelPlan::Receipt cityReceipt;
};

#endif // NEWBERLINWINDOW_H
