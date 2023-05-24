/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeView *treeView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *InsertString;
    QLineEdit *InsertKey;
    QPushButton *InsertButton;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *RemoveKey;
    QPushButton *RemoveButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        treeView->setGeometry(QRect(10, 10, 481, 361));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(500, 10, 291, 361));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        InsertString = new QLineEdit(verticalLayoutWidget);
        InsertString->setObjectName("InsertString");

        verticalLayout_2->addWidget(InsertString);

        InsertKey = new QLineEdit(verticalLayoutWidget);
        InsertKey->setObjectName("InsertKey");

        verticalLayout_2->addWidget(InsertKey);

        InsertButton = new QPushButton(verticalLayoutWidget);
        InsertButton->setObjectName("InsertButton");

        verticalLayout_2->addWidget(InsertButton);


        verticalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        RemoveKey = new QLineEdit(verticalLayoutWidget);
        RemoveKey->setObjectName("RemoveKey");

        verticalLayout_3->addWidget(RemoveKey);

        RemoveButton = new QPushButton(verticalLayoutWidget);
        RemoveButton->setObjectName("RemoveButton");

        verticalLayout_3->addWidget(RemoveButton);


        verticalLayout->addLayout(verticalLayout_3);

        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(690, 510, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        InsertString->setPlaceholderText(QCoreApplication::translate("MainWindow", "string", nullptr));
        InsertKey->setPlaceholderText(QCoreApplication::translate("MainWindow", "key", nullptr));
        InsertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        RemoveKey->setPlaceholderText(QCoreApplication::translate("MainWindow", "key", nullptr));
        RemoveButton->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "balance", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "debug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
