#include <iostream>
#include <vector>

#include "Fraction.h"
#include "Triangle.h"
#include "Line.h"

int main()
{
    /*Fraction f1;
    Fraction f2;

    f1.constructFraction();
    f1.display();

    f2.constructFraction();
    f2.display();

    std::cout << "\n\n1. Simplification\n\n";
    Fraction simplify1 = f1.simplify();
    simplify1.display();

    std::cout << "\n\n2. Addition\n\n";
    Fraction addTwoFraction1 = f1.addTwoFraction(f2);
    addTwoFraction1.display();

    std::cout << "\n\n3. Subtraction\n\n";
    Fraction subtractTwoFraction1 = f1.subtractTwoFraction(f2);
    subtractTwoFraction1.display();

    std::cout << "\n\n4. Product\n\n";
    Fraction productTwoFraction1 = f1.productTwoFraction(f2);
    productTwoFraction1.display();

    std::cout << "\n\n5. Division\n\n";
    Fraction divideTwoFraction1 = f1.divideTwoFraction(f2);
    divideTwoFraction1.display();

    std::cout << "\n\n6. Check if fraction is in its simplest form.\n\n";
    std::cout << "Fraction 1: " << f1.isSimplified() << "\n";
    std::cout << "Fraction 2: " << f2.isSimplified() << "\n";

    std::cout << "\n\n7. Reduce to common denominator.\n\n";
    Fraction rf1(f1);
    Fraction rf2(f2);
    rf1.findCommonDenominator(rf2);
    rf1.display();
    rf2.display();

    std::cout << "\n\n8. Check if fraction is positive.\n\n";
    std::cout << "Fraction 1: " << f1.isPositive() << "\n";
    std::cout << "Fraction 2: " << f2.isPositive() << "\n";

    std::cout << "\n\n9. Compare 2 fractions.\n\n";
    std::cout << "Answer: " << f1.compareFraction(f2);

    std::cout << "\n\n10. Operator+\n\n";
    Fraction bai10;
    bai10 = f1 + f2;
    bai10.display(); */

    /*Triangle Triangle;

    Triangle.constructTriangle();
    Triangle.displayTriangle();

    std::cout << "\n\n1. Is a triangle.\n";
    std::cout << "Answer: " << Triangle.isTriangle();
    std::cout << "\n\n2. Perimeter of the triangle\n";
    std::cout << "Answer: " << Triangle.findPerimeter();
    std::cout << "\n\n3. Area of the triangle\n";
    std::cout << "Answer: " << Triangle.findArea();
    std::cout << "\n\n4. Find the center coordinate that lies in the middle of the triangle.\n";
    Triangle.centerCoordinate();
    std::cout << "\n\n5. Widest x-coord\n";
    Triangle.widestCoordinateonX();
    std::cout << "\n\n6. Widest y-coor\n";
    Triangle.widestCoordinateonY();
    std::cout << "\n7. check if the point lie in the triangle\n";
    std::cout << Triangle.isInTriangle(1, 2);
    std::cout << "\n8.Type of triangle\n";
    std::cout << Triangle.typeOfTriangle();
    */

    int size = 0;
    std::cout << "Enter the number of Lines: ";
    std::cin >> size;

    std::vector<Line> lineVector(size);

    for (int i = 0; i < size; ++i)
        std::cin >> lineVector[i];

    std::cout << "\n1. Are the lines parallel to each other.\n";
    bool checkParallel = false;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (!lineVector[i].isParallel(lineVector[j]))
            {
                std::cout << "They are not all parallel to each other.\n";
                checkParallel = true;
                break;
            }
        }
        if (checkParallel == true)
            break;
    }

    std::cout << "\n2. Are there at least one pair of line that are parallel to each other.\n";
    checkParallel = false;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (lineVector[i].isParallel(lineVector[j]))
            {
                std::cout << "There exist at least a pair that are parallel to each other.\n";
                checkParallel = true;
                break;
            }
        }
        if (checkParallel == true)
            break;
    }

    std::cout << "\n3. Check if any line overlap each other\n";
    bool checkOverlap = false;
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (lineVector[i].isOverlap(lineVector[j]))
            {
                std::cout << "There exist at least a pair that overlap each other.\n";
                checkOverlap = true;
                break;
            }
        }
        if (!checkOverlap)
            break;
    }



    return 0;
}