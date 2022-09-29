#include "plantripwindow.h"
#include "ui_plantripwindow.h"

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
