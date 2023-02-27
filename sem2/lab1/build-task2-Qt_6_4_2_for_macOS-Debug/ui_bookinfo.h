/********************************************************************************
** Form generated from reading UI file 'bookinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKINFO_H
#define UI_BOOKINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_bookInfo
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *year;
    QLineEdit *lan;
    QLineEdit *author;
    QLineEdit *name;
    QLineEdit *id;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *date;
    QLabel *label_6;

    void setupUi(QDialog *bookInfo)
    {
        if (bookInfo->objectName().isEmpty())
            bookInfo->setObjectName("bookInfo");
        bookInfo->resize(303, 261);
        formLayoutWidget = new QWidget(bookInfo);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(39, 40, 211, 181));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        year = new QLineEdit(formLayoutWidget);
        year->setObjectName("year");
        year->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, year);

        lan = new QLineEdit(formLayoutWidget);
        lan->setObjectName("lan");
        lan->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, lan);

        author = new QLineEdit(formLayoutWidget);
        author->setObjectName("author");
        author->setReadOnly(true);

        formLayout->setWidget(2, QFormLayout::FieldRole, author);

        name = new QLineEdit(formLayoutWidget);
        name->setObjectName("name");
        name->setReadOnly(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, name);

        id = new QLineEdit(formLayoutWidget);
        id->setObjectName("id");
        id->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, id);

        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        date = new QLineEdit(formLayoutWidget);
        date->setObjectName("date");
        date->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, date);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);


        retranslateUi(bookInfo);

        QMetaObject::connectSlotsByName(bookInfo);
    } // setupUi

    void retranslateUi(QDialog *bookInfo)
    {
        bookInfo->setWindowTitle(QCoreApplication::translate("bookInfo", "\320\270\320\275\321\204\320\260", nullptr));
        label->setText(QCoreApplication::translate("bookInfo", "\320\232\320\276\320\264 \320\272\320\275\320\270\320\263\320\270:", nullptr));
        label_2->setText(QCoreApplication::translate("bookInfo", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265:", nullptr));
        label_3->setText(QCoreApplication::translate("bookInfo", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217 \320\260\320\262\321\202\320\276\321\200\320\260:", nullptr));
        label_4->setText(QCoreApplication::translate("bookInfo", "\320\257\320\267\321\213\320\272 \320\270\320\267\320\264\320\260\320\275\320\270\321\217:", nullptr));
        label_5->setText(QCoreApplication::translate("bookInfo", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217:", nullptr));
        label_6->setText(QCoreApplication::translate("bookInfo", "\320\224\320\260\321\202\320\260 \320\262\320\276\320\267\320\262\321\200\320\260\321\202\320\260:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookInfo: public Ui_bookInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINFO_H
