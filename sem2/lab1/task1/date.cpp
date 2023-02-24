#include "date.h"

QDate Date::NextDay(QDate date){
    return date.addDays(1);
}

QDate Date::PreviousDay(QDate date){
    return date.addDays(-1);
}

void Date::setDate(QDate date) {
    this->nowDate = date;
}

int Date::DaysTillYourBirthday(QDate birthday) {
    QDate today = this->nowDate;
        if (today == birthday) {
            return 0;
        }
        QDate nextBirthday;

        if (birthday.month() == 2 && birthday.day() == 29) {
            if (!today.isLeapYear(today.year()) && birthday.isLeapYear(birthday.year())) {
                nextBirthday.setDate(today.year() + (4 - today.year() % 4), birthday.month(), birthday.day());
            } else nextBirthday.setDate(today.year(), birthday.month(), birthday.day());
        } else nextBirthday.setDate(today.year(), birthday.month(), birthday.day());

        if (nextBirthday < today) {
            nextBirthday = nextBirthday.addYears(1);
        }

        return today.daysTo(nextBirthday);
}

int Date::Duration(QDate date) {
    return qAbs(nowDate.daysTo(date));
}

int Date::birthdayDuration(QDate date) {
    if (date == nowDate || date < nowDate) return 0;
    return qAbs(nowDate.daysTo(date));
}
