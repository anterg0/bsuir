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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_File;
    QAction *actionSave_File;
    QAction *actionClose_File;
    QWidget *centralwidget;
    QPushButton *add;
    QLineEdit *delIndex;
    QPushButton *del;
    QPushButton *ins;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QPushButton *edit;
    QPushButton *pushButton_2;
    QLineEdit *findID;
    QLineEdit *search;
    QLineEdit *searchName;
    QLineEdit *searchYear;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName("actionOpen_File");
        actionSave_File = new QAction(MainWindow);
        actionSave_File->setObjectName("actionSave_File");
        actionClose_File = new QAction(MainWindow);
        actionClose_File->setObjectName("actionClose_File");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        add = new QPushButton(centralwidget);
        add->setObjectName("add");
        add->setGeometry(QRect(390, 430, 100, 32));
        delIndex = new QLineEdit(centralwidget);
        delIndex->setObjectName("delIndex");
        delIndex->setGeometry(QRect(520, 480, 113, 21));
        delIndex->setFocusPolicy(Qt::ClickFocus);
        del = new QPushButton(centralwidget);
        del->setObjectName("del");
        del->setGeometry(QRect(530, 500, 100, 32));
        ins = new QPushButton(centralwidget);
        ins->setObjectName("ins");
        ins->setGeometry(QRect(390, 470, 100, 32));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(700, 520, 100, 32));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 30, 791, 391));
        tableWidget->horizontalHeader()->setDefaultSectionSize(126);
        edit = new QPushButton(centralwidget);
        edit->setObjectName("edit");
        edit->setGeometry(QRect(390, 510, 100, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(570, 430, 100, 32));
        findID = new QLineEdit(centralwidget);
        findID->setObjectName("findID");
        findID->setGeometry(QRect(680, 430, 113, 21));
        search = new QLineEdit(centralwidget);
        search->setObjectName("search");
        search->setGeometry(QRect(325, 0, 113, 21));
        searchName = new QLineEdit(centralwidget);
        searchName->setObjectName("searchName");
        searchName->setGeometry(QRect(10, 440, 113, 21));
        searchYear = new QLineEdit(centralwidget);
        searchYear->setObjectName("searchYear");
        searchYear->setGeometry(QRect(10, 470, 113, 21));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 500, 100, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionSave_File);
        menuFile->addAction(actionClose_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        actionSave_File->setText(QCoreApplication::translate("MainWindow", "Save File", nullptr));
        actionClose_File->setText(QCoreApplication::translate("MainWindow", "Close and Save File", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        del->setText(QCoreApplication::translate("MainWindow", "del", nullptr));
        ins->setText(QCoreApplication::translate("MainWindow", "ins", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "debug", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Publisher", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Page Count", nullptr));
        edit->setText(QCoreApplication::translate("MainWindow", "edit", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "find info", nullptr));
        searchName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        searchYear->setPlaceholderText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Search", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
