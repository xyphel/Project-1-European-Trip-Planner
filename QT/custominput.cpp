#include "custominput.h"
#include "ui_custominput.h"

custominput::custominput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::custominput)
{
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);

    ui->comboBox->addItem("Select City");
    ui->comboBox->setEnabled(true);
    ui->comboBox_2->setEnabled(false);
    ui->comboBox_2->addItem("Select City");

    SetDataBase();
    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT * FROM foods ORDER BY City ASC"); // SQL statement: means to output all values in the table
    QString name = "";
    while(q.next())
    {
        if(name != q.value(0).toString())
        {
            ui->comboBox->addItem(q.value(0).toString());
        }

        name = q.value(0).toString();
    }

    QFont font = ui->label->font();
    font.setPointSize(12);
    ui->textBrowser->setFont(font);
    ui->textBrowser->setText("Starting City: ");

    ConnClose();
}

custominput::~custominput()
{
    delete ui;
    delete customWindow;
}

void custominput::on_comboBox_currentIndexChanged(int index)
{
    ui->comboBox->setEnabled(false);
    ui->comboBox_2->setEnabled(true);

    QString city = ui->comboBox->currentText();
    qDebug() << city;

    ui->textBrowser->setText(ui->textBrowser->toPlainText() + city + "\nNext City: ");

    if(city != "Select City")
    {
        cities.push_back(city);
    }


    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT * FROM foods WHERE NOT City = \'" + ui->comboBox->currentText() + "\'ORDER BY City ASC"); // SQL statement: means to output all values in the table
    QString name = "";
    while(q.next())
    {
        if(name != q.value(0).toString())
        {
            ui->comboBox_2->addItem(q.value(0).toString());
        }

        name = q.value(0).toString();
    }

    ConnClose();
}

void custominput::on_pushButton_clicked()
{
    customWindow = new customwindow(nullptr, cities);

    customWindow->show();
    this->close();
}


void custominput::on_pushButton_2_clicked()
{
    this->close();
}


void custominput::on_pushButton_3_clicked()
{
    if(ui->comboBox_2->currentIndex() != 0)
    {
        QString city = ui->comboBox_2->currentText();

        ui->textBrowser->setText(ui->textBrowser->toPlainText() + city + "\nNext City: ");

        cities.push_back(city);

        ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());

        ui->pushButton->setEnabled(true);
    }

}

