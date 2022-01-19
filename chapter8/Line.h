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


    //overloading operator
    friend std::ostream& operator<<(std::ostream&, const Line&);
    friend std::istream& operator>>(std::istream&, Line&);
};
