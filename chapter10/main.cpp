#include <iostream>
#include <vector>

#include "chapter10.h"


int main()
{
    std::vector<int> vectorInt{ 1, 9, 3, 5, 5, 2, 3, 5, 7, 1, 2, 4, 6, 10,82, 83 };
    std::vector<float> vectorFloat{ 1.2f, -1.4f, 6.3f, 4.2f, 7.4f, -9.2f, -9.5f, -10.5f, 13.0f, 12.0f, 13.1f, -1.f };
    int count = 0;

    std::cout << "Sum from 1 - 10: " << sumInteger(10) << "\n";
    std::cout << "Factorial 10!: " << factorial(10) << "\n";
    std::cout << "Count even numbers: " << countEven(vectorInt, 0) << "\n";
    std::cout << "Count positive numbers: " << countPositiveInReal(vectorFloat, 0) << "\n";
    std::cout << "Fibonacci(n) " << fibonacci(5) << "\n";
    std::cout << "Bai 710: " << sumBai710(5, 5) << "\n";
    std::cout << "Print Vector: " << std::endl;
    printVector(vectorInt, 0);
    std::cout << "\nPrint Vector Reverse: " << std::endl;
    printVectorReverse(vectorInt, vectorInt.size() - 1);
    std::cout << "\nSum of the vector: " << sumOfVectorInt(vectorInt, 0);
    std::cout << "\nSum of positive numbers in the vector: " << sumOfPositiveFloat(vectorFloat, 0);
    std::cout << "\nThe largest number in the vector: " << largestNumber(vectorInt, 0) << "\n";
    std::cout << "Index of the largest number in the vector: " << indexLargestNumber(vectorFloat, 0);
    std::cout << "\nSorted array: ";
    sortArray(vectorInt, 0);
    std::cout << "S(n) = 1 ^ 2 + 2 ^ 2 + 3 ^ 2 + ... + n ^ 2: " << sumNSquare(5);
    std::cout << "\nS(n) = 1/2 + 1/4 + ... 1 /n: " << sumFractionN(5);
    std::cout << "\nS(n) = 1 + 1/3 + 1/5 + ... + 1/(2n + 1): " << sumBai734(5);
    std::cout << "\nS(n) = 1 / (1 * 2) + 1 / (2 * 3) + ... + 1 / (n * (n + 1)): " << sumBai735(5, 1);
    std::cout << "\nS(n) = x^n: " << xPowN(2, 5);
    std::cout << "\nS(n) = x + x^2 + x^3 + ... + x^n: " << sumPower(2, 5);
    std::cout << "\nFind GCD largest odd: " << gcd(100, 100);
    std::cout << "\nS(n) = Bai 748: " << sumBai748(5);
    std::cout << "\nS(n) = Bai 751: " << sumBai751(5); //
    std::cout << "\nCount the digits: " << countDigit(234443);
    std::cout << "\nProduct of the digit: " << productDigit(3229);
    std::cout << "\nFirst digit of n: " << firstDigit(195132);
    std::cout << "\nReverse of integer n: " << reverseN(92034, 0);

    return 0;
}