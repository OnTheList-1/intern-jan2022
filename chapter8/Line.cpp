#include <iostream>
#include <vector>
#include <math.h>

#include "Line.h"

//constructors
Line::Line()
{
    a = 0;
    b = 0;
}

Line::Line(float a1, float b1)
{
    a = a1;
    b = b1;
}

Line::Line(const Line& Line)
{
    a = Line.a;
    b = Line.b;
}


//member functions
bool Line::isParallel(const Line& Line)
{
    if (a != Line.a)
        return false;
    return true;
}

bool Line::isOverlap(const Line& Line)
{
    if (a == Line.a && b == Line.b)
        return true;
    return false;
}

bool Line::isIntersect(const Line& Line2, const Line& Line3)
{
    if (a - Line2.a == 0 && a - Line3.a == 0) //check gradient
        return false;
    return true;
}

bool Line::isAPointInLine(const float& a1, const float& b1)
{
    if (b1 == (a * a1) + b)
        return true;
    return false;
}

Line Line::findClosestToP(std::vector<Line> vec, const float& a1, const float& b1)
{
    float firstElement = (std::abs(vec[0].a * a1 + (-1 * b1) + vec[0].b)) / (float)std::sqrt(std::pow(3, 2) + std::pow(-vec[0].b, 2));

    std::pair<Line, float> p{ vec[0], firstElement };

    for (int i = 0; i < vec.size(); ++i)
    {
        if (p.second > (std::abs(vec[i].a * a1 + (-1 * b1) + vec[i].b)) / std::sqrt(std::pow(3, 2) + std::pow(-vec[i].b, 2)))
        {
            p.first = vec[i];
            p.second = std::abs(vec[i].a * a1 + (-1 * b1) + vec[i].b) / (float)std::sqrt(std::pow(3, 2) + std::pow(-vec[i].b, 2));
        }
    }

    return p.first;
}


//overloading operator
std::ostream& operator<<(std::ostream& os, const Line& Line)
{
    os << "\ny = " << Line.a << "x + " << Line.b << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Line& Line)
{
    std::cout << "Enter Formula y = ax + b\n";
    std::cout << "a = ";
    is >> Line.a;
    std::cout << "b = ";
    is >> Line.b;
    return is;
}