#include "plantripwindow.h"
#include "ui_planTripWindow.h"

planTripWindow::planTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::planTripWindow)
{
    // sets up ui
    ui->setupUi(this);

    // creates loginwindow
    loginWindow = new loginwindow();

    // sets database
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
    // if plan clicked creates plan window
    berlinPlanWindow = new berlinTripWindow(this);

    // show window
    berlinPlanWindow->show();
    this->hide();
}

void planTripWindow::on_actionSign_in_triggered()
{
    // show login window
    loginWindow->show();

}


void planTripWindow::on_pushButton_2_clicked()
{
    // if plan clicked creates plan window
    // checks if new cities were added
    bool dataInserted = CheckCitiesAdded();

    // if inserted create and show window
    if(dataInserted)
    {
        newBerlinPlanWindow = new newberlinwindow(this);

        newBerlinPlanWindow->show();
        this->hide();
    }
    else
    {
        // if not open login window
        QMessageBox::warning(this, "Error", "Data not inserted.");
        loginWindow->show();
    }

}


void planTripWindow::on_pushButton_3_clicked()
{
    // if plan clicked creates input window
    parisInput = new parisinput(this);

    // show window
    parisInput->show();

}

bool planTripWindow::CheckCitiesAdded()
{
    // checks if the new data was inserted
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
    // if plan clicked creates input window
    customInput = new custominput();

    // show window
    customInput->show();
    this->close();
}


void planTripWindow::on_pushButton_5_clicked()
{
    // refreshes database
    SetDataBase();
}

