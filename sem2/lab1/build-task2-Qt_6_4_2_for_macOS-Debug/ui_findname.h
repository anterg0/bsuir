/********************************************************************************
** Form generated from reading UI file 'findname.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FINDNAME_H
#define UI_FINDNAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_findName
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *findName)
    {
        if (findName->objectName().isEmpty())
            findName->setObjectName("findName");
        findName->resize(400, 300);
        lineEdit = new QLineEdit(findName);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 130, 181, 21));
        label = new QLabel(findName);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 130, 58, 16));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton = new QPushButton(findName);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(140, 180, 100, 32));

        retranslateUi(findName);

        QMetaObject::connectSlotsByName(findName);
    } // setupUi

    void retranslateUi(QDialog *findName)
    {
        findName->setWindowTitle(QCoreApplication::translate("findName", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("findName", "\320\244\320\230\320\236:", nullptr));
        pushButton->setText(QCoreApplication::translate("findName", "\320\235\320\260\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class findName: public Ui_findName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FINDNAME_H
