#include "plantripwindow.h"
#include "ui_planTripWindow.h"

planTripWindow::planTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::planTripWindow)
{
    ui->setupUi(this);
    loginWindow = new loginwindow();

    SetDataBase();
}

planTripWindow::~planTripWindow()
{
    delete ui;
    delete loginWindow;
    delete berlinPlanWindow;
    delete parisInput;
    delete customInput;
}

void planTripWindow::on_pushButton_clicked()
{
    berlinPlanWindow = new berlinTripWindow(this);

    berlinPlanWindow->show();
    this->hide();
}

void planTripWindow::on_actionSign_in_triggered()
{
    loginWindow->show();

}


void planTripWindow::on_pushButton_2_clicked()
{
    bool dataInserted = CheckCitiesAdded();

    if(dataInserted)
    {
        newBerlinPlanWindow = new newberlinwindow(this);

        newBerlinPlanWindow->show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Data not inserted.");
        loginWindow->show();
    }

}


void planTripWindow::on_pushButton_3_clicked()
{
    parisInput = new parisinput(this);

    parisInput->SetCheckCities(CheckCitiesAdded());
    parisInput->show();

}

bool planTripWindow::CheckCitiesAdded()
{
    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT DISTINCT Starting_City FROM Distances WHERE Starting_City = 'Vienna' OR Starting_City = 'Stockholm'"); // SQL statement: means to output all values in the table
    bool dataInserted = false;
    while(q.next())
    {
        if(!(q.value(0).isNull()))
        {
            dataInserted = true;
        }
        else
        {
            dataInserted = false;
        }

    }

    ConnClose();

    return dataInserted;
}


void planTripWindow::on_pushButton_4_clicked()
{
    customInput = new custominput();
    customInput->show();
    this->close();
}

