#pragma once
#include <vector>

//Get user's input
template <typename T>
void insertVector(std::vector<T>& a) {
    int arrayLength = 0;
    std::cout << "Array Length: ";
    std::cin >> arrayLength;

    a.resize(arrayLength);

    for (int i = 0; i < arrayLength; ++i) {
        std::cin >> a[i];
    }
};

//print
template <typename T>
void printVector(std::vector<T>& a)
{
    if (a.empty())
        std::cout << "This is an empty vector.\n";
    else
        for (auto i : a)
            std::cout << i << " ";
};

/*              Helper              */
bool isOdd(const int& a);

/*              INTERFACE           */

float avgGrade(void); //bai 115
float maxNum(std::vector<float>&); //bai 122
int minNumPosition(const std::vector<float>&);//bai 123
void sortArr(std::vector<float>&); //bai 127
void listPosNegativeNumber(const std::vector<float>&); //bai 133
int findLastEvenNumber(const std::vector<int>&); //bai 136
int lastPerfectNumberPos(const std::vector<int>&); //bai 139
int smallestPositiveNumberPos(const std::vector<float>&); //bai141
float biggestNegativeNumber(const std::vector<float>&); //bai 150
int closestMinX(const std::vector<float>&); //bai 156
void printRange(const std::vector<float>&); //bai 157
int productNearby(const std::vector<int>&); //bai 162
int baseTwoInArray(const std::vector<int>&); //bai 166
int biggestEvenLessThanOdd(const std::vector<int>&); //bai 169
int findLeastFrequency(const std::vector<int>&); //bai 173
void listAllPairs(std::vector<float>); //bai 174
void listPairClosest(const std::vector<float>&); //bai 175
void bai180(const std::vector<float>& array); //bai 180
void listDiffSign(const std::vector<float>&); //bai 182
void listOddDigit(const std::vector<int>&); //bai 190
void firstElementEven(const std::vector<int>&); //bai 192
void bai195(const std::vector<float>&); //bai 195
int sumFirstDigitOdd(const std::vector<int>&); // bai 202
float sumExtremeElement(const std::vector<float>&); //bai 207
float findAvgDistanceBetweenElements(const std::vector<float>&); //bai 215
int compareCountOddEven(const std::vector<int>&); //bai 221
int countNextToEven(const std::vector<int>&); // bai 226
void countDistinctElement(const std::vector<float>&); //bai 230
void listDistinctElements(const std::vector<float>&); //bai 231