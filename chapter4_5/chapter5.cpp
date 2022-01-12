#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <iostream>

#include "chapter5.h"

bool isOdd(const int& a)
{
    if (a % 2 == 1)
        return true;
    return false;
}

float avgGrade()
{ //bai 115
    std::string name = "";
    float gradeA = 0;
    float gradeB = 0;

    std::cout << "Ho va Ten: ";
    std::cin >> std::ws;
    std::getline(std::cin, name);

    std::cout << "Diem Toan: ";
    std::cin >> gradeA;

    std::cout << "Diem van:  ";
    std::cin >> gradeB;

    return (gradeA + gradeB) / 2;

};

float maxNum(std::vector<float>& array) // bai 122
{
    float max = array[0];

    for (int i = 1; i < array.size(); ++i)
    {
        if (max < array[i])
            max = array[i];

    }

    return max;

};

int minNumPosition(const std::vector<float>& array) //bai 123
{
    int position = 0;
    float min = array[0];

    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] < min)
        {
            min = array[i];
            position = i;
        }
    }
    return position;
};

void sortArr(std::vector<float>& array)
{
    //bubble sort

    for (int i = 0; i < array.size(); ++i)
    {
        for (int j = i + 1; j < array.size(); ++j)
        {
            if (array[i] > array[j])
            {
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }

        }
    }

    printVector(array);
}

void listPosNegativeNumber(const std::vector<float>& array) //bai133
{

    std::vector<int> negativePos;

    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] < 0)
            negativePos.push_back(i); //push index of neg numbers
    }

    printVector(negativePos);
};

int findLastEvenNumber(const std::vector<int>& array) //bai 136
{
    for (int i = static_cast<int> (array.size() - 1); i >= 0; --i)
    {
        if (array[i] % 2 == 0)
            return i;
    }
    return -1;
}

int lastPerfectNumberPos(const std::vector<int>& array) //bai139
{
    int perfectNumber = 0;

    for (int i = static_cast<int>(array.size() - 1); i >= 0; --i)
    {
        for (int j = 1; j < array[i]; ++j) {
            if (array[i] % j == 0)
                perfectNumber += j;
        }
        if (array[i] == perfectNumber)
            return i;
        perfectNumber = 0;
    }

    return -1;
}

int smallestPositiveNumberPos(const std::vector<float>& array) //bai 141
{
    float value = array[0]; //tracker
    int index = 0;

    //find smallest number
    for (int i = 0; i < array.size(); ++i)
    {
        if ((value > array[i] && array[i] > 0) || value < 0) {
            value = array[i];
            index = i;
        }
    }
    if (value < 0)
        return -1;

    return index;
}

float biggestNegativeNumber(const std::vector<float>& array) //bai 150
{
    float pos = array[0]; //tracker

    //find biggest negative number
    for (int i = 0; i < array.size(); ++i)
    {
        if ((pos < array[i] && array[i] < 0))
            pos = array[i];
    }
    if (pos > 0)
        return -1;

    return pos;
}

int closestMinX(const std::vector<float>& array) //bai 156
{
    float x = 0;
    int index = 0;

    std::cout << "Enter value for X: ";
    std::cin >> x;

    float distance = array[0];

    for (int i = 1; i < array.size(); ++i)
    {
        if (abs(array[i] - x) < distance) {
            distance = abs(array[i] - x);
            index = i;
        }
    }

    return index;
}

void printRange(const std::vector<float>& array)
{
    std::vector<float> copy(array.begin(), array.end());
    int max = copy[0];
    int min = copy[0];

    for (int i = 1; i < copy.size(); ++i)
    {
        if (max < copy[i])
            max = copy[i];
        if (min > copy[i])
            min = copy[i];
    }

    std::cout << "Min: " << min << "; Max = " << max << "\n";
}

int productNearby(const std::vector<int>& array)
{

    for (int i = 1; i < array.size() - 1; ++i)
    {
        if (array[i - 1] * array[i + 1] == array[i])
            return i;
    }

    return -1;

}

int baseTwoInArray(const std::vector<int>& array) //bai 166
{

    for (int i = 0; i < array.size(); ++i)
    {
        int n = (array[i] < 0) ? -array[i] : array[i];
        bool check = true;
        while (n > 1) {
            if (n % 2 != 0)
                check = false;
            n /= 2;
        }
        if (check == true) {
            return array[i];
        }
    }

    return 0;
}

int biggestEvenLessThanOdd(const std::vector<int>& array) //bai 169
{
    int minOdd = array[0];
    int biggest = -1;

    for (int i = 0; i < array.size(); ++i) //find min odd
    {
        if (array[i] % 2 != 0)
            minOdd = std::max(array[i], minOdd);
    }

    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] % 2 == 0 && array[i] < minOdd)
            biggest = std::max(array[i], biggest);
    }
    return biggest;
}

int findLeastFrequency(const std::vector<int>& array)
{
    std::vector<int> v(10, 0);

    for (int i = 0; i < array.size(); ++i)
    {
        int temp = array[i];
        while (temp > 0)
        {
            ++v[temp % 10];
            temp /= 10;
        }
    }

    int leastOccurrence = array[0] % 10; //get existing element where > 0
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] != 0)
            leastOccurrence = (v[leastOccurrence] < v[i]) ? leastOccurrence : i;
    }

    return leastOccurrence;
}

