#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "binarysearchtree.cpp"
#include <QStandardItemModel>
#include <QMessageBox>
MyBinarySearchTree tree;

void addChildren(QStandardItem* parentItem, Node* parentNode) {
    if (!parentNode) {
        return;
    }
    if (parentNode->left) {
        QStandardItem* leftChild = new QStandardItem(QString::fromStdString(parentNode->left->data) + " (" + QString::number(parentNode->left->key) + ", L)");
        parentItem->appendRow(leftChild);
        addChildren(leftChild, parentNode->left);
    }
    if (parentNode->right) {
        QStandardItem* rightChild = new QStandardItem(QString::fromStdString(parentNode->right->data) + " (" + QString::number(parentNode->right->key) + ", R)");
        parentItem->appendRow(rightChild);
        addChildren(rightChild, parentNode->right);
    }
}

void displayBinaryTree(QTreeView* treeView, Node* root) {
    QStandardItemModel* model = new QStandardItemModel(treeView);
    QStandardItem* rootNode = new QStandardItem("Root (" + QString::fromStdString(root->data) + ", " + QString::number(root->key) + ")");
    model->appendRow(rootNode);
    addChildren(rootNode, root);
    treeView->setModel(model);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_InsertButton_clicked()
{
    QString inputText = ui->InsertKey->text();

    bool isNumeric = false;
    if (!inputText.isEmpty()) {
        bool conversionOk;
        inputText.toInt(&conversionOk);
        isNumeric = conversionOk;
    }
    if (isNumeric) {
        tree.insert(ui->InsertString->text().toStdString(),ui->InsertKey->text().toInt());
        displayBinaryTree(ui->treeView, tree.getRoot());
    } else {
        QMessageBox::warning(this,"Error","Value should be an int.");
        return;
    }
}


void MainWindow::on_RemoveButton_clicked()
{
    QString inputText = ui->RemoveKey->text();

    bool isNumeric = false;
    if (!inputText.isEmpty()) {
        bool conversionOk;
        inputText.toInt(&conversionOk);
        isNumeric = conversionOk;
    }
    if (isNumeric) {
        tree.remove(ui->RemoveKey->text().toInt());
        displayBinaryTree(ui->treeView, tree.getRoot());
    } else {
        QMessageBox::warning(this,"Error","Value should be an int.");
        return;
    }
}


void MainWindow::on_pushButton_clicked()
{
    tree.printInOrder();
}


void MainWindow::on_pushButton_2_clicked()
{
    tree.balanceTree();
    displayBinaryTree(ui->treeView, tree.getRoot());
}

