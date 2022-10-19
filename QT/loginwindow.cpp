#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>

loginwindow::loginwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::loginwindow)
{
    ui->setupUi(this);
    setWindowTitle("Administrator Login");
}

loginwindow::~loginwindow()
{
    delete ui;
    delete admin;
}

void loginwindow::on_loginButton_clicked()
{
    // checks if user name or password is correct
    if(ADMINISTRATOR_USERNAME == ui->usernameTextEdit->toPlainText() && ADMINISTRATOR_PASSWORD == ui->passwordTextEdit->toPlainText())
    {
        QMessageBox::information(this, "Login", "Login Successful!");
        emit loginSuccessful();
        close();

        // if correct open the admin page
        admin = new adminpage();

        admin->show();
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or Password was incorrect.");
    }
    ui->usernameTextEdit->setPlainText("");
    ui->passwordTextEdit->setPlainText("");
}
