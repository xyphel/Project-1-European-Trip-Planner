#include "adminpage.h"
#include "ui_adminpage.h"

adminpage::adminpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    SetDataBase();

    model = new QSqlQueryModel();
    model2 = new QSqlQueryModel();
    DisplayData(model, model2);

    ui->comboBox->addItem("Select Food item");
    ui->comboBox_2->addItem("Select City");

    ConnOpen();
    QSqlQuery q;
    q.exec("SELECT * FROM foods ORDER BY City ASC"); // SQL statement: means to output all values in the table
    QString name = "";
    while(q.next())
    {
        ui->comboBox->addItem(q.value(1).toString());

        if(name != q.value(0).toString())
        {
            name = q.value(0).toString();
            ui->comboBox_2->addItem(name);
        }

     }

    ConnClose();
}

adminpage::~adminpage()
{
    delete ui;
    delete model;
    delete model2;
}

void adminpage::DisplayData(QSqlQueryModel* model, QSqlQueryModel* model2)
{
    ConnOpen();
    QSqlQuery* qry = new QSqlQuery(db);

    qry->prepare("select * from distances");
    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);

    qry->prepare("select * from foods ORDER BY City ASC");
    qry->exec();

    model2->setQuery(*qry);

    ui->tableView_2->setModel(model2);

    delete qry;

    ConnClose();
}

void adminpage::on_comboBox_currentIndexChanged(int index)
{
    QString name = "";
    QString cost = "";

    if(index > 0)
    {
        name = ui->comboBox->itemText(index);

        ui->lineEdit->setText(name);

        ConnOpen();
        QSqlQuery q;
        q.exec("SELECT cost FROM foods WHERE Food = \'" + name + "\'"); // SQL statement: means to output all values in the table

        while(q.next())
        {
            cost = q.value(0).toString();
        }

        ConnClose();
    }

    ui->lineEdit->setText(name);
    ui->lineEdit_2->setText(cost);
}


void adminpage::on_pushButton_clicked()
{
    if(ui->comboBox->currentIndex() > 0)
    {
        QString foodName = "";
        QString foodPrice = "";

        foodName = ui->lineEdit->text();
        foodPrice = ui->lineEdit_2->text();

        if(NumCheck(foodPrice))
        {
            ConnOpen();
            QSqlQuery q;
            QString sql = "update foods set cost ='"+foodPrice+"' where Food = '"+foodName+"'";
            qDebug() << sql;
            q.exec(sql); // SQL statement: means to output all values in the table
            ConnClose();

            DisplayData(model, model2);

            QMessageBox::information(this, "Success", "Updated entry.");
        }
        else
        {
            QMessageBox::warning(this, "Error", "Invalid input.");
        }

    }
}


void adminpage::on_pushButton_2_clicked()
{
    if(ui->comboBox->currentIndex() > 0)
    {
        QString foodName = "";

        foodName = ui->lineEdit->text();

        ConnOpen();
        QSqlQuery q;
        QString sql = "delete from foods where Food = '"+foodName+"'";
        qDebug() << sql;
        q.exec(sql); // SQL statement: means to output all values in the table
        ConnClose();

        DisplayData(model, model2);

        ui->comboBox->removeItem(ui->comboBox->currentIndex());

        QMessageBox::information(this, "Success", "Deleted entry.");

    }
}


void adminpage::on_comboBox_2_currentIndexChanged(int index)
{
    if(ui->comboBox_2->currentIndex() == 0)
    {
        ui->lineEdit_3->setEnabled(false);
        ui->lineEdit_4->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
    }
    else
    {
        ui->lineEdit_3->setEnabled(true);
        ui->lineEdit_4->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
    }
}


void adminpage::on_pushButton_3_clicked()
{
    QString foodName = "";
    QString foodPrice = "";
    QString cityName = "";

    foodName = ui->lineEdit_3->text();
    foodPrice = ui->lineEdit_4->text();

    cityName = ui->comboBox_2->currentText();

    if(NumCheck(foodPrice))
    {
        ConnOpen();
        QSqlQuery q;
        QString sql = "insert into foods (City, Food, Cost) values (\'" + cityName +"\', \'" + foodName +"\' , \'" + foodPrice + "\')";
        qDebug() << sql;
        q.exec(sql); // SQL statement: means to output all values in the table
        ConnClose();

        DisplayData(model, model2);

        ui->comboBox->addItem(foodName);

        QMessageBox::information(this, "Success", "Added entry.");
    }
    else
    {
        QMessageBox::warning(this, "Error", "Invalid input.");
    }

    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");

}


void adminpage::on_pushButton_4_clicked()
{

}

