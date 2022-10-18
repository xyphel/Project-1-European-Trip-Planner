#ifndef PARISINPUT_H
#define PARISINPUT_H

#include <QDialog>
#include <QMessageBox>
#include "pariswindow.h"

namespace Ui {
class parisinput;
}

class parisinput : public QDialog
{
    Q_OBJECT

public:
    explicit parisinput(QWidget *parent = nullptr);
    ~parisinput();

    bool NumCheck(QString num)
    {
        bool ok;

        num.toInt(&ok);
        if(ok && num.toInt() < 14 && num.toInt() > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void SetCheckCities(bool b)
    {
        checkCities = b;
    }

private slots:
    void on_buttonBox_accepted();

private:
    Ui::parisinput *ui;
    pariswindow *parisWindow;
    bool checkCities;
    QWidget *tripWindow;
};

#endif // PARISINPUT_H
