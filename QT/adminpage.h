#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTextStream>
#include <QFile>
#include <QRegularExpression>
#include <QFileDialog>
#include <QMessageBox>
#include <QStringList>


namespace Ui {
class adminpage;
}

/// adminPage class holds admin page
///
/// This class provides functionality to the ui admin page by allowing the user
/// to manupliate the data and add data to the database
class adminpage : public QMainWindow
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

    /// Checks input
    ///
    /// This method takes a num string and checks to see if the input is a number
    /// @param num String num to check if a valid number
    /// @returns valid or not
    bool NumCheck(QString num)
    {
        // checks a string to see if it is a number or not
        num.replace(QString("."), QString(""));
        qDebug() << num;

        bool ok;

        num.toInt(&ok);
        if(ok && num.toInt() > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /// Closes database
    ///
    /// Calls databse method to close database
    void ConnClose() { db.close();}

    /// Displays the data
    ///
    /// Displays the data into models
    /// @param model This parameter is a pointer to the objects current model
    /// @param model2 This parameter is a pointer to the objects current model
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

    /// Add data from file
    ///
    /// This method takes a text file and grabs each line
    /// of data one by one and adds the data to the database
    void AddFromFile(QTextStream& iFile);

private:
    Ui::adminpage *ui;
    QSqlQueryModel* model;
    QSqlQueryModel* model2;
};

#endif // ADMINPAGE_H
