#ifndef DATE_H
#define DATE_H
#include <QDate>

class Date : public QDate {
private:
    QDate nowDate;
public:
    void setDate(QDate date);
    QDate NextDay(QDate date);
    QDate PreviousDay(QDate date);
    int DaysTillYourBirthday(QDate birthDate);
    int Duration(QDate date);
    int birthdayDuration(QDate date);
};

#endif // DATE_H
