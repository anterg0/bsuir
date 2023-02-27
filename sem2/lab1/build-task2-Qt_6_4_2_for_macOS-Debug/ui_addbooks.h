/********************************************************************************
** Form generated from reading UI file 'addbooks.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKS_H
#define UI_ADDBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addBooks
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QLineEdit *bookID;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_4;
    QLineEdit *bookName;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_5;
    QLineEdit *bookAuthor;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLineEdit *bookLanguage;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_6;
    QDateEdit *bookYear;
    QSpacerItem *verticalSpacer_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_7;
    QPushButton *editButton;

    void setupUi(QDialog *addBooks)
    {
        if (addBooks->objectName().isEmpty())
            addBooks->setObjectName("addBooks");
        addBooks->resize(904, 148);
        addBooks->setMinimumSize(QSize(904, 148));
        addBooks->setMaximumSize(QSize(904, 148));
        horizontalLayoutWidget = new QWidget(addBooks);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 891, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_3);

        bookID = new QLineEdit(horizontalLayoutWidget);
        bookID->setObjectName("bookID");

        verticalLayout_3->addWidget(bookID);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_4 = new QLabel(horizontalLayoutWidget);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_4);

        bookName = new QLineEdit(horizontalLayoutWidget);
        bookName->setObjectName("bookName");

        verticalLayout_4->addWidget(bookName);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_5 = new QLabel(horizontalLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_5);

        bookAuthor = new QLineEdit(horizontalLayoutWidget);
        bookAuthor->setObjectName("bookAuthor");

        verticalLayout_5->addWidget(bookAuthor);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label);

        bookLanguage = new QLineEdit(horizontalLayoutWidget);
        bookLanguage->setObjectName("bookLanguage");

        verticalLayout_6->addWidget(bookLanguage);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_5);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_6 = new QLabel(horizontalLayoutWidget);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_6);

        bookYear = new QDateEdit(horizontalLayoutWidget);
        bookYear->setObjectName("bookYear");

        verticalLayout_7->addWidget(bookYear);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_6);


        horizontalLayout->addLayout(verticalLayout_7);

        pushButton = new QPushButton(addBooks);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 110, 100, 32));
        pushButton_2 = new QPushButton(addBooks);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(440, 110, 100, 32));
        label_7 = new QLabel(addBooks);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(550, 115, 341, 21));
        editButton = new QPushButton(addBooks);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(440, 110, 100, 32));
        editButton->raise();
        horizontalLayoutWidget->raise();
        pushButton->raise();
        pushButton_2->raise();
        label_7->raise();

        retranslateUi(addBooks);

        QMetaObject::connectSlotsByName(addBooks);
    } // setupUi

    void retranslateUi(QDialog *addBooks)
    {
        addBooks->setWindowTitle(QCoreApplication::translate("addBooks", "\320\260\321\200\321\205\320\270\320\262\320\260\321\200\320\270\321\203\320\274", nullptr));
        label_3->setText(QCoreApplication::translate("addBooks", "\320\232\320\276\320\264 \320\272\320\275\320\270\320\263\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("addBooks", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_5->setText(QCoreApplication::translate("addBooks", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        label->setText(QCoreApplication::translate("addBooks", "\320\257\320\267\321\213\320\272 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));
        label_6->setText(QCoreApplication::translate("addBooks", "\320\223\320\276\320\264 \320\270\320\267\320\264\320\260\320\275\320\270\321\217", nullptr));
        bookYear->setDisplayFormat(QCoreApplication::translate("addBooks", "yyyy", nullptr));
        pushButton->setText(QCoreApplication::translate("addBooks", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("addBooks", "\320\236\320\272", nullptr));
        label_7->setText(QString());
        editButton->setText(QCoreApplication::translate("addBooks", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addBooks: public Ui_addBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKS_H
