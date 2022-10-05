#include "summarypage.h"
#include "ui_summarypage.h"

summarypage::summarypage(QWidget *parent, double cost, std::vector<double> costItems, std::vector<QString> items) :
    QDialog(parent),
    ui(new Ui::summarypage)
{
    ui->setupUi(this);
    QString receipt = "";
    for(int i = 0; i < costItems.size(); i++)
    {
        receipt += items[i] + ": $" + QString::number(costItems[i]) + "\n";
    }

    receipt += "\n\n---------------------------\nTotal cost: $" + QString::number(cost);

    ui->textBrowser->setText(receipt);
}

summarypage::~summarypage()
{
    delete ui;
}

void summarypage::on_pushButton_clicked()
{
    this->close();
}

