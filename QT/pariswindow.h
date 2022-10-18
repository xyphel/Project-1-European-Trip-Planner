#ifndef PARISWINDOW_H
#define PARISWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"

namespace Ui {
class pariswindow;
}

class pariswindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;

    void SetDataBase()
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        QString path = "C:/Users/andre/Documents/GitHub/Project-1-European-Trip-Planner/QT/DB/Cities.sqlite3";
        qInfo() << path;
        db.setDatabaseName(path);

    }

    void ConnOpen()
    {
        if(db.open())
        {
            qDebug() << ("Connected.");

        } else {

            qDebug() << ("Not Connected.");
        }
    }

    void ConnClose() { db.close();}

    void DisplayReceipt();

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
