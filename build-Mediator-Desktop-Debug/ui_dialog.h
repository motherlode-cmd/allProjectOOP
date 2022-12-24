/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(90, 30, 231, 81));
        lineEdit = new QLineEdit(Dialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(130, 120, 113, 25));
        comboBox_2 = new QComboBox(Dialog);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(130, 160, 111, 25));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Dialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\204\320\260\320\271\320\273 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("Dialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\321\213\320\262\320\276\320\264 \320\262 \320\272\320\276\320\275\321\201\320\276\320\273\321\214", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("Dialog", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\262\321\213\320\262\320\276\320\264 \320\262 \320\272\320\276\320\275\321\201\320\276\320\273\321\214", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
