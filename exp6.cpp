#include <iostream>
using namespace std;

class Date {
private:
    int day, month, year;

    bool isLeapYear(int year) const {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    // to get the number of days in a given month
    int daysInMonth(int month, int year) const {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 0;
        }
    }

public:

 Date(int d = 1, int m = 1, int y = 2000) : day(d), month(m), year(y) {}

    bool operator<(const Date& other) const {
        if (year < other.year) return true;
        if (year == other.year && month < other.month) return true;
        if (year == other.year && month == other.month && day < other.day) return true;
        return false;
    }

    bool operator<=(const Date& other) const {
        return *this < other || *this == other;
    }

    bool operator>(const Date& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Date& other) const {
        return !(*this < other);
    }

    bool operator==(const Date& other) const {
        return day == other.day && month == other.month && year == other.year;
    }

    bool operator!=(const Date& other) const {
        return !(*this == other);
    }

    Date& operator++() {
        day++;
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
        return *this;
    }

    Date operator+(int days) const {
        Date newDate = *this;
        newDate.day += days;

        while (newDate.day > newDate.daysInMonth(newDate.month, newDate.year)) {
            newDate.day -= newDate.daysInMonth(newDate.month, newDate.year);
            newDate.month++;
            if (newDate.month > 12) {
                newDate.month = 1;
                newDate.year++;
            }
        }

        return newDate;
    }

    operator int() const {
        int daysElapsed = day;
        for (int m = 1; m < month; ++m) {
            daysElapsed += daysInMonth(m, year);
        }
        return daysElapsed;
    }

    void print() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main() {
    Date dt(15, 8, 2024);  
    dt.print();            

    Date dt2 = dt + 10;    
    dt2.print();           

    ++dt2;                 
    dt2.print();           

    if (dt < dt2) {
        cout << "dt is earlier than dt2" << endl;
    }

    int daysElapsed = dt;  // Date to int
    cout << "Days elapsed in the year: " << daysElapsed << endl;  // Output: Days elapsed in the year: 228

    return 0;
}
