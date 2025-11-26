/********************************************************************************
** Form generated from reading UI file 'dataimageconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAIMAGECONFIGDIALOG_H
#define UI_DATAIMAGECONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSplitter>

QT_BEGIN_NAMESPACE

class Ui_DataImageConfigDialog
{
public:
    QPushButton *pushButton;
    QLabel *label_2;
    QSplitter *splitter;
    QLabel *label;
    QRadioButton *radioButton1;
    QRadioButton *radioButton2;
    QRadioButton *radioButton3;

    void setupUi(QDialog *DataImageConfigDialog)
    {
        if (DataImageConfigDialog->objectName().isEmpty())
            DataImageConfigDialog->setObjectName(QString::fromUtf8("DataImageConfigDialog"));
        DataImageConfigDialog->resize(521, 137);
        pushButton = new QPushButton(DataImageConfigDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(400, 100, 99, 27));
        label_2 = new QLabel(DataImageConfigDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(11, 11, 498, 17));
        splitter = new QSplitter(DataImageConfigDialog);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(12, 38, 179, 83));
        splitter->setOrientation(Qt::Vertical);
        label = new QLabel(splitter);
        label->setObjectName(QString::fromUtf8("label"));
        splitter->addWidget(label);
        radioButton1 = new QRadioButton(splitter);
        radioButton1->setObjectName(QString::fromUtf8("radioButton1"));
        splitter->addWidget(radioButton1);
        radioButton2 = new QRadioButton(splitter);
        radioButton2->setObjectName(QString::fromUtf8("radioButton2"));
        radioButton2->setChecked(false);
        splitter->addWidget(radioButton2);
        radioButton3 = new QRadioButton(splitter);
        radioButton3->setObjectName(QString::fromUtf8("radioButton3"));
        radioButton3->setCheckable(true);
        radioButton3->setChecked(true);
        splitter->addWidget(radioButton3);

        retranslateUi(DataImageConfigDialog);

        QMetaObject::connectSlotsByName(DataImageConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *DataImageConfigDialog)
    {
        DataImageConfigDialog->setWindowTitle(QCoreApplication::translate("DataImageConfigDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("DataImageConfigDialog", "Ok", nullptr));
        label_2->setText(QCoreApplication::translate("DataImageConfigDialog", "A larger system size is recommended because you can install more apps.", nullptr));
        label->setText(QCoreApplication::translate("DataImageConfigDialog", "Choose system size:", nullptr));
        radioButton1->setText(QCoreApplication::translate("DataImageConfigDialog", "8GB", nullptr));
        radioButton2->setText(QCoreApplication::translate("DataImageConfigDialog", "16GB", nullptr));
        radioButton3->setText(QCoreApplication::translate("DataImageConfigDialog", "32GB(Recommended)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataImageConfigDialog: public Ui_DataImageConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAIMAGECONFIGDIALOG_H
