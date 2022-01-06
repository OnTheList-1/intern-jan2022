#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#include "bai82.h";
#include "bai83.h";
#include "bai84.h";
#include "bai85.h";
#include "bai88.h";
#include "bai92.h";
#include "bai95.h";
#include "bai104.h"
#include "bai110.h"
#include "bai111.h"
#include "bai112.h"
#include "bai113.h"

int main() {
    printf("bai 82: max(82, 12, 55) = %i; max(1, 0, 2) = %i; max (9123, 1283, 8383) = %i\n", maxNum(82, 15, 55), maxNum(1, 0, 2), maxNum(9123, 1283, 8383)); //bai 82

    printf("\nbai 83: nhap 2 so va kiem tra co bang dau hay khong.\n"); //bai 83
    std::cout << checkSign() << std::endl;

    printf("\nbai84: a = 1, b = 2 => x = %f \t a = 5, b = 11 = > x = %f\n", solveX(1, 2), solveX(5, 11)); //bai 84
    printf("bai 85: thang 1 = %i, ; thang 3 = %i ; thang 8 = %i, thang 12 = %i\n", checkQuarter(1), checkQuarter(3), checkQuarter(8), checkQuarter(12)); //bai85

    std::cout << "bai 88: "; //bai 88
    printAtoZ();

    printf("\nbai 92: gcd(5, 10) = %i; gcd(36, 60) = %i; gcd(36, 54) = %i\n", gcd(5, 10), gcd(36, 60), gcd(36, 54)); //bai 92

    printf("\nbai 95: \n"); //bai 95
    abs();

    printf("\nbai 104: 14/1/2020 has %i days; 1/3/2021 has %i days; 31/12/2021 has %i days\n", countDays(14, 1, 2020), countDays(1, 3, 2021), countDays(31, 12, 2021));

    printf("bai 110: \n");
    findChange();

    printf("\nBai 111: h = 4 \n\n");
    printTriangleA(4);
    std::cout << "\n";
    printTriangleB(4);
    std::cout << "\n";
    printTriangleC(4);
    std::cout << "\n";
    printTriangleD(4);
    std::cout << "\n";

    printf("\n\nBai 112: w = 7, l = 4\n\n");
    printRectangleA(7, 4);
    printRectangleB(7, 4);

    printf("\n\nBai113: sin(1.23) = %.5f, sin(0) = %.5f, sin(1.394) = %.5f\n", findSin(1.23), findSin(0), findSin(1.394));
    return 0;
}