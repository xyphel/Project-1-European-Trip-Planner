#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Select City");
    ui->comboBox_2->addItem("Select City");

    SetDataBase();
    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT * FROM foods ORDER BY City ASC"); // SQL statement: means to output all values in the table
    QString name = "";
    while(q.next())
    {
        if(name != q.value(0).toString())
        {
            ui->comboBox->addItem(q.value(0).toString());
            ui->comboBox_2->addItem(q.value(0).toString());
        }

        name = q.value(0).toString();
    }

    ui->comboBox_2->removeItem(11);

    ConnClose();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete loginWindow;
}

void MainWindow::on_pushButton_clicked()
{
    SetDataBase();
}

void MainWindow::on_pushButton_2_clicked()
{
    tripWindow = new planTripWindow(this);

    tripWindow->show();
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT food, cost FROM foods WHERE City = \'" + ui->comboBox->itemText(index) + "\'"); // SQL statement: means to output all values in the table
    QString data = "";
    while(q.next())
    {
        data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

    }
    ui->textEdit_2->setText(data);

    ConnClose();
}


void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT Distance FROM Distances WHERE Ending_City = 'Rome' AND Starting_City = \'" + ui->comboBox_2->itemText(index) + "\'"); // SQL statement: means to output all values in the table
    QString data = "";
    while(q.next())
    {
        data = "Distance from " + ui->comboBox_2->itemText(index) + " to Rome is ";
        data += q.value(0).toString() + "km";

    }
    ui->textEdit->setText(data);

    ConnClose();
}


void MainWindow::on_actionSign_in_triggered()
{
    loginWindow = new loginwindow();
    loginWindow->show();
}

