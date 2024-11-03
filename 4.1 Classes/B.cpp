#include <iostream>

class Date {
public:
    Date(int day, int month, int year) {
        if (IsValidDate(day, month, year)) {
            days_since_epoch = DaysSinceEpoch(day, month, year);
        } else {
            days_since_epoch = DaysSinceEpoch(1, 1, 1970);
        }
    }

    int GetDay() const {
        int d, m, y;
        FromDaysSinceEpoch(d, m, y);
        return d;
    }

    int GetMonth() const {
        int d, m, y;
        FromDaysSinceEpoch(d, m, y);
        return m;
    }

    int GetYear() const {
        int d, m, y;
        FromDaysSinceEpoch(d, m, y);
        return y;
    }

    Date operator+(int days) const {
        Date result(1, 1, 1970);
        result.days_since_epoch = days_since_epoch + days;
        return result;
    }

    Date operator-(int days) const {
        Date result(1, 1, 1970);
        result.days_since_epoch = days_since_epoch - days;
        return result;
    }

    int operator-(const Date& other) const {
        return days_since_epoch - other.days_since_epoch;
    }

private:
    int days_since_epoch;

    static bool IsLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    static bool IsValidDate(int day, int month, int year) {
        if (year < 1970 || year > 2099 || month < 1 || month > 12) return false;
        int days_in_month = DaysInMonth(month, year);
        return day >= 1 && day <= days_in_month;
    }

    static int DaysInMonth(int month, int year) {
        static const int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (month == 2 && IsLeapYear(year)) return 29;
        return days_in_month[month - 1];
    }

    static int DaysSinceEpoch(int day, int month, int year) {
        int days = 0;
        for (int y = 1970; y < year; ++y) {
            days += IsLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < month; ++m) {
            days += DaysInMonth(m, year);
        }
        days += day - 1;
        return days;
    }

    void FromDaysSinceEpoch(int& day, int& month, int& year) const {
        int days = days_since_epoch;
        year = 1970;
        while (days >= (IsLeapYear(year) ? 366 : 365)) {
            days -= IsLeapYear(year) ? 366 : 365;
            ++year;
        }
        month = 1;
        while (days >= DaysInMonth(month, year)) {
            days -= DaysInMonth(month, year);
            ++month;
        }
        day = days + 1;
    }
};