#pragma once

class Fraction
{
public:
    //member variables 
    float numerator;
    float denominator;

    //constructor
    Fraction();
    Fraction(float a, float b);
    Fraction(float a);
    Fraction(const Fraction&);


    //overloading operators
    Fraction operator+(const Fraction&);
    Fraction operator-(const Fraction&);
    Fraction operator*(const Fraction&);
    Fraction operator/(const Fraction&);
    Fraction operator++(); //pre-increment
    Fraction operator--();
    friend std::ostream& operator<<(std::ostream&, const Fraction&);
    friend std::istream& operator>>(std::istream&, Fraction&);

    //member functions
    void constructFraction();
    void display();
    Fraction simplify();
    Fraction addTwoFraction(Fraction);
    Fraction subtractTwoFraction(Fraction);
    Fraction productTwoFraction(Fraction);
    Fraction divideTwoFraction(Fraction);
    void findCommonDenominator(Fraction&);


    //bool functions
    bool isSimplified();
    bool isPositive();
    bool isNegative();
    int compareFraction(const Fraction&);
};

