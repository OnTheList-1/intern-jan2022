#pragma once
#include "Date.h"

class Pet
{
public:
    //Date timeUntilCheckUp(const int&);
    //void foodQuantity();
    Pet()
    {
        weight = 0;
        width = 0;
        height = 0;
        breed = "N/A";
        furColor = "N/A";
        date.insertDate(1, 1, 1990);

    }
    virtual void petFood() {};
    virtual void petInfo() {};
    virtual int dayTillCheckup() { return 999; };

    void setType(const float&, const float&, const float&, const std::string&, const Date&, const std::string&);
    void setHeight(const float&);
    void setWidth(const float&);
    void setWeight(const float&);
    void setFurColor(const std::string&);
    void setDate(const Date&);
    void setBreed(const std::string&);

protected:
    float weight;
    float width;
    float height;
    std::string furColor;
    Date date;
    std::string breed;
};

class Dog : public Pet
{
public:
    void petInfo();
    void petFood();
    void setPlayTime(const int&);
    int dayTillCheckup();

private:
    int playTime;
};

class Cat : public Pet
{
public:
    void petInfo();
    void petFood();
    void setSleptTime(const int&);
    int dayTillCheckup();

private:
    int sleptTime;
};



void run();
