#ifndef BOOKINFO_H
#define BOOKINFO_H

#include <QDialog>

namespace Ui {
class bookInfo;
}

class bookInfo : public QDialog
{
    Q_OBJECT

public:
    explicit bookInfo(QWidget *parent = nullptr);
    ~bookInfo();
    void enterInfo(int bookID, QString bookName, QString bookAuthor, QString bookPublisher, int bookYear, int bookPageAmount);
private:
    Ui::bookInfo *ui;
};

#endif // BOOKINFO_H
