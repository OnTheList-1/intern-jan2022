#include <iostream>
#include "chapter5.h"

int main() {
    std::cout << "---------- Chapter 5 ----------" << "\n\n";
    std::vector<int> intType;
    std::vector<float> floatType;
    std::cout << "Enter a vector containing int datatype: \n\n";
    insertVector(intType);
    std::cout << "\nEnter a vector containing float datatype: \n\n";
    insertVector(floatType);

    std::cout << "\nBai 115: \n"; //bai 115
    std::cout << "Answer: " << avgGrade() << "\n";

    std::cout << "\n\nBai 122:\n"; //bai 122
    std::cout << "Answer: " << maxNum(floatType);

    std::cout << "\n\nBai 123:\n"; //bai 123
    std::cout << "Answer: " << minNumPosition(floatType) << "\n";

    std::cout << "\nBai127: Sort\n"; //bai 127
    std::vector<float> copy = floatType;
    sortArr(copy);
    for (auto i : copy)
        std::cout << i << " ";

    std::cout << "\n\nBai 133\n"; //bai 133
    listPosNegativeNumber(floatType);

    std::cout << "\nBai 136: Find the position of the last positive number in an array. \n"; //bai136
    std::cout << "Last Position is " << findLastEvenNumber(intType) << "\n";

    std::cout << "\nBai 137:";
    std::cout << "\nLast Position is " << lastPerfectNumberPos(intType) << "\n"; //bai137

    std::cout << "\nBai 141: Find the position of the smallest positive number\n"; //bai 141
    std::cout << "Smallest positive number's position is: " << smallestPositiveNumberPos(floatType) << "\n";

    std::cout << "\nBai 150: Find the biggest negative number"; //bai 150
    std::cout << "\nBiggest negative number is " << biggestNegativeNumber(floatType) << "\n";

    std::cout << "\nBai 156: Find the closest value to X\n"; //bai 156
    std::cout << "Answer: " << closestMinX(floatType);

    std::cout << "\n\nBai 157: Print [a,b] in the array.\n"; //bai 157
    printRange(floatType); //print [3.5, 4] in the array

    std::cout << "\n\nBai 158: Find if the array contain X where X is the product of [x - 1] && [x + 1] \n"; //bai 162
    std::cout << "Answer: " << productNearby(intType) << "\n";

    std::cout << "\nBai 166: Find if the array contain elements whom value is 2^k\n"; //bai 166
    std::cout << "Answer: " << baseTwoInArray(intType) << "\n";

    std::cout << "\nBai 169: Find the biggest even number that is less than all of the odd numbers.\n"; //bai 169
    std::cout << "Answer: " << biggestEvenLessThanOdd(intType) << "\n";

    std::cout << "\nBai 173: \n"; // bai 173
    std::cout << "Answer: " << findLeastFrequency(intType) << "\n";

    std::cout << "\nBai 174: List all pairs in the array where a < b\n"; //bai 174
    listAllPairs(floatType);

    std::cout << "\n\nBai 175: Find two elements most closest in value.\n";
    listPairClosest(floatType);

    std::cout << "\nBai 180: list all numbers n in the array where: n < abs(-1); n > abs(+1)\n";
    bai180(floatType);
    std::cout << "\n\nBai 182: List all numbers that has at least one element next to it where the sign is different.\n";
    listDiffSign(floatType);

    std::cout << "\nBai 190: List all elements in the array where each of its digits are odd numbers.\n";
    listOddDigit(intType);

    std::cout << "\n\nBai 192: List all elements in the array where the first digit is an even number.\n";
    firstElementEven(intType);

    std::cout << "\n\nBai 195: List all 3 values in an array where a = b + c and a, b, c are distinct.\n";
    bai195(floatType);

    std::cout << "\n\nBai 202: Sum all numbers where their first digit is odd.\n";
    std::cout << "Answer: " << sumFirstDigitOdd(intType) << "\n";

    std::cout << "\nBai 207: Sum of all the extreme elements.\n";
    std::cout << "Answer: " << sumExtremeElement(floatType) << "\n";

    std::cout << "\nBai 215: Find average distance between all elements in the array.\n";
    std::cout << "Answer: " << findAvgDistanceBetweenElements(floatType);

    std::cout << "\nBai 221: Count the numbers of odd and even. [-1 even > odd; 0 odd == even; odd > even]\n";
    std::cout << "Answer: " << compareCountOddEven(intType) << "\n";

    std::cout << "\nBai 226: Count numbers of elements in which the one next to it is also even.\n";
    std::cout << "Answer: " << countNextToEven(intType) << "\n";

    std::cout << "\nBai 230: Count distinct elements and it's occurrences.";
    countDistinctElement(floatType);

    std::cout << "\nBai 231: List all unique elements in the array.\n";
    listDistinctElements(floatType);

    std::cout << "\nBai 236: Count the number of times A appears in B.\n";
    std::vector<float> floatTypeExample{ 10, 12, 12.2, 13, 15 };
    std::cout << "Answer: " << countAinB(floatType, floatTypeExample) << std::endl;

    std::cout << "\nBai 238: List the mode in the array.\n";
    listModeInArray(intType);

    std::cout << "\n\nBai 241: Consecutive Zeros\n";
    std::cout << "Answer: " << isConsecutiveZeros(intType) << "\n";

    std::cout << "\nBai 246: Symetrical Array\n";
    std::cout << "Answer : " << isSymetricalArray(floatType) << "\n";

    std::cout << "\nBai 249: Descending Array\n";
    std::cout << "Answer: " << isDescendingArray(floatType) << "\n";

    std::cout << "\nBai 256: Sort Array Descending\n";
    std::vector<float> copy256(floatType.begin(), floatType.end());
    sortArrayDescending(copy256);


    return 0;
}