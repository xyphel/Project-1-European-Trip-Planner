/********************************************************************************
** Form generated from reading UI file 'plantripwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLANTRIPWINDOW_H
#define UI_PLANTRIPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_planTripWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *planTripWindow)
    {
        if (planTripWindow->objectName().isEmpty())
            planTripWindow->setObjectName("planTripWindow");
        planTripWindow->resize(800, 600);
        centralwidget = new QWidget(planTripWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 151, 41));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 60, 401, 81));
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setEnabled(true);
        textBrowser->setGeometry(QRect(20, 130, 311, 121));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 260, 81, 23));
        planTripWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(planTripWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        planTripWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(planTripWindow);
        statusbar->setObjectName("statusbar");
        planTripWindow->setStatusBar(statusbar);

        retranslateUi(planTripWindow);

        QMetaObject::connectSlotsByName(planTripWindow);
    } // setupUi

    void retranslateUi(QMainWindow *planTripWindow)
    {
        planTripWindow->setWindowTitle(QCoreApplication::translate("planTripWindow", "Plan a trip", nullptr));
        label->setText(QCoreApplication::translate("planTripWindow", "<html><head/><body><p><span style=\" font-size:24pt;\">Plan a trip</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("planTripWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">Choose a plan from our trip options below</span></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("planTripWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt; font-weight:600;\">Berlin Trip Plan</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Starts off in Berlin</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Travels through 11 other European Cities</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">- Choose which food items"
                        " you would like in each city</p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("planTripWindow", "Start this plan", nullptr));
    } // retranslateUi

};

namespace Ui {
    class planTripWindow: public Ui_planTripWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLANTRIPWINDOW_H
