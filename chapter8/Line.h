#pragma once

class Line
{
public:
    float a;
    float b;

    //contructor
    Line();
    Line(float, float);
    Line(const Line&);

    //member functions
    bool isParallel(const Line&);
    bool isOverlap(const Line&);
    bool isIntersect(const Line&, const Line&);
    bool isAPointInLine(const float&, const float&);
    Line findClosestToP(std::vector<Line>, const float&, const float&);

    //overloading operator
    friend std::ostream& operator<<(std::ostream&, const Line&);
    friend std::istream& operator>>(std::istream&, Line&);
};
