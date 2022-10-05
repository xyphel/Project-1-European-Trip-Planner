#include "berlintripwindow.h"
#include "ui_berlintripwindow.h"
#include <QDebug>

bool Compare(const QString& str1, const QString& str2);

berlinTripWindow::berlinTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::berlinTripWindow)
{
    ui->setupUi(this);
    index = 0;
    cost = 0;
    cityName = "Berlin";
    QFont font = ui->label->font();
    font.setBold(true);
    font.setPointSize(15);
    ui->label->setFont(font);
    font.setBold(false);
    font.setPointSize(18);
    ui->label_2->setFont(font);
    ui->label_2->setText("Welcome to " + cityName);
    ui->label->setText(cityName);

    QDir dir("../GitHub/Project-1-European-Trip-Planner/data/Cities.sqlite3");
    QString path = dir.absolutePath();
    qInfo() << path;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    // displays first city
    db.open();

    QSqlQuery q;
    q.exec("SELECT food, Cost FROM foods WHERE City = 'Berlin'");
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
    db.close();

    visitedCities.push_back(cityName);
    FindClosestCity(cityName, visitedCities);

}

berlinTripWindow::~berlinTripWindow()
{
    delete ui;
}



void berlinTripWindow::on_pushButton_2_clicked()
{
    db.open();
    QString string = "";
    QString s = "";
    QSqlQuery q;
    s = ui->comboBox->currentText();
    string = "SELECT cost FROM foods WHERE food = \'" + s + "\'";
    q.exec(string);
    while(q.next())
    {
        s = q.value(0).toString();
    }

    cost += s.toDouble();
    qInfo() << cost;

    db.close();
}

void berlinTripWindow::on_pushButton_clicked()
{
    if(index != 9)
    {
        ui->comboBox->clear();
        index++;
        ui->comboBox->clear();
        db.open();
        QSqlQuery q;

        qInfo() << visitedCities[index];

        cityName = visitedCities[index];

        ui->label->setText(cityName);
        ui->label_2->setText("Welcome to " + cityName);

        q.exec("SELECT food, Cost FROM foods WHERE City = \'" + cityName + "\'");
        QString data = "";
        QString dataCombo = "";
        while(q.next())
        {
            dataCombo = q.value(0).toString();
            ui->comboBox->addItem(q.value(0).toString());
            data += q.value(0).toString() + ": $" + q.value(1).toString() + "\n";

        }
        ui->textBrowser->setText(data);
        db.close();
    }
    else
    {
        this->hide();
        summaryWindow = new summarypage(this, cost);

        summaryWindow->show();
    }

}
void berlinTripWindow::FindClosestCity(const QString& city, std::vector<QString> &cities)
{
    if(cities.size() != 10)
    {
        db.open();
        std::list<QString> End;
        QSqlQuery q;
        QString string = "SELECT Ending_City FROM Distances WHERE Starting_City = \'" + city + "\' ORDER BY Distance ASC";
        q.exec(string);

        while(q.next())
        {
            End.push_back(q.value(0).toString());
        }

        for(; !CheckIfCityWasVisited(End.front(), cities); End.pop_front());

        cities.push_back(End.front());

        FindClosestCity(End.front(), cities);
    }

    db.close();
}

bool berlinTripWindow::CheckIfCityWasVisited(const QString& CITY, std::vector<QString>& visitedCities)
{
    bool notVisitedYet = true;

    for(unsigned int i = 0; i < visitedCities.size(); i++)
    {
        if(Compare(CITY, visitedCities[i]))
            notVisitedYet = false;
    }
    return notVisitedYet;
}

bool Compare(const QString& str1, const QString& str2)
{
    // returns true if they are equal
    if(str1.size() != str2.size())
        return false;

    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] != str2[i])
            return false;
    }
    return true;
}

