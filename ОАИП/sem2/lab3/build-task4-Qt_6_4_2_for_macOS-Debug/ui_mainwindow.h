/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
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
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *v1Label;
    QLineEdit *v1Elements;
    QHBoxLayout *horizontalLayout;
    QLabel *v1maxLabel;
    QLabel *v1MaxSize;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *v2Label;
    QLineEdit *v2Elements;
    QHBoxLayout *horizontalLayout_2;
    QLabel *v2MaxLabel;
    QLabel *v2MaxSize;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *pushValue;
    QPushButton *v1Push;
    QPushButton *v2Push;
    QPushButton *v1Pop;
    QPushButton *v2Pop;
    QVBoxLayout *verticalLayout_4;
    QPushButton *swapVec;
    QPushButton *v1Clear;
    QPushButton *v2Clear;
    QVBoxLayout *verticalLayout_5;
    QLineEdit *resizeValue;
    QPushButton *v1Resize;
    QPushButton *v2Resize;
    QVBoxLayout *verticalLayout_6;
    QLineEdit *atValue;
    QPushButton *v1At;
    QPushButton *v2At;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 310);
        MainWindow->setMinimumSize(QSize(800, 310));
        MainWindow->setMaximumSize(QSize(800, 310));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 391, 83));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        v1Label = new QLabel(verticalLayoutWidget_2);
        v1Label->setObjectName("v1Label");
        v1Label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(v1Label);

        v1Elements = new QLineEdit(verticalLayoutWidget_2);
        v1Elements->setObjectName("v1Elements");
        v1Elements->setAlignment(Qt::AlignCenter);
        v1Elements->setReadOnly(true);

        verticalLayout_2->addWidget(v1Elements);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        v1maxLabel = new QLabel(verticalLayoutWidget_2);
        v1maxLabel->setObjectName("v1maxLabel");
        v1maxLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(v1maxLabel);

        v1MaxSize = new QLabel(verticalLayoutWidget_2);
        v1MaxSize->setObjectName("v1MaxSize");

        horizontalLayout->addWidget(v1MaxSize);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(400, 0, 391, 81));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        v2Label = new QLabel(verticalLayoutWidget_3);
        v2Label->setObjectName("v2Label");
        v2Label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(v2Label);

        v2Elements = new QLineEdit(verticalLayoutWidget_3);
        v2Elements->setObjectName("v2Elements");
        v2Elements->setAlignment(Qt::AlignCenter);
        v2Elements->setReadOnly(true);

        verticalLayout_3->addWidget(v2Elements);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        v2MaxLabel = new QLabel(verticalLayoutWidget_3);
        v2MaxLabel->setObjectName("v2MaxLabel");
        v2MaxLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(v2MaxLabel);

        v2MaxSize = new QLabel(verticalLayoutWidget_3);
        v2MaxSize->setObjectName("v2MaxSize");

        horizontalLayout_2->addWidget(v2MaxSize);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(0, 90, 791, 162));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        pushValue = new QLineEdit(horizontalLayoutWidget_3);
        pushValue->setObjectName("pushValue");

        verticalLayout->addWidget(pushValue);

        v1Push = new QPushButton(horizontalLayoutWidget_3);
        v1Push->setObjectName("v1Push");

        verticalLayout->addWidget(v1Push);

        v2Push = new QPushButton(horizontalLayoutWidget_3);
        v2Push->setObjectName("v2Push");

        verticalLayout->addWidget(v2Push);

        v1Pop = new QPushButton(horizontalLayoutWidget_3);
        v1Pop->setObjectName("v1Pop");

        verticalLayout->addWidget(v1Pop);

        v2Pop = new QPushButton(horizontalLayoutWidget_3);
        v2Pop->setObjectName("v2Pop");

        verticalLayout->addWidget(v2Pop);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        swapVec = new QPushButton(horizontalLayoutWidget_3);
        swapVec->setObjectName("swapVec");

        verticalLayout_4->addWidget(swapVec);

        v1Clear = new QPushButton(horizontalLayoutWidget_3);
        v1Clear->setObjectName("v1Clear");

        verticalLayout_4->addWidget(v1Clear);

        v2Clear = new QPushButton(horizontalLayoutWidget_3);
        v2Clear->setObjectName("v2Clear");

        verticalLayout_4->addWidget(v2Clear);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        resizeValue = new QLineEdit(horizontalLayoutWidget_3);
        resizeValue->setObjectName("resizeValue");

        verticalLayout_5->addWidget(resizeValue);

        v1Resize = new QPushButton(horizontalLayoutWidget_3);
        v1Resize->setObjectName("v1Resize");

        verticalLayout_5->addWidget(v1Resize);

        v2Resize = new QPushButton(horizontalLayoutWidget_3);
        v2Resize->setObjectName("v2Resize");

        verticalLayout_5->addWidget(v2Resize);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        atValue = new QLineEdit(horizontalLayoutWidget_3);
        atValue->setObjectName("atValue");

        verticalLayout_6->addWidget(atValue);

        v1At = new QPushButton(horizontalLayoutWidget_3);
        v1At->setObjectName("v1At");

        verticalLayout_6->addWidget(v1At);

        v2At = new QPushButton(horizontalLayoutWidget_3);
        v2At->setObjectName("v2At");

        verticalLayout_6->addWidget(v2At);


        horizontalLayout_3->addLayout(verticalLayout_6);

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
        v1Label->setText(QCoreApplication::translate("MainWindow", "MyVector<int> v1:", nullptr));
        v1maxLabel->setText(QCoreApplication::translate("MainWindow", "max_size:", nullptr));
        v1MaxSize->setText(QString());
        v2Label->setText(QCoreApplication::translate("MainWindow", "MyVector<int> v2:", nullptr));
        v2MaxLabel->setText(QCoreApplication::translate("MainWindow", "max_size:", nullptr));
        v2MaxSize->setText(QString());
        pushValue->setPlaceholderText(QCoreApplication::translate("MainWindow", "push_back value", nullptr));
        v1Push->setText(QCoreApplication::translate("MainWindow", "push_back to v1", nullptr));
        v2Push->setText(QCoreApplication::translate("MainWindow", "push_back to v2", nullptr));
        v1Pop->setText(QCoreApplication::translate("MainWindow", "pop_back v1", nullptr));
        v2Pop->setText(QCoreApplication::translate("MainWindow", "pop_back v2", nullptr));
        swapVec->setText(QCoreApplication::translate("MainWindow", "swap vectors", nullptr));
        v1Clear->setText(QCoreApplication::translate("MainWindow", "clear v1", nullptr));
        v2Clear->setText(QCoreApplication::translate("MainWindow", "clear v2", nullptr));
        resizeValue->setPlaceholderText(QCoreApplication::translate("MainWindow", "resize value", nullptr));
        v1Resize->setText(QCoreApplication::translate("MainWindow", "resize v1", nullptr));
        v2Resize->setText(QCoreApplication::translate("MainWindow", "resize v2", nullptr));
        atValue->setPlaceholderText(QCoreApplication::translate("MainWindow", "at index", nullptr));
        v1At->setText(QCoreApplication::translate("MainWindow", "at v1", nullptr));
        v2At->setText(QCoreApplication::translate("MainWindow", "at v2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
