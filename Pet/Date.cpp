#include <iostream>
#include <string>
#include "Date.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 1990;
}

Date::Date(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

void Date::displayDate()
{
    std::cout << month << "/" << day << "/" << year << " ";
}

void Date::insertDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}

bool Date::insertDateString(const std::string& str)
{
    if (str.find('/') != std::string::npos && str.rfind('/') != str.find('/'))
    {
        month = std::stoi(str.substr(0, str.find('/')));
        day = std::stoi(str.substr(str.find('/') + 1, str.rfind('/')));
        year = std::stoi(str.substr(str.rfind('/') + 1, str.length() - 1));
    }
    else
    {
        std::cout << "bad format\n";
        return false;
    }

    if (this->checkDate() == false)
    {
        std::cout << "bad format\n";
        return false;
    }

    return true;
}

bool Date::checkDate()
{
    bool flag = true;
    if (day < 1 || day > 31)
        flag = false;

    else if (month < 1 || month > 12)
        flag = false;


    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
        flag = false;

    else if ((month == 2) && (year % 4 == 0) && day > 29)
        flag = false;

    else if ((month == 2) && (year % 4 != 0) && day > 28)
        flag = false;

    return flag;
}

int Date::countLeapYearDays() {
    if (month <= 2)
        year--;
    return ((year / 4) - (year / 100) + (year / 400));
}
