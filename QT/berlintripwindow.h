#ifndef BERLINTRIPWINDOW_H
#define BERLINTRIPWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVector>
#include "summarypage.h"

namespace Ui {
class berlinTripWindow;
}

class berlinTripWindow : public QMainWindow
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

    explicit berlinTripWindow(QWidget *parent = nullptr);
    void FindClosestCity(const QString& city, std::vector<QString>& cities);
    bool CheckIfCityWasVisited(const QString& CITY, std::vector<QString>& visitedCities);
    ~berlinTripWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::berlinTripWindow *ui;
    int index;
    Receipt currentReceipt;
    QString cityName;
    std::vector<QString> visitedCities;
    summarypage *summaryWindow;
};

#endif // BERLINTRIPWINDOW_H
