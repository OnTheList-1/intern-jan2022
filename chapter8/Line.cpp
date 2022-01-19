#include <iostream>

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