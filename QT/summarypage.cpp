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
    QString receipt = "";
    for(int i = 0; i < currentReceipt.costOfItems.size(); i++)
    {
        receipt += currentReceipt.itemsBought[i] + ": $" + QString::number(currentReceipt.costOfItems[i]) + "\n";
    }

    receipt += "\n\n---------------------------\nTotal cost: $" + QString::number(currentReceipt.cost);
    receipt += "\n\nDistance Traveled: " + QString::number(currentReceipt.distanceTraveled) + "km";

    ui->textBrowser->setText(receipt);
}

void summarypage::on_pushButton_clicked()
{
    this->close();
}

