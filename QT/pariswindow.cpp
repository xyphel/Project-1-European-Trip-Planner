#include "pariswindow.h"
#include "ui_pariswindow.h"

pariswindow::pariswindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::pariswindow)
{
    ui->setupUi(this);
}

pariswindow::~pariswindow()
{
    delete ui;
}
