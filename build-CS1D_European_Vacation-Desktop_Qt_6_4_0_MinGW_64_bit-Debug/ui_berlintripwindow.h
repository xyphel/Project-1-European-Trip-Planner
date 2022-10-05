/********************************************************************************
** Form generated from reading UI file 'berlintripwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BERLINTRIPWINDOW_H
#define UI_BERLINTRIPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_berlinTripWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowser;
    QComboBox *comboBox;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *berlinTripWindow)
    {
        if (berlinTripWindow->objectName().isEmpty())
            berlinTripWindow->setObjectName("berlinTripWindow");
        berlinTripWindow->resize(800, 600);
        centralwidget = new QWidget(berlinTripWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(720, 520, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 151, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 271, 51));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 50, 811, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 110, 271, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 160, 101, 51));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 210, 291, 251));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(310, 210, 191, 22));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(310, 180, 191, 21));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(490, 430, 75, 23));
        berlinTripWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(berlinTripWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        berlinTripWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(berlinTripWindow);
        statusbar->setObjectName("statusbar");
        berlinTripWindow->setStatusBar(statusbar);

        retranslateUi(berlinTripWindow);

        QMetaObject::connectSlotsByName(berlinTripWindow);
    } // setupUi

    void retranslateUi(QMainWindow *berlinTripWindow)
    {
        berlinTripWindow->setWindowTitle(QCoreApplication::translate("berlinTripWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("berlinTripWindow", "Next City", nullptr));
        label->setText(QCoreApplication::translate("berlinTripWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">City Name</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("berlinTripWindow", "<html><head/><body><p><span style=\" font-size:18pt;\">Welcome to Berlin</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("berlinTripWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Select below to purchase your meals</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("berlinTripWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600;\">Menu</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("berlinTripWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Select what to buy</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("berlinTripWindow", "Purchase", nullptr));
    } // retranslateUi

};

namespace Ui {
    class berlinTripWindow: public Ui_berlinTripWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BERLINTRIPWINDOW_H
