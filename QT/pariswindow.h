#ifndef PARISWINDOW_H
#define PARISWINDOW_H

#include <QMainWindow>

namespace Ui {
class pariswindow;
}

class pariswindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit pariswindow(QWidget *parent = nullptr);
    ~pariswindow();

private:
    Ui::pariswindow *ui;
};

#endif // PARISWINDOW_H
