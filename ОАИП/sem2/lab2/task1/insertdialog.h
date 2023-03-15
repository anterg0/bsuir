#ifndef INSERTDIALOG_H
#define INSERTDIALOG_H

#include <QDialog>

namespace Ui {
class insertDialog;
}

class insertDialog : public QDialog
{
    Q_OBJECT

public:
    explicit insertDialog(QWidget *parent = nullptr);
    ~insertDialog();
signals:
    void addBook(int index, int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);
private slots:
    void on_buttonBox_accepted();

private:
    Ui::insertDialog *ui;
};

#endif // INSERTDIALOG_H
