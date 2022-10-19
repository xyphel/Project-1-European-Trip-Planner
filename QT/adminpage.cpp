#include "adminpage.h"
#include "ui_adminpage.h"


adminpage::adminpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::adminpage)
{
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);
    SetDataBase(); // sets database

    // sets models of the database to be displayed
    model = new QSqlQueryModel();
    model2 = new QSqlQueryModel();
    DisplayData(model, model2); // displays the model

    ui->comboBox->addItem("Select Food item");
    ui->comboBox_2->addItem("Select City");

    // opens database and sets the values of the combobox to entries from the database
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
    // uses the models passed in and sets the data from the database to them
    // to be displayed
    ConnOpen();
    QSqlQuery* qry = new QSqlQuery(db);

    qry->prepare("select * from distances ORDER BY Starting_City ASC");
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
    // first comboBox holds all the food items to be updated in the database
    QString name = "";
    QString cost = "";

    // sets the name in the comboBox to a lineEdit for ui purposes
    if(index > 0)
    {
        name = ui->comboBox->itemText(index);

        ui->lineEdit->setText(name);

        ConnOpen();
        QSqlQuery q;
        q.exec("SELECT cost FROM foods WHERE Food = \'" + name + "\'");

        // gets cost of the selected food item
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
    // updates the cost of the selected food item
    if(ui->comboBox->currentIndex() > 0)
    {
        QString foodName = "";
        QString foodPrice = "";

        foodName = ui->lineEdit->text();
        foodPrice = ui->lineEdit_2->text();

        // checks the price the user inputted to see if it's a valid input
        if(NumCheck(foodPrice))
        {
            // if valid it updates the database
            ConnOpen();
            QSqlQuery q;
            QString sql = "update foods set cost ='"+foodPrice+"' where Food = '"+foodName+"'";
            qDebug() << sql;
            q.exec(sql);
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
    // deletes the current food item from the database
    if(ui->comboBox->currentIndex() > 0)
    {
        QString foodName = "";

        foodName = ui->lineEdit->text();

        ConnOpen();
        QSqlQuery q;
        QString sql = "delete from foods where Food = '"+foodName+"'";
        qDebug() << sql;
        q.exec(sql);
        ConnClose();

        DisplayData(model, model2);

        ui->comboBox->removeItem(ui->comboBox->currentIndex());

        QMessageBox::information(this, "Success", "Deleted entry.");

    }
}


void adminpage::on_comboBox_2_currentIndexChanged(int index)
{
    // disables the lineEdits and buttons unless a food item is
    // selected
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
    // takes an input from user and adds it to the database
    QString foodName = "";
    QString foodPrice = "";
    QString cityName = "";

    // reads input
    foodName = ui->lineEdit_3->text();
    foodPrice = ui->lineEdit_4->text();

    cityName = ui->comboBox_2->currentText();

    // checks if price is a valid input
    if(NumCheck(foodPrice))
    {
        // if valid adds the food to the database
        ConnOpen();
        QSqlQuery q;
        QString sql = "insert into foods (City, Food, Cost) values (\'" + cityName +"\', \'" + foodName +"\' , \'" + foodPrice + "\')";
        qDebug() << sql;
        q.exec(sql);
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
    // opens file directory and accepts a text file to be open
    QString filePath = QFileDialog::getOpenFileName(this,"European Trip Planner - Open File",QDir::homePath(),"Text Files (*.txt)");

    QFile file(filePath);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream iFile(&file);

        AddFromFile(iFile);

        file.close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Failed to open file.");
    }
}

void adminpage::AddFromFile(QTextStream& iFile)
{
    // reads the text file line from line and inserts the data into the database
    QStringList fields;
    QString line;

    QSqlQuery q;
    QString sql = "";
    bool food = false;
    QString cityName;

    ConnOpen();

    while(!iFile.atEnd())
    {
        // checks first line to see if it's a food item or city
        line = iFile.readLine();
        if(line != "New Food" && !food)
        {
            // if city split the line at each space and insert the data into the database
            fields.append(line.split(' '));
            sql = "insert into distances (Starting_City, Ending_City, Distance) values (\'" + fields.at(0) + "\', \'" + fields.at(1) + "\', \'" + fields.at(2) + "\')";
            q.exec(sql);
            fields.clear();
        }
        else
        {
            // if food read each line and split at the $ sign and add the data into the database
            food = true;

            if(line == "New Food")
            {
                iFile.readLine();
                line = iFile.readLine();
                cityName = line;
            }
            else if(line == "")
            {
                iFile.readLine();
            }
            else
            {
                fields.append(line.split('$'));
                sql = "insert into foods (City, Food, Cost) values (\'" + cityName + "\', \'" + fields.at(0) + "\', \'" + fields.at(1) + "\')";
                q.exec(sql);
                fields.clear();
            }

        }

    }

    ConnClose();

    DisplayData(model, model2);

    ui->comboBox->clear();
    ui->comboBox_2->clear();

    ui->comboBox->addItem("Select Food item");
    ui->comboBox_2->addItem("Select City");

    // updates the comboBoxes to add the new data inserted
    ConnOpen();
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

