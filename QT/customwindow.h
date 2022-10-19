#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"

namespace Ui {
class customwindow;
}

class customwindow : public QMainWindow
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

    explicit customwindow(QWidget *parent = nullptr, const vector<QString> &citiesVec = vector<QString>());
    ~customwindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

protected:
    Ui::customwindow *ui;
    TravelPlan *custom;
    summarypage *summaryWindow;
    TravelPlan::Receipt cityReceipt;
    vector<QString> cities;
};

#endif // CUSTOMWINDOW_H
