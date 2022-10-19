#include "mainwindow.h"
#include "travelplan.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // declares application
    MainWindow w; // declares main window
    w.show(); // shows main window
    return a.exec(); // runs application
}
