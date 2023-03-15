/********************************************************************************
** Form generated from reading UI file 'adddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOG_H
#define UI_ADDDIALOG_H

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

class Ui_addDialog
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
    QLineEdit *bookYear;
    QLineEdit *bookPublisher;
    QLineEdit *bookPageAmount;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *addDialog)
    {
        if (addDialog->objectName().isEmpty())
            addDialog->setObjectName("addDialog");
        addDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(addDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        formLayoutWidget = new QWidget(addDialog);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(10, 10, 371, 221));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        bookID = new QLineEdit(formLayoutWidget);
        bookID->setObjectName("bookID");

        formLayout->setWidget(0, QFormLayout::FieldRole, bookID);

        bookName = new QLineEdit(formLayoutWidget);
        bookName->setObjectName("bookName");

        formLayout->setWidget(1, QFormLayout::FieldRole, bookName);

        bookAuthor = new QLineEdit(formLayoutWidget);
        bookAuthor->setObjectName("bookAuthor");

        formLayout->setWidget(2, QFormLayout::FieldRole, bookAuthor);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        bookYear = new QLineEdit(formLayoutWidget);
        bookYear->setObjectName("bookYear");

        formLayout->setWidget(4, QFormLayout::FieldRole, bookYear);

        bookPublisher = new QLineEdit(formLayoutWidget);
        bookPublisher->setObjectName("bookPublisher");

        formLayout->setWidget(3, QFormLayout::FieldRole, bookPublisher);

        bookPageAmount = new QLineEdit(formLayoutWidget);
        bookPageAmount->setObjectName("bookPageAmount");

        formLayout->setWidget(5, QFormLayout::FieldRole, bookPageAmount);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        QWidget::setTabOrder(bookID, bookName);
        QWidget::setTabOrder(bookName, bookAuthor);
        QWidget::setTabOrder(bookAuthor, bookPublisher);
        QWidget::setTabOrder(bookPublisher, bookYear);
        QWidget::setTabOrder(bookYear, bookPageAmount);

        retranslateUi(addDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, addDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, addDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(addDialog);
    } // setupUi

    void retranslateUi(QDialog *addDialog)
    {
        addDialog->setWindowTitle(QCoreApplication::translate("addDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("addDialog", "ID:", nullptr));
        label_2->setText(QCoreApplication::translate("addDialog", "Name:", nullptr));
        label_3->setText(QCoreApplication::translate("addDialog", "Author:", nullptr));
        label_4->setText(QCoreApplication::translate("addDialog", "Publisher:", nullptr));
        label_5->setText(QCoreApplication::translate("addDialog", "Year:", nullptr));
        label_6->setText(QCoreApplication::translate("addDialog", "Page Amount:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addDialog: public Ui_addDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOG_H
