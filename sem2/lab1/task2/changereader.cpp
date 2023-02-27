#include "changereader.h"
#include "ui_changereader.h"

changeReader::changeReader(MainWindow *mainWindow, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changeReader),
    m_mainWindow(mainWindow)
{
    ui->setupUi(this);
}

changeReader::~changeReader()
{
    delete ui;
}