void listAllPairs(std::vector<float> array)
{
    if (array.size() % 2 == 0)
    {
        std::vector<float> result;
        //sort array first
        sortArr(array);

        for (int i = 0; i < array.size() - 1; ++i)
        {
            for (int j = i + 1; j < array.size(); ++j)
            {
                result.push_back(array[i]);
                result.push_back(array[j]);
            }
        }

        for (int i = 0; i < result.size() - 1; i += 2)
        {
            std::cout << "(" << result[i] << ", " << result[i + 1] << ") ";
        }

    }
    else
    {
        std::cout << "Array has 1 element that can't be pair up.\n";
    }
}

void listPairClosest(const std::vector<float>& array)
{
    float minDistance = abs(array[1] - array[0]);
    std::vector<int> distancePairs;
    int index0 = 1;
    int index1 = 0;

    //find min distance
    for (int i = 0; i < array.size(); ++i)
    {
        for (int j = i + 1; j < array.size(); ++j)
        {
            if (abs(array[i] - array[j]) < minDistance) {
                minDistance = abs(array[i] - array[j]);
                index0 = i;
                index1 = j;
            }

        }

    }

    std::cout << index0 << " " << index1;

    std::cout << "Answer: (" << array[index0] << ", " << array[index1] << ")\n";
}

void bai180(const std::vector<float>& array)
{
    std::cout << "Answer: ";

    for (int i = 1; i < array.size() - 1; ++i)
    {
        if (array[i] > array[i - 1] && array[i] < abs(array[i + 1]))
            std::cout << array[i] << " ";
    }
}

void listDiffSign(const std::vector<float>& array)
{
    for (int i = 1; i < array.size() - 1; ++i)
    {
        if (array[i] > 0)
        {
            if (array[i - 1] < 0 || array[i + 1] < 0)
                std::cout << array[i] << " ";
        }
        if (array[i] < 0)
        {
            if (array[i - 1] > 0 || array[i + 1] > 0)
                std::cout << array[i] << " ";
        }
    }
}

void listOddDigit(const std::vector<int>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        bool checkOdd = true;
        int copy = array[i];
        while (copy > 0)
        {
            checkOdd = isOdd(copy);
            copy /= 10;
        }
        if (checkOdd == true)
            std::cout << array[i] << " ";

    }
}

void firstElementEven(const std::vector<int>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        bool checkEven = false;
        int copy = array[i];

        while (copy > 0) {
            checkEven = isOdd(copy);
            copy /= 10;
        }
        if (checkEven == true)
            std::cout << array[i] << " ";
    }
}

void bai195(const std::vector<float>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        for (int k = 0; k < array.size(); ++k)
        {
            for (int j = 0; j < array.size(); ++j)
            {
                if (array[j] == array[i] + array[k])
                    std::cout << "(" << array[j] << ", " << array[i] << ", " << array[k] << ")";
            }
        }
    }
}

int sumFirstDigitOdd(const std::vector<int>& array)
{
    int sum = 0;

    for (int i = 0; i < array.size(); ++i)
    {
        bool checkOdd = false;
        int copy = array[i];

        while (copy > 0)
        {
            if (isOdd(copy) && copy < 10)
                checkOdd = isOdd(copy);
            copy /= 10;
        }

        if (checkOdd)
            sum += array[i];
    }
    return sum;
}

float sumExtremeElement(const std::vector<float>& array)
{
    float sum = 0;

    for (int i = 1; i < array.size() - 1; ++i)
    {
        if (array[i] > array[i - 1] && array[i] > array[i + 1])
            sum += array[i];
        if (array[i] < array[i - 1] && array[i] < array[i + 1])
            sum += array[i];
    }

    return sum;
}

float findAvgDistanceBetweenElements(const std::vector<float>& array)
{
    float avg = 0;
    int count = 0;
    for (int i = 0; i < array.size() - 1; ++i)
    {
        for (int j = i + 1; j < array.size(); ++j)
        {
            avg += abs(array[i] - array[j]);
            ++count;
        }
    }
    avg /= count;
    return avg;
}

int compareCountOddEven(const std::vector<int>& array)
{
    int countOdd = 0;
    int countEven = 0;

    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] % 2 == 0)
            ++countEven;
        else
            ++countOdd;
    }

    if (countEven == countOdd)
        return 0;
    if (countEven < countOdd)
        return 1;

    return -1;

}

int countNextToEven(const std::vector<int>& array)
{
    int countEven = 0;

    for (int i = 0; i < array.size() - 1; ++i)
    {
        if (array[i] % 2 == 0 && array[i + 1] % 2 == 0)
            ++countEven;
    }
    return countEven;
}

void countDistinctElement(const std::vector<float>& array) //bai 230
{
    std::map<float, int> m;

    for (int i = 0; i < array.size(); ++i)
    {
        m[array[i]]++;
    }

    std::map<float, int>::iterator itr;

    std::cout << "\nAnswer: \n";

    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        std::cout << itr->first << " : " << itr->second << "\n";
    }
}

void listDistinctElements(const std::vector<float>& array)
{
    std::map<float, int> m;

    for (int i = 0; i < array.size(); ++i)
    {
        m[array[i]]++;
    }

    std::map<float, int>::iterator itr;

    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second == 1)
            std::cout << itr->first << " ";

    }
}
