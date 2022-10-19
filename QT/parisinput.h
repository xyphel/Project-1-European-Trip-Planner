#ifndef PARISINPUT_H
#define PARISINPUT_H

#include <QDialog>
#include <QMessageBox>
#include "pariswindow.h"

namespace Ui {
class parisinput;
}

/// parisInput class
///
/// Gets the number of cities the user wants to visit
/// in the Paris plan
class parisinput : public QDialog
{
    Q_OBJECT

public:
    explicit parisinput(QWidget *parent = nullptr);
    ~parisinput();

    /// Checks input
    ///
    /// This method takes a num string and checks to see if the input is a number
    /// @param num String num to check if a valid number
    /// @returns valid or not
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

private slots:
    void on_buttonBox_accepted();

private:
    Ui::parisinput *ui;
    pariswindow *parisWindow;
    QWidget *tripWindow;
};

#endif // PARISINPUT_H
