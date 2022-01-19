#include <iostream>

#include "Fraction.h"

//catch divide by zero error
inline float intDivideEx(float numerator, float denominator)
{
    if (denominator == 0)
        throw std::overflow_error("Divide by zero exception.\n");
    return numerator / denominator;
}


//helpers
float getGCD(float a, float b)
{
    if (b == 0)
        return a;
    return getGCD(b, float((int)a % (int)b));
}


//constructors
Fraction::Fraction()
{
    numerator = 1;
    denominator = 1;
}

Fraction::Fraction(float a, float b) // a/b
{
    try
    {
        float i = intDivideEx(a, b);

    }
    catch (std::overflow_error& e)
    {
        std::cout << e.what() << "\n";
    }

    numerator = a;
    denominator = b;

}

Fraction::Fraction(float a) // 1/a
{
    try {
        float i = intDivideEx(1, a);
    }
    catch (std::overflow_error& e)
    {
        std::cout << e.what() << "\n";
    }
    numerator = 1;
    denominator = a;
}

Fraction::Fraction(const Fraction& f)
{
    numerator = f.numerator;
    denominator = f.denominator;
}


//methods
void Fraction::constructFraction()
{
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;

    do
    {
        std::cout << "Enter the denominator: ";
        std::cin >> denominator;

        if (denominator == 0)
            std::cout << "Denominator cannot be 0, divide by 0 error.\n";

    } while (denominator == 0);
}

void Fraction::display()
{
    std::cout << numerator << "/" << denominator << "\n";
}

Fraction Fraction::simplify()
{
    float a = getGCD(numerator, denominator);
    numerator = numerator / a;
    denominator = denominator / a;
    Fraction Fraction;
    Fraction.numerator = numerator;
    Fraction.denominator = denominator;
    return Fraction;
}

Fraction Fraction::addTwoFraction(Fraction f)
{
    Fraction result;
    result.numerator = numerator * f.denominator + f.numerator * denominator;
    result.denominator = f.denominator * denominator;

    return result;
}

Fraction Fraction::subtractTwoFraction(Fraction f)
{
    Fraction result;
    result.numerator = numerator * f.denominator - f.numerator * denominator;
    result.denominator = f.denominator * denominator;

    return result;
}

Fraction Fraction::productTwoFraction(Fraction f)
{
    Fraction result;

    result.numerator = f.numerator * numerator;
    result.denominator = f.denominator * denominator;

    return result;
}

Fraction Fraction::divideTwoFraction(Fraction f)
{
    Fraction result;
    result.numerator = numerator * f.denominator;
    result.denominator = denominator * f.numerator;

    return result;
}

bool Fraction::isSimplified()
{
    Fraction result(numerator, denominator);
    result.simplify();

    if (result.numerator == numerator && result.denominator == denominator)
        return true;
    return false;
}

void Fraction::findCommonDenominator(Fraction& f)
{
    Fraction temp(f);

    numerator *= f.denominator;
    denominator *= f.numerator;

    f.numerator = temp.numerator;
    f.denominator = temp.denominator;
}

bool Fraction::isPositive()
{
    if (numerator > 0 && denominator > 0)
        return true;
    return false;
}

bool Fraction::isNegative()
{
    if (numerator > 0 && denominator > 0)
        return false;
    return true;
}

int Fraction::compareFraction(const Fraction& f1)
{
    //3 case -1 0 1
    // if (-1) lhs < rhs
    // if (0) lhs = rhs
    // if (1) lhs > rhs

    Fraction temp2(f1);
    Fraction temp1(numerator, denominator);

    temp1.findCommonDenominator(temp2);
    if (temp1.numerator > temp2.numerator)
        return 1;
    else if (temp1.numerator == temp2.numerator)
        return 0;
    else
        return -1;

}

Fraction Fraction::operator+(const Fraction& f1)
{
    Fraction temp;
    temp.numerator = numerator * f1.denominator + denominator * f1.numerator;
    temp.denominator = denominator * f1.denominator;
    return temp;
}

Fraction Fraction::operator-(const Fraction& f1)
{
    Fraction temp;
    temp.numerator = numerator * f1.denominator - denominator * f1.numerator;
    temp.denominator = denominator * f1.denominator;
    return temp;
}

Fraction Fraction::operator*(const Fraction& f1)
{
    Fraction temp;
    temp.numerator = numerator + f1.numerator;
    temp.denominator = denominator + f1.denominator;
    return temp;
}

Fraction Fraction::operator/ (const Fraction& f1)
{
    Fraction temp;
    temp.numerator = numerator * f1.denominator;
    temp.denominator = denominator * f1.numerator;
    return temp;
}

Fraction Fraction::operator++()
{
    Fraction temp;
    temp = numerator + denominator;
    return temp;
}

Fraction Fraction::operator--()
{
    Fraction temp;
    temp = numerator - denominator;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Fraction& Fraction)
{
    os << Fraction.numerator << "/" << Fraction.denominator << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& Fraction)
{
    is >> Fraction.numerator;
    is >> Fraction.denominator;
    return is;
}