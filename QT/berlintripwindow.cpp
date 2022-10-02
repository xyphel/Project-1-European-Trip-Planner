#include "berlintripwindow.h"
#include "ui_berlintripwindow.h"

berlinTripWindow::berlinTripWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::berlinTripWindow)
{
    ui->setupUi(this);
    index = 0;
}

berlinTripWindow::~berlinTripWindow()
{
    delete ui;
}

void berlinTripWindow::on_pushButton_clicked()
{
    index = ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(index + 1);
}

