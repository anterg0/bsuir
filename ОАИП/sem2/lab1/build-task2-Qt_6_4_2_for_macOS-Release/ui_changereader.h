/********************************************************************************
** Form generated from reading UI file 'changereader.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGEREADER_H
#define UI_CHANGEREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_changeReader
{
public:
    QLineEdit *id;
    QLineEdit *name;
    QLineEdit *phone;
    QLineEdit *address;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *addButton;

    void setupUi(QDialog *changeReader)
    {
        if (changeReader->objectName().isEmpty())
            changeReader->setObjectName("changeReader");
        changeReader->resize(400, 300);
        changeReader->setMinimumSize(QSize(400, 300));
        changeReader->setMaximumSize(QSize(400, 300));
        id = new QLineEdit(changeReader);
        id->setObjectName("id");
        id->setGeometry(QRect(30, 40, 113, 21));
        name = new QLineEdit(changeReader);
        name->setObjectName("name");
        name->setGeometry(QRect(30, 80, 113, 21));
        phone = new QLineEdit(changeReader);
        phone->setObjectName("phone");
        phone->setGeometry(QRect(30, 120, 113, 21));
        address = new QLineEdit(changeReader);
        address->setObjectName("address");
        address->setGeometry(QRect(30, 160, 113, 21));
        pushButton = new QPushButton(changeReader);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(30, 200, 100, 32));
        label = new QLabel(changeReader);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 40, 161, 16));
        addButton = new QPushButton(changeReader);
        addButton->setObjectName("addButton");
        addButton->setEnabled(false);
        addButton->setGeometry(QRect(130, 200, 100, 32));

        retranslateUi(changeReader);

        QMetaObject::connectSlotsByName(changeReader);
    } // setupUi

    void retranslateUi(QDialog *changeReader)
    {
        changeReader->setWindowTitle(QCoreApplication::translate("changeReader", "\320\277\320\260\321\201\320\277\320\276\321\200\321\202\320\275\321\213\320\271 \321\201\321\202\320\276\320\273", nullptr));
        id->setPlaceholderText(QCoreApplication::translate("changeReader", "ID", nullptr));
        name->setPlaceholderText(QCoreApplication::translate("changeReader", "\320\244\320\230\320\236", nullptr));
        phone->setPlaceholderText(QCoreApplication::translate("changeReader", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\265\320\273\320\265\321\204\320\276\320\275\320\260", nullptr));
        address->setPlaceholderText(QCoreApplication::translate("changeReader", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        pushButton->setText(QCoreApplication::translate("changeReader", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label->setText(QString());
        addButton->setText(QCoreApplication::translate("changeReader", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class changeReader: public Ui_changeReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGEREADER_H
