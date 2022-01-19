#pragma once

#include <utility>

class Triangle
{
public:
    //member variables
    std::pair<float, float> p1;
    std::pair<float, float> p2;
    std::pair<float, float> p3;

    //constructors
    Triangle();
    Triangle(const Triangle&);

    //member functions
    void constructTriangle();
    void displayTriangle();
    bool isTriangle();
    float findPerimeter();
    float findArea();
    void centerCoordinate();
    void widestCoordinateonX();
    void widestCoordinateonY();
    float distanceToTriangleCoord(const float&, const float&);
    bool isInTriangle(const float&, const float&);
    std::string typeOfTriangle();
};