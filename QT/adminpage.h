#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

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

    bool NumCheck(QString num)
    {
        num.replace(QString("."), QString(""));
        qDebug() << num;

        bool ok;

        num.toInt(&ok);
        if(ok && num.size() < 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void ConnClose() { db.close();}

    void DisplayData(QSqlQueryModel* model, QSqlQueryModel* model2);

    explicit adminpage(QWidget *parent = nullptr);
    ~adminpage();

private slots:
    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::adminpage *ui;
    QSqlQueryModel* model;
    QSqlQueryModel* model2;
};

#endif // ADMINPAGE_H
