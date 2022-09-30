#include "plantripwindow.h"
#include "ui_planTripWindow.h"

planTripWindow::planTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::planTripWindow)
{
    ui->setupUi(this);
}

planTripWindow::~planTripWindow()
{
    delete ui;
}

void planTripWindow::on_pushButton_clicked()
{
    berlinPlanWindow = new berlinTripWindow(this);

    berlinPlanWindow->show();
    this->hide();
}
