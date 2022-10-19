#include "summarypage.h"
#include "ui_summarypage.h"

summarypage::summarypage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::summarypage)
{
    ui->setupUi(this);
}

summarypage::~summarypage()
{
    delete ui;
}

void summarypage::GetData(TravelPlan::Receipt currentReceipt)
{
    // gets data and outputs it to the ui
    QString receipt = "";
    QString distance = "";

    // outputs each item bought and the cost of it
    for(int i = 0; i < currentReceipt.costOfItems.size(); i++)
    {
        receipt += currentReceipt.itemsBought[i] + ": $" + QString::number(currentReceipt.costOfItems[i]) + "\n";
    }

    // outputs the total cost
    receipt += "\n\n---------------------------\nTotal cost: $" + QString::number(currentReceipt.cost);

    // outputs the distancet traveled
    distance = "Distance Traveled: " + QString::number(currentReceipt.distanceTraveled) + "km";

    ui->textBrowser->setText(receipt);
    ui->textBrowser_2->setText(distance);
}

void summarypage::on_pushButton_clicked()
{
    // closes window
    this->close();
}

