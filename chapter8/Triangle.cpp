#pragma once

#include <iostream>
#include <vector> // ?
#include <math.h>

#include "Triangle.h"

//helpers
float distanceBetweenPoints(const float& x1, const float& y1, const float& x2, const float& y2)
{
    return (float)std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

float findRelativeDistance(const float& x1, const float& y1, const float& x2, const float& y2, const float& x3, const float& y3)
{
    return (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3);
}

//constructors
Triangle::Triangle()
{
    p1.first = 0;
    p1.second = 0;
    p2.first = 0;
    p2.second = 0;
    p3.first = 0;
    p3.second = 0;
}

Triangle::Triangle(const Triangle& triangle)
{
    p1.first = triangle.p1.first;
    p1.second = triangle.p1.second;
    p2.first = triangle.p2.first;
    p2.second = triangle.p2.second;
    p3.first = triangle.p3.first;
    p3.second = triangle.p3.second;
}


//methods
void Triangle::constructTriangle()
{
    std::cout << "Enter the 3 coordinates to construct a Triangle.\n";
    std::cout << "\nFirst Coordinate: \n";
    std::cout << "x1 = ";
    std::cin >> p1.first;
    std::cout << "y1 = ";
    std::cin >> p1.second;
    std::cout << "\nSecond Coordinate: \n";
    std::cout << "x2 = ";
    std::cin >> p2.first;
    std::cout << "y2 = ";
    std::cin >> p2.second;
    std::cout << "\nThird Coordinate: \n";
    std::cout << "x3 = ";
    std::cin >> p3.first;
    std::cout << "y3 = ";
    std::cin >> p3.second;

}

void Triangle::displayTriangle()
{
    std::cout << "\n((" << p1.first << ", " << p1.second << ");(" << p2.first << ", " << p2.second << ");(" << p3.first << ", " << p3.second << "))\n";
}

bool Triangle::isTriangle()
{
    float ab = distanceBetweenPoints(p1.first, p1.second, p2.first, p2.second);
    float ac = distanceBetweenPoints(p1.first, p1.second, p3.first, p3.second);
    float bc = distanceBetweenPoints(p2.first, p2.second, p3.first, p3.second);

    if (ab + bc <= ac || ab + ac <= bc || ac + bc <= ab)
        return false;
    return true;
}

float Triangle::findPerimeter()
{
    if (isTriangle())
        return distanceBetweenPoints(p1.first, p1.second, p2.first, p2.second) +
        distanceBetweenPoints(p1.first, p1.second, p3.first, p3.second) +
        distanceBetweenPoints(p2.first, p2.second, p3.first, p3.second);
    std::cout << "\nThis is not a triangle\n";
    return 0;
}

float Triangle::findArea()
{
    if (isTriangle())
        return std::sqrt((findPerimeter() / 2) *
            ((findPerimeter() / 2) - distanceBetweenPoints(p1.first, p1.second, p2.first, p2.second)) *
            ((findPerimeter() / 2) - distanceBetweenPoints(p1.first, p1.second, p3.first, p3.second)) *
            ((findPerimeter() / 2) - distanceBetweenPoints(p2.first, p2.second, p3.first, p3.second))
        );
    return 0;
}

void Triangle::centerCoordinate()
{
    if (isTriangle())
    {
        float xCoord = (p1.first + p2.first + p3.first) / 3;
        float yCoord = (p1.second + p2.second + p3.second) / 3;

        std::cout << "Center Coordinate is: \n";
        std::cout << "x = " << xCoord << "\ty = " << yCoord << "\n";
    }
}

void Triangle::widestCoordinateonX()
{
    if (isTriangle())
    {
        float x = std::max(p1.first, p2.first);
        x = std::max(p3.first, x);

        float y = 0;

        if (x == p1.first)
            y = p1.second;
        if (x == p2.first)
            y = p2.second;
        if (x == p3.first)
            y = p3.second;

        std::cout << "Answer: x = " << x << "\ty = " << y << "\n";
    }
}

void Triangle::widestCoordinateonY()
{
    if (isTriangle())
    {
        float y = std::max(p1.second, p2.second);
        y = std::max(p3.second, y);

        float x = 0;

        if (y == p1.second)
            x = p1.first;
        if (y == p2.second)
            x = p2.first;
        if (y == p3.second)
            x = p3.first;

        std::cout << "Answer: x = " << x << "\ty = " << y << "\n";
    }
}

float Triangle::distanceToTriangleCoord(const float& x, const float& y)
{
    std::cout << "Point 1: " << distanceBetweenPoints(x, y, p1.first, p1.second) << "\n";
    std::cout << "Point 2: " << distanceBetweenPoints(x, y, p2.first, p2.second) << "\n";
    std::cout << "Point 3: " << distanceBetweenPoints(x, y, p3.first, p3.second) << "\n";

    return distanceBetweenPoints(x, y, p1.first, p1.second) + distanceBetweenPoints(x, y, p2.first, p2.second) + distanceBetweenPoints(x, y, p3.first, p3.second);
}

bool Triangle::isInTriangle(const float& x, const float& y)
{
    bool checkA = findRelativeDistance(x, y, p1.first, p1.second, p2.first, p2.second) < (float)0;
    bool checkB = findRelativeDistance(x, y, p2.first, p2.second, p3.first, p3.second) < (float)0;
    bool checkC = findRelativeDistance(x, y, p1.first, p1.second, p3.first, p3.second) < (float)0;

    return ((checkB == checkA) && (checkB == checkC));
}

std::string Triangle::typeOfTriangle()
{
    float AB = distanceBetweenPoints(p1.first, p1.second, p2.first, p2.second);
    float BC = distanceBetweenPoints(p2.first, p2.second, p3.first, p3.second);
    float AC = distanceBetweenPoints(p1.first, p1.second, p3.first, p3.second);

    if (AB == BC && AB == AC)
        return "This is an equilateral triangle.\n";
    else
    {
        if (AB == BC || AB == AC || BC == AC)
            return "This is an Isosceles triangle.\n";

        if (AC * AC + BC * BC == AB * AB || AB * AB + BC * BC == AC * AC || AB * AB + AC * AC == BC * BC)
            return "This is a Right Angle triangle.\n";

        else
            return "This is a Scalene triangle.\n";
    }
}