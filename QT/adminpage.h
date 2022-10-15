#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

namespace Ui {
class adminpage;
}

class adminpage : public QMainWindow
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

    void DisplayData(QSqlQueryModel* model, QSqlQueryModel* model2);

    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

private slots:
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::adminpage *ui;
};

#endif // ADMINPAGE_H
