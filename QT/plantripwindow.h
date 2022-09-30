#ifndef PLANTRIPWINDOW_H
#define PLANTRIPWINDOW_H

#include <QMainWindow>
#include "berlintripwindow.h"

namespace Ui {
class planTripWindow;
}

class planTripWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit planTripWindow(QWidget *parent = nullptr);
    ~planTripWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::planTripWindow *ui;
    berlinTripWindow *berlinPlanWindow;
};

#endif // PLANTRIPWINDOW_H
