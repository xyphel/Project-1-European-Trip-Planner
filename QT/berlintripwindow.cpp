#include "berlintripwindow.h"
#include "ui_berlintripwindow.h"
#include <QDebug>

bool Compare(const QString& str1, const QString& str2);

berlinTripWindow::berlinTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::berlinTripWindow)
{
    ui->setupUi(this);

    SetDataBase();
    ConnOpen();

    berlin = new TravelPlan(db);

    berlin->cityIndex = 0;
    berlin->receipt.cost = 0;
    berlin->receipt.distanceTraveled = 0;
    berlin->currentCity = "Berlin";

    QFont font = ui->label->font();
    font.setBold(true);
    font.setPointSize(15);
    ui->label->setFont(font);
    font.setBold(false);
    font.setPointSize(18);
    ui->label_2->setFont(font);
    ui->label_2->setText("Welcome to " + berlin->currentCity);
    ui->label->setText(berlin->currentCity);

    QSqlQuery q;
    q.exec("SELECT food, Cost FROM foods WHERE City = 'Berlin'");
    QString data = "";
    QString dataCombo = "";
    while(q.next())
    {
        dataCombo = q.value(0).toString();
        ui->comboBox->addItem(q.value(0).toString());
        data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

    }
    font.setBold(false);
    font.setPointSize(10);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText(data);
    ConnClose();

    berlin->visitedCities.push_back(berlin->currentCity);
    berlin->FindClosestCity(berlin->currentCity, berlin->visitedCities);

}

berlinTripWindow::~berlinTripWindow()
{
    delete ui;
    delete berlin;
}



void berlinTripWindow::on_pushButton_2_clicked()
{
    ConnOpen();
    QString string = "";
    QString s = "";
    QSqlQuery q;
    s = ui->comboBox->currentText();
    berlin->receipt.itemsBought.push_back(s);
    string = "SELECT cost FROM foods WHERE food = \'" + s + "\'";
    q.exec(string);
    while(q.next())
    {
        s = q.value(0).toString();
    }

    berlin->receipt.costOfItems.push_back(s.toDouble());
    berlin->receipt.cost += s.toDouble();
    qInfo() << berlin->receipt.cost;

    ConnClose();
}

void berlinTripWindow::on_pushButton_clicked()
{
    if(berlin->cityIndex != 9)
    {
        ui->comboBox->clear();
        berlin->cityIndex++;
        ui->comboBox->clear();
        ConnOpen();
        QSqlQuery q;

        qInfo() << berlin->visitedCities[berlin->cityIndex];

        berlin->currentCity = berlin->visitedCities[berlin->cityIndex];

        ui->label->setText(berlin->currentCity);
        ui->label_2->setText("Welcome to " + berlin->currentCity);

        q.exec("SELECT food, Cost FROM foods WHERE City = \'" + berlin->currentCity + "\'");
        QString data = "";
        QString dataCombo = "";
        while(q.next())
        {
            dataCombo = q.value(0).toString();
            ui->comboBox->addItem(q.value(0).toString());
            data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

        }
        ui->textBrowser->setText(data);

        q.exec("SELECT Distance FROM Distances WHERE Starting_City = \'" + berlin->currentCity + "\' AND Ending_City = \'" + berlin->visitedCities[berlin->cityIndex-1] + "\'");
        while(q.next())
        {
            berlin->receipt.distanceTraveled += q.value(0).toDouble();
            qInfo() << berlin->receipt.distanceTraveled;

        }
        ConnClose();
    }
    else
    {
        this->hide();
        summaryWindow = new summarypage(this);
        summaryWindow->GetData(berlin->receipt);

        summaryWindow->show();
    }

}

