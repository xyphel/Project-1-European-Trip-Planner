#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QDir dir("../data/Cities.sqlite3");
    QString path = dir.absolutePath();
    ui->setupUi(this);
    qInfo() << path;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    db.open();
    QSqlQuery q;
    QString data = "";
    q.exec("SELECT * FROM distances WHERE Ending_City = 'Rome';"); // SQL statement: means to output all values in the table where ending city is rome

    while(q.next())
    {
        data += "Starting City: " + q.value(0).toString();
        data += "\nEnding City: " + q.value(1).toString() + "\n";
        data += "Distance between the two: " + q.value(2).toString() + "\n\n";
    }

    ui->textEdit->setText(data);

    q.clear();
    db.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    db.open();
    QSqlQuery q;
    QString data = "";
    QString city = "";
    QString newCity = "";
    q.exec("SELECT * FROM foods"); // SQL statement: means to output all values in the table

    while(q.next())
    {
        city = q.value(0).toString();
        if(city != newCity)
        {
            if(data == "")
            {
                data += "City: " + q.value(0).toString();
            }
            else
            {
                data += "\nCity: " + q.value(0).toString();
            }
            data += "\nTraditonal food items:\n";
        }
        data += q.value(1).toString() + ": $" + q.value(2).toString() + "\n";
        newCity = city;
    }

    ui->textEdit_2->setText(data);

    q.clear();
    db.close();
}

void MainWindow::on_pushButton_3_clicked()
{
    tripWindow = new planTripWindow(this);

    tripWindow->show();
}

