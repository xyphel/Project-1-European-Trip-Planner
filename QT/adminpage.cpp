#include "adminpage.h"
#include "ui_adminpage.h"

adminpage::adminpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQueryModel* model2 = new QSqlQueryModel();
    DisplayData(model, model2);
}

adminpage::~adminpage()
{
    delete ui;
}

void adminpage::DisplayData(QSqlQueryModel* model, QSqlQueryModel* model2)
{
    SetDataBase();
    ConnOpen();
    QSqlQuery* qry = new QSqlQuery(db);

    qry->prepare("select * from distances");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    qry->prepare("select * from foods");
    qry->exec();

    model2->setQuery(*qry);

    ui->tableView_2->setModel(model2);

    delete qry;

    ConnClose();
}
