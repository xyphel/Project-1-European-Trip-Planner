#ifndef BERLINTRIPWINDOW_H
#define BERLINTRIPWINDOW_H

#include <QMainWindow>

namespace Ui {
class berlinTripWindow;
}

class berlinTripWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit berlinTripWindow(QWidget *parent = nullptr);
    ~berlinTripWindow();

private:
    Ui::berlinTripWindow *ui;
};

#endif // BERLINTRIPWINDOW_H
