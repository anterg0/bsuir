#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>

namespace Ui {
class addDialog;
}

class addDialog : public QDialog
{
    Q_OBJECT

public:
    explicit addDialog(QWidget *parent = nullptr);
    ~addDialog();
    void setEdit(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);
signals:
    void addBook(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);
private slots:
    void on_buttonBox_accepted();


private:
    Ui::addDialog *ui;
};

#endif // ADDDIALOG_H
