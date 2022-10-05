#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QDialog>

namespace Ui {
class summarypage;
}

class summarypage : public QDialog
{
    Q_OBJECT

public:
    explicit summarypage(QWidget *parent = nullptr, double cost = 0);
    ~summarypage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::summarypage *ui;
};

#endif // SUMMARYPAGE_H
