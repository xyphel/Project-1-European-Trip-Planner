#include "parisinput.h"
#include "ui_parisinput.h"

parisinput::parisinput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::parisinput)
{
    // sets tripWindow as the parent so if
    // the input is valid it can close previous window
    tripWindow = parent;

    ui->setupUi(this);

}

parisinput::~parisinput()
{
    delete ui;
    delete parisWindow;
}

void parisinput::on_buttonBox_accepted()
{
    // checks input to make sure it's valid
    if(NumCheck(ui->lineEdit->text()))
    {
        // if valid but expecting data to be inserted
        // tell user data isn't inserted
        int num = ui->lineEdit->text().toInt();
        if((num == 12 || num == 13))
        {
            QMessageBox::warning(this, "Error", "Data not inserted.");
        }
        else
        {
            // if valid pass the number of cities to pariswindow
            // and open a pariswindow
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

