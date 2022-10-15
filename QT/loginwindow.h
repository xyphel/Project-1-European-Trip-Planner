#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include <QString>
#include "adminpage.h"


const QString ADMINISTRATOR_USERNAME = "Admin";
const QString ADMINISTRATOR_PASSWORD = "Password";

namespace Ui {
class loginwindow;
}

class loginwindow : public QWidget
{
    Q_OBJECT

public:
    explicit loginwindow(QWidget *parent = 0);
    ~loginwindow();

signals:
    void loginSuccessful();

private slots:
    void on_loginButton_clicked();

private:
    Ui::loginwindow *ui;
    adminpage *admin;
};

#endif // LOGINWINDOW_H
