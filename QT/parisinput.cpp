#include "parisinput.h"
#include "ui_parisinput.h"

parisinput::parisinput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parisinput)
{

    tripWindow = parent;
    ui->setupUi(this);
    checkCities = false;

}

parisinput::~parisinput()
{
    delete ui;
    delete parisWindow;
}

void parisinput::on_buttonBox_accepted()
{
    if(NumCheck(ui->lineEdit->text()))
    {
        int num = ui->lineEdit->text().toInt();
        if((num == 12 || num == 13) && !checkCities)
        {
            QMessageBox::warning(this, "Error", "Data not inserted.");
        }
        else
        {
            int num = ui->lineEdit->text().toInt();
            parisWindow = new pariswindow(nullptr, num);
            parisWindow->show();
            tripWindow->close();
        }

    }
    else
    {
        QMessageBox::warning(this, "Error", "Invalid input.");
    }
}

