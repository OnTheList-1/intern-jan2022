#include <iostream>
#include <ctime>

#include "Pet.h"
#include "Date.h"

const int monthDays[12] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };


/*              Date            */
Date timeUntilCheckUp()
{
    Date d;
    return d;
}



/*              Pet             */

void Pet::setType(const float& w, const float& w1, const float& h, const std::string& color, const Date& d, const std::string& b)
{
    weight = w;
    width = w1;
    height = h;
    furColor = color;
    date = d;
    breed = b;
}

void Pet::setWeight(const float& w)
{
    weight = w;
}

void Pet::setHeight(const float& h)
{
    height = h;
}

void Pet::setWidth(const float& wi)
{
    width = wi;
}

void Pet::setFurColor(const std::string& color)
{
    furColor.assign(color);
}

void Pet::setDate(const Date& d)
{
    date = d;
}

void Pet::setBreed(const std::string& b)
{
    breed.assign(b);
}



/*              Dog             */

void Dog::petFood()
{
    std::cout << breed << " doesn't need to eat breakfast but has to eat " << (weight / 20) + (height / 10) << "g in the evening.\n";
}

void Dog::setPlayTime(const int& h)
{
    playTime = h;
}

void Dog::petInfo()
{
    std::cout << "\nYour Pet: " << "\n";
    std::cout << "Weight: " << weight << "\n";
    std::cout << "Width: " << width << "\n";
    std::cout << "Height: " << height << "\n";
    std::cout << "Breed: " << breed << "\n";
    std::cout << "Fur color: " << furColor << "\n";
    std::cout << "Most recent checkup date: ";
    date.displayDate();
    std::cout << "Play time: " << playTime << "\n";
    petFood();
    std::cout << "Days until checkup: " << dayTillCheckup() << "\n";

}

int Dog::dayTillCheckup()
{
    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);


    Date curr(timeinfo.tm_mon, timeinfo.tm_wday, timeinfo.tm_year);

    int dayCount1 = (date.getYear() * 365);
    dayCount1 += monthDays[date.getMonth()];
    dayCount1 += date.getDate();

    int dayCount2 = (timeinfo.tm_year * 365);
    dayCount2 += monthDays[timeinfo.tm_mon];
    dayCount2 += timeinfo.tm_wday;

    if (dayCount2 - dayCount1 > 180)
        std::cout << "Time to checkup!\n";

    return dayCount2 - dayCount1;
}


/*              Cat             */
void Cat::petFood()
{
    std::cout << breed << " needs to eat " << (height * 5) << "g in the morning & " << (height * 5) + 5 - sleptTime << "g in the evening.\n";
}

void Cat::setSleptTime(const int& h)
{
    sleptTime = h;
}

void Cat::petInfo()
{
    std::cout << "\nYour Pet: " << "\n";
    std::cout << "Weight: " << weight << "\n";
    std::cout << "Width: " << width << "\n";
    std::cout << "Height: " << height << "\n";
    std::cout << "Breed: " << breed << "\n";
    std::cout << "Fur color: " << furColor << "\n";
    std::cout << "Most recent checkup date: ";
    date.displayDate();
    std::cout << "\nNap time: " << sleptTime << "\n";
    petFood();
    std::cout << "Days until checkup: " << dayTillCheckup() << "\n";
}

int Cat::dayTillCheckup()
{
    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);

    Date curr(1 + timeinfo.tm_mon, timeinfo.tm_mday, 1900 + timeinfo.tm_year);


    int dayCount1 = date.getYear() * 365;
    dayCount1 += monthDays[date.getMonth() - 1];
    dayCount1 += date.getDate();
    dayCount1 += date.countLeapYearDays();

    int dayCount2 = (timeinfo.tm_year + 1900) * 365;
    dayCount2 += monthDays[timeinfo.tm_mon];
    dayCount2 += timeinfo.tm_mday;
    dayCount2 += curr.countLeapYearDays();

    if (dayCount2 - dayCount1 > 90)
        std::cout << "Time to checkup!\n";

    return dayCount2 - dayCount1;
}