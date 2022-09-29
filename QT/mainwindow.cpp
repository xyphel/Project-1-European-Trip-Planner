#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/andre/Documents/CS1D_European_Vacation/DB/Cities.sqlite3");
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
    q.exec("SELECT * FROM distances");

    while(q.next())
    {
        data += "Starting City: " + q.value(0).toString();
        data += " Ending City: " + q.value(1).toString() + "\n";
        data += "Distance between the two: " + q.value(2).toString() + "\n";
    }

    ui->textEdit->setText(data);

    q.clear();
    db.close();
}

