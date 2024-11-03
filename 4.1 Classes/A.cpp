#include <iostream>
#include <stdexcept>

class Date {
public:
    Date(int day, int month, int year) {
        if (IsValidDate(day, month, year)) {
            this->day = day;
            this->month = month;
            this->year = year;
        } else {
            this->day = 1;
            this->month = 1;
            this->year = 1970;
        }
    }

    int GetDay() const { return day; }
    int GetMonth() const { return month; }
    int GetYear() const { return year; }

    Date operator+(int days) const {
        Date result(day, month, year);
        result.AddDays(days);
        return result;
    }

    Date operator-(int days) const {
        Date result(day, month, year);
        result.AddDays(-days);
        return result;
    }

    int operator-(const Date& other) const {
        return DaysDifference(*this, other);
    }

private:
    int day, month, year;

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

    void AddDays(int days) {
        day += days;
        while (day > DaysInMonth(month, year)) {
            day -= DaysInMonth(month, year);
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        while (day <= 0) {
            month--;
            if (month < 1) {
                month = 12;
                year--;
            }
            day += DaysInMonth(month, year);
        }
    }

    static int DaysDifference(const Date& date1, const Date& date2) {
        int days1 = DaysSinceEpoch(date1);
        int days2 = DaysSinceEpoch(date2);
        return days1 - days2;
    }

    static int DaysSinceEpoch(const Date& date) {
        int days = 0;
        for (int y = 1970; y < date.year; ++y) {
            days += IsLeapYear(y) ? 366 : 365;
        }
        for (int m = 1; m < date.month; ++m) {
            days += DaysInMonth(m, date.year);
        }
        days += date.day - 1;
        return days;
    }
};