#ifndef PLANTRIPWINDOW_H
#define PLANTRIPWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"
#include "loginwindow.h"
#include "newberlinwindow.h"
#include "parisinput.h"
#include "custominput.h"

namespace Ui {
class planTripWindow;
}

/// planTripWindow class
///
/// Holds the buttons to all the trip plans
/// and sends the user to the specified plan they chose
class planTripWindow : public QMainWindow
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

    /// Checks if new cities were added
    ///
    /// Checks if the new cities were added to be used in this
    /// travel plan
    /// @returns if cities were added or not
    bool CheckCitiesAdded();

    explicit planTripWindow(QWidget *parent = nullptr);
    ~planTripWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionSign_in_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::planTripWindow *ui;
    berlinTripWindow *berlinPlanWindow;
    newberlinwindow *newBerlinPlanWindow;
    loginwindow *loginWindow;
    parisinput *parisInput;
    custominput *customInput;
};

#endif // PLANTRIPWINDOW_H
