#include "customwindow.h"
#include "ui_customwindow.h"

customwindow::customwindow(QWidget *parent, const vector<QString> &citiesVec) :
    QMainWindow(parent),
    ui(new Ui::customwindow)
{
    // setups ui
    ui->setupUi(this);

    // sets the cities to visit to the classes cities
    cities = citiesVec;
    // sets database
    SetDataBase();
    ConnOpen();

    // instantiates a travelPlan
    custom = new TravelPlan(db);

    // instantiates variables
    custom->cityIndex = 0;
    custom->receipt.cost = 0;
    custom->receipt.distanceTraveled = 0;
    custom->currentCity = cities[0];

    // sets up ui
    QFont font = ui->label->font();
    font.setBold(true);
    font.setPointSize(15);
    ui->label->setFont(font);
    font.setBold(false);
    font.setPointSize(18);
    ui->label_2->setFont(font);
    ui->label_2->setText("Welcome to " + custom->currentCity);
    ui->label->setText(custom->currentCity);

    // outputs the food items of the city and adds them to the comboBox
    QSqlQuery q;
    q.exec("SELECT food, Cost FROM foods WHERE City = \'" + custom->currentCity + "\'");
    QString data = "";
    QString dataCombo = "";
    while(q.next())
    {
        dataCombo = q.value(0).toString();
        ui->comboBox->addItem(q.value(0).toString());
        data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

    }

    // sets up ui
    font.setBold(false);
    font.setPointSize(10);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText(data);
    ConnClose();

    // finds all the closest cities recursively
    custom->visitedCities.push_back(custom->currentCity);
    custom->FindClosestCity(custom->currentCity, custom->visitedCities, cities.size(), false, true, cities);
    custom->cityReceipt.cost = 0;

    // displays the cities receipt
    DisplayReceipt();
    }

customwindow::~customwindow()
{
    delete ui;
    delete custom;
}



void customwindow::on_pushButton_2_clicked()
{
    // purchases the food item that the user selected
    ConnOpen();
    QString string = "";
    QString s = "";
    QSqlQuery q;
    s = ui->comboBox->currentText();
    custom->receipt.itemsBought.push_back(s);
    custom->cityReceipt.itemsBought.push_back(s);

    // gets the price of the food item
    string = "SELECT cost FROM foods WHERE food = \'" + s + "\'";
    q.exec(string);
    while(q.next())
    {
        s = q.value(0).toString();
    }

    custom->receipt.costOfItems.push_back(s.toDouble());
    custom->cityReceipt.costOfItems.push_back(s.toDouble());
    custom->cityReceipt.cost += s.toDouble();
    custom->receipt.cost += s.toDouble();

    // updates the city's receipt
    DisplayReceipt();

    qInfo() << custom->receipt.cost;

    ConnClose();
}

void customwindow::on_pushButton_clicked()
{
    // goes to the next city
    if(custom->cityIndex != cities.size() - 1)
    {
        // updates the ui for the new city
        custom->cityReceipt.itemsBought.clear();
        custom->cityReceipt.costOfItems.clear();
        custom->cityReceipt.cost = 0;
        DisplayReceipt();

        ui->comboBox->clear();
        custom->cityIndex++;
        ui->comboBox->clear();
        ConnOpen();
        QSqlQuery q;

        qInfo() << custom->visitedCities[custom->cityIndex];

        custom->currentCity = custom->visitedCities[custom->cityIndex];

        ui->label->setText(custom->currentCity);
        ui->label_2->setText("Welcome to " + custom->currentCity);

        // displays the food items of the new city and adds them to the comboBox
        q.exec("SELECT food, Cost FROM foods WHERE City = \'" + custom->currentCity + "\'");
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
        q.exec("SELECT Distance FROM Distances WHERE Starting_City = \'" + custom->currentCity + "\' AND Ending_City = \'" + custom->visitedCities[custom->cityIndex-1] + "\'");
        while(q.next())
        {
            custom->receipt.distanceTraveled += q.value(0).toDouble();
            qInfo() << custom->receipt.distanceTraveled;

        }
        ConnClose();
    }
    else
    {
        // if all cities visited open summaryPage
        this->hide();
        summaryWindow = new summarypage(this);
        summaryWindow->GetData(custom->receipt);

        summaryWindow->show();
    }
}

void customwindow::DisplayReceipt()
{
    // displays the total cost of items purchased from the current city
    QString receipt = "";
    for(int i = 0; i < custom->cityReceipt.costOfItems.size(); i++)
    {
        receipt += custom->cityReceipt.itemsBought[i] + ": $" + QString::number(custom->cityReceipt.costOfItems[i]) + "\n";
    }

    receipt += "\n\n---------------------------\nTotal cost: $" + QString::number(custom->cityReceipt.cost);

    ui->textBrowser_2->setText(receipt);
}
