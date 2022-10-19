#include "custominput.h"
#include "ui_custominput.h"

custominput::custominput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::custominput)
{
    // sets up ui
    ui->setupUi(this);
    ui->pushButton->setEnabled(false);

    ui->comboBox->addItem("Select City");
    ui->comboBox->setEnabled(true);
    ui->comboBox_2->setEnabled(false);
    ui->comboBox_2->addItem("Select City");

    // sets database and display all cities and adds them to the comboBox
    SetDataBase();
    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT * FROM foods ORDER BY City ASC");
    QString name = "";
    while(q.next())
    {
        if(name != q.value(0).toString())
        {
            ui->comboBox->addItem(q.value(0).toString());
        }

        name = q.value(0).toString();
    }

    // sets text for the custom trip log ui
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
    // select starting city
    // once starting city is selected disable the option to select a starting city
    // and enable the option to select another city
    ui->comboBox->setEnabled(false);
    ui->comboBox_2->setEnabled(true);

    // adds the city to the trip log ui
    QString city = ui->comboBox->currentText();
    qDebug() << city;

    ui->textBrowser->setText(ui->textBrowser->toPlainText() + city + "\nNext City: ");

    // adds the city to the vector of cities
    if(city != "Select City")
    {
        cities.push_back(city);
    }

    // adds remaining cities to the new comboBox
    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT * FROM foods WHERE NOT City = \'" + ui->comboBox->currentText() + "\'ORDER BY City ASC");
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
    // finishes custom trip input and starts custom trip
    customWindow = new customwindow(nullptr, cities);

    customWindow->show();
    this->close();
}


void custominput::on_pushButton_2_clicked()
{
    // closes the window
    this->close();
}


void custominput::on_pushButton_3_clicked()
{
    // adds the current city selected to the trip log ui
    // and to the vector of cities to visit
    if(ui->comboBox_2->currentIndex() != 0)
    {
        QString city = ui->comboBox_2->currentText();

        ui->textBrowser->setText(ui->textBrowser->toPlainText() + city + "\nNext City: ");

        cities.push_back(city);

        ui->comboBox_2->removeItem(ui->comboBox_2->currentIndex());

        ui->pushButton->setEnabled(true);
    }

}

