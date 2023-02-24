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

int Date::DaysTillYourBirthday(QDate birthDate) {
    if (birthDate.isLeapYear(birthDate.year()) && nowDate.isLeapYear(nowDate.year()) && (birthDate == nowDate)) {
        birthDate = birthDate.addYears(4);
    }
    if (birthDate.isLeapYear(birthDate.year()) && !nowDate.isLeapYear(nowDate.year())) {
        birthDate = birthDate.addDays(1);
    }
    if (nowDate.isLeapYear(nowDate.year()) && !birthDate.isLeapYear(birthDate.year())) {
        birthDate = birthDate.addDays(-1);
    }
    birthDate.setDate(nowDate.year(), birthDate.month(), birthDate.day());
    if (nowDate > birthDate) {
        birthDate = birthDate.addYears(1);
    }
    int daysToBirthday = nowDate.daysTo(birthDate);
    return daysToBirthday;
}

int Date::Duration(QDate date) {
    return qAbs(nowDate.daysTo(date));
}
