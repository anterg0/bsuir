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
    QLineEdit *publisher;
    QLineEdit *author;
    QLineEdit *name;
    QLineEdit *id;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *pages;
    QLabel *label_6;

    void setupUi(QDialog *bookInfo)
    {
        if (bookInfo->objectName().isEmpty())
            bookInfo->setObjectName("bookInfo");
        bookInfo->resize(400, 300);
        formLayoutWidget = new QWidget(bookInfo);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(50, 40, 291, 211));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        year = new QLineEdit(formLayoutWidget);
        year->setObjectName("year");
        year->setReadOnly(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, year);

        publisher = new QLineEdit(formLayoutWidget);
        publisher->setObjectName("publisher");
        publisher->setReadOnly(true);

        formLayout->setWidget(3, QFormLayout::FieldRole, publisher);

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

        pages = new QLineEdit(formLayoutWidget);
        pages->setObjectName("pages");
        pages->setReadOnly(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, pages);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);


        retranslateUi(bookInfo);

        QMetaObject::connectSlotsByName(bookInfo);
    } // setupUi

    void retranslateUi(QDialog *bookInfo)
    {
        bookInfo->setWindowTitle(QCoreApplication::translate("bookInfo", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("bookInfo", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("bookInfo", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("bookInfo", "Author:", nullptr));
        label_4->setText(QCoreApplication::translate("bookInfo", "Publisher:", nullptr));
        label_5->setText(QCoreApplication::translate("bookInfo", "Year:", nullptr));
        label_6->setText(QCoreApplication::translate("bookInfo", "Page Amount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class bookInfo: public Ui_bookInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKINFO_H
