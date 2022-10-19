#ifndef CUSTOMINPUT_H
#define CUSTOMINPUT_H

#include <QDialog>
#include "berlintripwindow.h"
#include "customwindow.h"

namespace Ui {
class custominput;
}

/// customInput
///
/// Gets the starting city and all the other
/// cities the user wants to visit on their custom trip
class custominput : public QDialog
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

    explicit custominput(QWidget *parent = nullptr);
    ~custominput();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::custominput *ui;
    customwindow *customWindow;
    vector<QString> cities;
};

#endif // CUSTOMINPUT_H
