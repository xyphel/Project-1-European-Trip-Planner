#ifndef SUMMARYPAGE_H
#define SUMMARYPAGE_H

#include <QDialog>
#include "travelplan.h"

//struct Receipt{
//    std::vector<double> costOfItems;
//    std::vector<QString> itemsBought;
//    double cost;
//    int distanceTraveled;
//};

namespace Ui {
class summarypage;
}

class summarypage : public QDialog
{
    Q_OBJECT

public:
    explicit summarypage(QWidget *parent = nullptr);
    void GetData(TravelPlan::Receipt currentReceipt);
    ~summarypage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::summarypage *ui;
};

#endif // SUMMARYPAGE_H
