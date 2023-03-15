/********************************************************************************
** Form generated from reading UI file 'insertdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTDIALOG_H
#define UI_INSERTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insertDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *bookID;
    QLineEdit *bookName;
    QLineEdit *bookAuthor;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_7;
    QLineEdit *bookPublisher;
    QLineEdit *bookYear;
    QLabel *label_6;
    QLineEdit *bookPageAmount;

    void setupUi(QDialog *insertDialog)
    {
        if (insertDialog->objectName().isEmpty())
            insertDialog->setObjectName("insertDialog");
        insertDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(insertDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(insertDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 371, 235));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        bookID = new QLineEdit(formLayoutWidget);
        bookID->setObjectName("bookID");

        formLayout->setWidget(1, QFormLayout::FieldRole, bookID);

        bookName = new QLineEdit(formLayoutWidget);
        bookName->setObjectName("bookName");

        formLayout->setWidget(2, QFormLayout::FieldRole, bookName);

        bookAuthor = new QLineEdit(formLayoutWidget);
        bookAuthor->setObjectName("bookAuthor");

        formLayout->setWidget(3, QFormLayout::FieldRole, bookAuthor);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        lineEdit = new QLineEdit(formLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_7);

        bookPublisher = new QLineEdit(formLayoutWidget);
        bookPublisher->setObjectName("bookPublisher");

        formLayout->setWidget(4, QFormLayout::FieldRole, bookPublisher);

        bookYear = new QLineEdit(formLayoutWidget);
        bookYear->setObjectName("bookYear");

        formLayout->setWidget(5, QFormLayout::FieldRole, bookYear);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        bookPageAmount = new QLineEdit(formLayoutWidget);
        bookPageAmount->setObjectName("bookPageAmount");

        formLayout->setWidget(6, QFormLayout::FieldRole, bookPageAmount);

        QWidget::setTabOrder(lineEdit, bookID);
        QWidget::setTabOrder(bookID, bookName);
        QWidget::setTabOrder(bookName, bookAuthor);
        QWidget::setTabOrder(bookAuthor, bookPublisher);
        QWidget::setTabOrder(bookPublisher, bookYear);
        QWidget::setTabOrder(bookYear, bookPageAmount);

        retranslateUi(insertDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, insertDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, insertDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(insertDialog);
    } // setupUi

    void retranslateUi(QDialog *insertDialog)
    {
        insertDialog->setWindowTitle(QCoreApplication::translate("insertDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("insertDialog", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("insertDialog", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("insertDialog", "Author:", nullptr));
        label_4->setText(QCoreApplication::translate("insertDialog", "Publisher:", nullptr));
        label_5->setText(QCoreApplication::translate("insertDialog", "Year:", nullptr));
        label_7->setText(QCoreApplication::translate("insertDialog", "Insert before:", nullptr));
        label_6->setText(QCoreApplication::translate("insertDialog", "Page Amount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertDialog: public Ui_insertDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTDIALOG_H
