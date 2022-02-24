#pragma once

class Date
{
public:
    //constructors
    Date();
    Date(int, int, int);
    void displayDate();
    void insertDate(int, int, int);
    bool insertDateString(const std::string&);
    bool checkDate();
    int getDate() { return day; };
    int getMonth() { return month; };
    int getYear() { return year; };
    int countLeapYearDays();
private:
    int day;
    int month;
    int year;
};
