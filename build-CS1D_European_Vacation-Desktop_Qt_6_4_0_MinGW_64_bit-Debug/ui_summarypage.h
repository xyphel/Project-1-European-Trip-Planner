/********************************************************************************
** Form generated from reading UI file 'summarypage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUMMARYPAGE_H
#define UI_SUMMARYPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_summarypage
{
public:
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *summarypage)
    {
        if (summarypage->objectName().isEmpty())
            summarypage->setObjectName("summarypage");
        summarypage->resize(555, 488);
        label = new QLabel(summarypage);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 251, 51));
        label_2 = new QLabel(summarypage);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 151, 31));
        textBrowser = new QTextBrowser(summarypage);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 110, 256, 291));
        pushButton = new QPushButton(summarypage);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(470, 450, 75, 23));

        retranslateUi(summarypage);

        QMetaObject::connectSlotsByName(summarypage);
    } // setupUi

    void retranslateUi(QDialog *summarypage)
    {
        summarypage->setWindowTitle(QCoreApplication::translate("summarypage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("summarypage", "<html><head/><body><p><span style=\" font-size:22pt;\">Your trip is over :(</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("summarypage", "<html><head/><body><p><span style=\" font-size:12pt;\">Here is your receipt</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("summarypage", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class summarypage: public Ui_summarypage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUMMARYPAGE_H
