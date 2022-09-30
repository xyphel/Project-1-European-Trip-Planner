#include "berlintripwindow.h"
#include "ui_berlinTripWindow.h"

berlinTripWindow::berlinTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::berlinTripWindow)
{
    ui->setupUi(this);
}

berlinTripWindow::~berlinTripWindow()
{
    delete ui;
}
