#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <array>

#include "Header1.h"

void avgGrade(void)
{ //bai 115
    std::string name = "";
    int gradeA = 0;
    int gradeB = 0;
    double avgGrade;

    std::cout << "Ho va Ten: ";
    std::getline(std::cin, name);

    std::cout << "Diem Toan: ";
    std::cin >> gradeA;

    std::cout << "Diem van:  ";
    std::cin >> gradeB;
    avgGrade = (gradeA + gradeB) / 2.0;
    std::cout << "\nDiem Trung Binh = " << avgGrade;

};

void maxNum(void) // bai 122
{
    int arrLength = 0;
    int i = 0;
    float* arr;

    std::cout << "Size array: ";
    std::cin >> arrLength;

    arr = new float[arrLength];

    do
    {
        std::cin >> arr[i];
        ++i;

    } while (i < arrLength);

    float max = arr[0];

    for (int i = 1; i < arrLength; ++i)
    {
        if (max < arr[i])
            max = arr[i];

    }
    std::cout << "The biggest number is: " << max << std::endl;

};

void minNumPos(void) //bai 123
{
    int arrLength = 0;
    int i = 0;
    float* arr;
    int position = 0;

    std::cout << "Size array: ";
    std::cin >> arrLength;

    arr = new float[arrLength];

    do
    {
        std::cin >> arr[i];
        ++i;

    } while (i < arrLength);

    float min = arr[0];

    for (int i = 0; i < arrLength; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            position = i;
        }
    }

    std::cout << "The position of the min number is:  " << ++position << std::endl;
};

void sortArr(void)
{
    int arrLength = 0;
    float* arr;
    int i = 0;
    std::cout << "Size Array: ";
    std::cin >> arrLength;

    arr = new float[arrLength];

    do
    {
        std::cin >> arr[i];
        ++i;
    } while (i < arrLength);

    //bubble sort

    for (int i = 0; i < arrLength; ++i)
    {
        for (int j = i + 1; j < arrLength; ++j)
        {
            if (arr[i] > arr[j])
            {
                float temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }

        }
    }

    for (int i = 0; i < arrLength; ++i)
    {
        std::cout << arr[i] << " ";
    }

}

void listPosNegativeNumber(void)
{
    int* arr = nullptr;
    std::vector<int> negativePos;
    int arrLength = 0;
    int i = 0;

    std::cout << "Array Size: ";
    std::cin >> arrLength;
    arr = new int[arrLength];

    do
    {
        std::cin >> arr[i++];
    } while (i < arrLength);

    for (int i = 0; i < arrLength; ++i)
    {
        if (arr[i] < 0)
            negativePos.push_back(i); //push index of neg numbers
    }

    if (negativePos.empty()) //check if empty
        negativePos.push_back(-1);

    for (auto i : negativePos)
    {
        std::cout << ++i << " ";
    }

};

int findLastEvenNumber(void) //bai 136
{
    int arrLength = 0;
    int i = 0;
    int* arr;

    std::cout << "Size array: ";
    std::cin >> arrLength;

    arr = new int[arrLength];

    do
    {
        std::cin >> arr[i];
        ++i;

    } while (i < arrLength);

    for (int i = arrLength - 1; i >= 0; --i)
    {
        if (arr[i] % 2 == 0)
            return ++i;
    }
    return -1;
}

int lastPerfectNumberPos(void)
{
    int arrLength = 0;
    int i = 0;
    std::vector<int> perfectNumberVec;
    int perfectNumber = 0;

    int* arr;

    std::cout << "Size array: ";
    std::cin >> arrLength;

    arr = new int[arrLength];

    do
    {
        std::cin >> arr[i++];

    } while (i < arrLength);

    for (int i = 0; i < arrLength; ++i)
    {
        for (int j = 1; j < arr[i]; ++j) {
            if (arr[i] % j == 0)
                perfectNumber += j;
        }
        if (arr[i] == perfectNumber)
            perfectNumberVec.push_back(perfectNumber);
        perfectNumber = 0;
    }

    if (!perfectNumberVec.empty()) {
        for (int i = 0; i < arrLength; ++i)
        {
            if (perfectNumberVec[perfectNumberVec.size() - 1] == arr[i])
                return ++i;
        }
    }

    return -1;
}

int smallestPositiveNumberPos(void)
{
    int arrLength = 0;
    int i = 0;

    std::cout << "Size array: ";
    std::cin >> arrLength;

    float* arr = new float[arrLength];

    do
    {
        std::cin >> arr[i++];

    } while (i < arrLength);

    float pos = arr[0]; //tracker

    //find smallest number
    for (int i = 0; i < arrLength; ++i)
    {
        if ((pos > arr[i] && arr[i] > 0) || pos < 0)
            pos = arr[i];
    }
    if (pos < 0)
        return -1;

    //find index
    for (int i = 0; i < arrLength; ++i)
    {
        if (pos == arr[i])
            return ++i;
    }
}

float biggestNegativeNumber(void)
{
    int arrLength = 0;
    int i = 0;

    std::cout << "Size array: ";
    std::cin >> arrLength;

    float* arr = new float[arrLength];

    do
    {
        std::cin >> arr[i++];

    } while (i < arrLength);

    float pos = arr[0]; //tracker

    //find biggest negative number
    for (int i = 0; i < arrLength; ++i)
    {
        if ((pos < arr[i] && arr[i] < 0))
            pos = arr[i];
    }
    if (pos > 0)
        return -1;

    return pos;
}

float closestMinX()
{
    int arrLength = 0;
    int i = 0;
    float x = 0;
    bool sign;

    std::cout << "Size Array: ";
    std::cin >> arrLength;

    float* arr = new float[arrLength];

    do
    {
        std::cin >> arr[i++];

    } while (i < arrLength);

    std::cout << "Enter value for X: ";
    std::cin >> x;

    float distance = arr[0];

    for (int i = 1; i < arrLength; ++i)
    {
        if (abs(arr[i] - x) < distance) {
            if (arr[i] - x < 0)
                sign = true;
            else
                sign = false;
            distance = abs(arr[i] - x);
        }
    }
    //check for arr[0]
    if (arr[0] - x >= distance)
        sign = false;

    return (sign) ? x - distance : distance + x;
}

int main() {
    //std::cout << "Bai 115: \n"; //bai 115
    //avgGrade();
    //std::cout << "\n\nBai 122:\n"; //bai 122
    //maxNum();
    std::cout << "\nBai 123:\n"; //bai 123
    minNumPos();
    std::cout << "\nBai127: Sort\n"; //bai 127
    sortArr();
    std::cout << "\n\nBai 133\n"; //bai 133
    listPosNegativeNumber();
    std::cout << "\nBai 136: Find the position of the last positive number in an array. \n"; //bai136
    std::cout << "Last Position is " << findLastEvenNumber() << "\n";
    std::cout << "\nBai 137: \n";
    std::cout << "\nLast Position is " << lastPerfectNumberPos() << "\n"; //bai137
    std::cout << "Bai 141: Find the position of the smallest positive number\n"; //bai 141
    std::cout << "Smallest positive number's position is " << smallestPositiveNumberPos() << "\n";
    std::cout << "Bai 150: Find the biggest negative number\n"; //bai 150
    std::cout << "Biggest negative number is " << biggestNegativeNumber() << "\n";
    std::cout << "Bai 156: Find the closest value to X\n"; //bai 156
    std::cout << closestMinX();

    return 0;
}