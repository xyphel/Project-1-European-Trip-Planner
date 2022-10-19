#include "pariswindow.h"
#include "ui_pariswindow.h"

pariswindow::pariswindow(QWidget *parent, int numCities) :
    QMainWindow(parent),
    ui(new Ui::pariswindow)
{
    // sets up ui
    ui->setupUi(this);

    // sets number of cities
    cities = numCities;

    // sets database
    SetDataBase();
    ConnOpen();

    // sets up travelPlan object for trip
    paris = new TravelPlan(db);

    // instantiate variables
    paris->cityIndex = 0;
    paris->receipt.cost = 0;
    paris->receipt.distanceTraveled = 0;
    paris->currentCity = "Paris";

    // setup ui for current city
    QFont font = ui->label->font();
    font.setBold(true);
    font.setPointSize(15);
    ui->label->setFont(font);
    font.setBold(false);
    font.setPointSize(18);
    ui->label_2->setFont(font);
    ui->label_2->setText("Welcome to " + paris->currentCity);
    ui->label->setText(paris->currentCity);

    // displays food for current city
    QSqlQuery q;
    q.exec("SELECT food, Cost FROM foods WHERE City = 'Paris'");
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

    // find closest cities using the number of cities wanted to visit
    // recursively
    paris->visitedCities.push_back(paris->currentCity);
    qDebug() << cities;
    paris->FindClosestCity(paris->currentCity, paris->visitedCities, cities);
    paris->cityReceipt.cost = 0;
    DisplayReceipt();
    }

pariswindow::~pariswindow()
{
    delete ui;
    delete paris;
}



void pariswindow::on_pushButton_2_clicked()
{
    // purchases selected food items
    ConnOpen();
    QString string = "";
    QString s = "";
    QSqlQuery q;
    s = ui->comboBox->currentText();
    paris->receipt.itemsBought.push_back(s);
    paris->cityReceipt.itemsBought.push_back(s);
    string = "SELECT cost FROM foods WHERE food = \'" + s + "\'";
    q.exec(string);
    while(q.next())
    {
        s = q.value(0).toString();
    }

    paris->receipt.costOfItems.push_back(s.toDouble());
    paris->cityReceipt.costOfItems.push_back(s.toDouble());
    paris->cityReceipt.cost += s.toDouble();
    paris->receipt.cost += s.toDouble();

    // updates receipt with purchased food item
    DisplayReceipt();

    qInfo() << paris->receipt.cost;

    ConnClose();
}

void pariswindow::on_pushButton_clicked()
{
    // goes to next city
    if(paris->cityIndex != cities - 1)
    {
        // updates ui for the new city
        paris->cityReceipt.itemsBought.clear();
        paris->cityReceipt.costOfItems.clear();
        paris->cityReceipt.cost = 0;
        DisplayReceipt();

        ui->comboBox->clear();
        paris->cityIndex++;
        ui->comboBox->clear();
        ConnOpen();
        QSqlQuery q;

        qInfo() << paris->visitedCities[paris->cityIndex];

        paris->currentCity = paris->visitedCities[paris->cityIndex];

        ui->label->setText(paris->currentCity);
        ui->label_2->setText("Welcome to " + paris->currentCity);

        // displays food items of the current city
        q.exec("SELECT food, Cost FROM foods WHERE City = \'" + paris->currentCity + "\'");
        QString data = "";
        QString dataCombo = "";
        while(q.next())
        {
            dataCombo = q.value(0).toString();
            ui->comboBox->addItem(q.value(0).toString());
            data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

        }
        ui->textBrowser->setText(data);

        // gets distance from previous city to current city and adds it to the total
        q.exec("SELECT Distance FROM Distances WHERE Starting_City = \'" + paris->currentCity + "\' AND Ending_City = \'" + paris->visitedCities[paris->cityIndex-1] + "\'");
        while(q.next())
        {
            paris->receipt.distanceTraveled += q.value(0).toDouble();
            qInfo() << paris->receipt.distanceTraveled;

        }
        ConnClose();
    }
    else
    {
        // if all cities visited open summaryPage
        this->hide();
        summaryWindow = new summarypage(this);
        summaryWindow->GetData(paris->receipt);

        summaryWindow->show();
    }
}

void pariswindow::DisplayReceipt()
{
    // displays the total cost of items purchased from the current city
    QString receipt = "";
    for(int i = 0; i < paris->cityReceipt.costOfItems.size(); i++)
    {
        receipt += paris->cityReceipt.itemsBought[i] + ": $" + QString::number(paris->cityReceipt.costOfItems[i]) + "\n";
    }

    receipt += "\n\n---------------------------\nTotal cost: $" + QString::number(paris->cityReceipt.cost);

    ui->textBrowser_2->setText(receipt);
}

