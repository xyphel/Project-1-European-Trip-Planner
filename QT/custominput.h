#ifndef CUSTOMINPUT_H
#define CUSTOMINPUT_H

#include <QDialog>
#include "berlintripwindow.h"

namespace Ui {
class custominput;
}

class custominput : public QDialog
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

    explicit custominput(QWidget *parent = nullptr);
    ~custominput();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::custominput *ui;
    vector<QString> cities;
};

#endif // CUSTOMINPUT_H
