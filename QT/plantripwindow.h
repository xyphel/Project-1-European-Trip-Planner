#ifndef PLANTRIPWINDOW_H
#define PLANTRIPWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"
#include "loginwindow.h"
#include "newberlinwindow.h"

namespace Ui {
class planTripWindow;
}

class planTripWindow : public QMainWindow
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

    explicit planTripWindow(QWidget *parent = nullptr);
    ~planTripWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionSign_in_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::planTripWindow *ui;
    berlinTripWindow *berlinPlanWindow;
    newberlinwindow *newBerlinPlanWindow;
    loginwindow *loginWindow;
};

#endif // PLANTRIPWINDOW_H
