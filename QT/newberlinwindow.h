#ifndef NEWBERLINWINDOW_H
#define NEWBERLINWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"

namespace Ui {
class newberlinwindow;
}

class newberlinwindow : public QMainWindow
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
