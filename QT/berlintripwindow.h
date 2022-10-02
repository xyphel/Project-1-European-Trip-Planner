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

private slots:
    void on_pushButton_clicked();

private:
    Ui::berlinTripWindow *ui;
    int index;
};

#endif // BERLINTRIPWINDOW_H
