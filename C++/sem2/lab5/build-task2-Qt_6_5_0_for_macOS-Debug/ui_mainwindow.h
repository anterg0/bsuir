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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushB;
    QPushButton *pushF;
    QVBoxLayout *verticalLayout_2;
    QPushButton *emptyButton;
    QPushButton *sizeButton;
    QPushButton *clearButton;
    QVBoxLayout *verticalLayout_3;
    QPushButton *popF;
    QPushButton *popB;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(508, 227);
        MainWindow->setMinimumSize(QSize(508, 227));
        MainWindow->setMaximumSize(QSize(508, 227));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 491, 161));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit);

        pushB = new QPushButton(horizontalLayoutWidget);
        pushB->setObjectName("pushB");

        verticalLayout->addWidget(pushB);

        pushF = new QPushButton(horizontalLayoutWidget);
        pushF->setObjectName("pushF");

        verticalLayout->addWidget(pushF);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        emptyButton = new QPushButton(horizontalLayoutWidget);
        emptyButton->setObjectName("emptyButton");

        verticalLayout_2->addWidget(emptyButton);

        sizeButton = new QPushButton(horizontalLayoutWidget);
        sizeButton->setObjectName("sizeButton");

        verticalLayout_2->addWidget(sizeButton);

        clearButton = new QPushButton(horizontalLayoutWidget);
        clearButton->setObjectName("clearButton");

        verticalLayout_2->addWidget(clearButton);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        popF = new QPushButton(horizontalLayoutWidget);
        popF->setObjectName("popF");

        verticalLayout_3->addWidget(popF);

        popB = new QPushButton(horizontalLayoutWidget);
        popB->setObjectName("popB");

        verticalLayout_3->addWidget(popB);


        horizontalLayout->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 508, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\261\320\265\320\261\321\200\320\260. \320\276\320\271, \321\202\320\276\320\265\321\201\321\202\321\214 deque", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "value", nullptr));
        pushB->setText(QCoreApplication::translate("MainWindow", "push_back", nullptr));
        pushF->setText(QCoreApplication::translate("MainWindow", "push_front", nullptr));
        emptyButton->setText(QCoreApplication::translate("MainWindow", "is it empty?", nullptr));
        sizeButton->setText(QCoreApplication::translate("MainWindow", "how big the deque is?", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "clear the deque", nullptr));
        popF->setText(QCoreApplication::translate("MainWindow", "pop_front", nullptr));
        popB->setText(QCoreApplication::translate("MainWindow", "pop_back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
