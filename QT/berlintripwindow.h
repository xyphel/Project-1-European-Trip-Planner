#ifndef BERLINTRIPWINDOW_H
#define BERLINTRIPWINDOW_H

#include <QMainWindow>
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QVector>

namespace Ui {
class berlinTripWindow;
}

class berlinTripWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit berlinTripWindow(QWidget *parent = nullptr);
    void FindClosestCity(const QString& city, std::vector<QString>& cities);
    bool CheckIfCityWasVisited(const QString& CITY, std::vector<QString>& visitedCities);
    ~berlinTripWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::berlinTripWindow *ui;
    int index;
    double cost;
    QString cityName;
    std::vector<QString> visitedCities;
};

#endif // BERLINTRIPWINDOW_H
