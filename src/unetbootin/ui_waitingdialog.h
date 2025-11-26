/********************************************************************************
** Form generated from reading UI file 'waitingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGDIALOG_H
#define UI_WAITINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WaitingDialog
{
public:
    QLabel *infolabel;

    void setupUi(QDialog *WaitingDialog)
    {
        if (WaitingDialog->objectName().isEmpty())
            WaitingDialog->setObjectName(QString::fromUtf8("WaitingDialog"));
        WaitingDialog->resize(500, 40);
        infolabel = new QLabel(WaitingDialog);
        infolabel->setObjectName(QString::fromUtf8("infolabel"));
        infolabel->setGeometry(QRect(10, 10, 481, 20));

        retranslateUi(WaitingDialog);

        QMetaObject::connectSlotsByName(WaitingDialog);
    } // setupUi

    void retranslateUi(QDialog *WaitingDialog)
    {
        WaitingDialog->setWindowTitle(QCoreApplication::translate("WaitingDialog", "Dialog", nullptr));
        infolabel->setText(QCoreApplication::translate("WaitingDialog", "Installation on FAT32 format hard disk will take a while. Please wait...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaitingDialog: public Ui_WaitingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGDIALOG_H
