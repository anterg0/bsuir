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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *Debters;
    QAction *bookList;
    QWidget *centralwidget;
    QPushButton *pushButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *id;
    QLineEdit *phone;
    QLineEdit *addr;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QComboBox *comboBox;
    QLabel *label;
    QListWidget *listWidget;
    QPushButton *addBook;
    QListWidget *listWidget_2;
    QPushButton *pushButton_2;
    QPushButton *addReader;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QDateEdit *dateEdit;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QComboBox *comboBox_2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_7;
    QPushButton *pushButton_11;
    QComboBox *comboBox_3;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(729, 598);
        MainWindow->setMinimumSize(QSize(729, 598));
        MainWindow->setMaximumSize(QSize(729, 598));
        MainWindow->setTabShape(QTabWidget::Rounded);
        Debters = new QAction(MainWindow);
        Debters->setObjectName("Debters");
        bookList = new QAction(MainWindow);
        bookList->setObjectName("bookList");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(729, 547));
        centralwidget->setMaximumSize(QSize(729, 547));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 230, 251, 32));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(60, 90, 191, 127));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        id = new QLineEdit(verticalLayoutWidget);
        id->setObjectName("id");
        id->setReadOnly(true);

        verticalLayout->addWidget(id);

        phone = new QLineEdit(verticalLayoutWidget);
        phone->setObjectName("phone");
        phone->setReadOnly(true);

        verticalLayout->addWidget(phone);

        addr = new QLineEdit(verticalLayoutWidget);
        addr->setObjectName("addr");
        addr->setReadOnly(true);

        verticalLayout->addWidget(addr);

        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(-150, 40, 401, 41));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(-1);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(100, 0));

        gridLayout->addWidget(comboBox, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(280, 0, 256, 192));
        addBook = new QPushButton(centralwidget);
        addBook->setObjectName("addBook");
        addBook->setGeometry(QRect(280, 400, 121, 32));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(280, 200, 256, 192));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(90, 0, 100, 32));
        addReader = new QPushButton(centralwidget);
        addReader->setObjectName("addReader");
        addReader->setGeometry(QRect(10, 260, 251, 32));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 290, 251, 32));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(9, 320, 251, 32));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(410, 400, 121, 32));
        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(10, 370, 251, 22));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 390, 251, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 350, 101, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 430, 221, 16));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 450, 171, 32));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(280, 430, 121, 32));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(410, 430, 121, 32));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(280, 460, 121, 32));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(540, -10, 161, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(540, 190, 101, 41));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(540, 230, 177, 91));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_2->addWidget(label_6);

        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName("lineEdit");

        verticalLayout_2->addWidget(lineEdit);

        comboBox_2 = new QComboBox(verticalLayoutWidget_2);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        verticalLayout_2->addWidget(comboBox_2);

        verticalLayoutWidget_3 = new QWidget(centralwidget);
        verticalLayoutWidget_3->setObjectName("verticalLayoutWidget_3");
        verticalLayoutWidget_3->setGeometry(QRect(540, 330, 177, 95));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        verticalLayout_4->addWidget(label_7);

        pushButton_11 = new QPushButton(verticalLayoutWidget_3);
        pushButton_11->setObjectName("pushButton_11");

        verticalLayout_4->addWidget(pushButton_11);

        comboBox_3 = new QComboBox(verticalLayoutWidget_3);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");

        verticalLayout_4->addWidget(comboBox_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 729, 24));
        menubar->setMinimumSize(QSize(729, 24));
        menubar->setMaximumSize(QSize(729, 24));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setMinimumSize(QSize(729, 27));
        statusbar->setMaximumSize(QSize(729, 27));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menu->addAction(Debters);
        menu->addAction(bookList);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "welcome to the \320\261\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260, bitch", nullptr));
        Debters->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\264\320\276\320\273\320\266\320\275\320\270\320\272\320\276\320\262", nullptr));
        bookList->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \320\272\320\275\320\270\320\263 \321\203 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
        id->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        phone->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        addr->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236:", nullptr));
        addBook->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        addReader->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\262\321\213\320\261\321\200\320\260\320\275\320\275\321\203\321\216 \320\272\320\275\320\270\320\263\321\203 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\216", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\262\320\276\320\267\320\262\321\200\320\260\321\202\320\260", nullptr));
        label_3->setText(QString());
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\320\270", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\272\320\275\320\270\320\263\320\270", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<- \320\241\320\277\320\270\321\201\320\276\320\272 \320\272\320\275\320\270\320\263 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<- \320\241\320\277\320\270\321\201\320\276\320\272 \320\272\320\275\320\270\320\263", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272 \320\272\320\275\320\270\320\263", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\204\320\260\320\274\320\270\320\273\320\270\320\270 \320\260\320\262\321\202\320\276\321\200\320\260", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", nullptr));

        label_7->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260 \320\272\320\275\320\270\320\263", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\272\320\276\320\264\321\203 \320\272\320\275\320\270\320\263\320\270", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\321\216", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\260\320\262\321\202\320\276\321\200\321\203", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\217\320\267\321\213\320\272\321\203", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("MainWindow", "\320\237\320\276 \320\263\320\276\320\264\321\203", nullptr));

        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
