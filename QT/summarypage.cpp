#include "summarypage.h"
#include "ui_summarypage.h"

summarypage::summarypage(QWidget *parent, double cost) :
    QDialog(parent),
    ui(new Ui::summarypage)
{
    ui->setupUi(this);
    ui->textBrowser->setText(QString::number(cost));
}

summarypage::~summarypage()
{
    delete ui;
}

void summarypage::on_pushButton_clicked()
{
    this->close();
}

