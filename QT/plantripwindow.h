#ifndef PLANTRIPWINDOW_H
#define PLANTRIPWINDOW_H

#include <QMainWindow>

namespace Ui {
class planTripWindow;
}

class planTripWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit planTripWindow(QWidget *parent = nullptr);
    ~planTripWindow();

private:
    Ui::planTripWindow *ui;
};

#endif // PLANTRIPWINDOW_H
