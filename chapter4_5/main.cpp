#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <array>
#include <map>

#include "Header1.h"

template <typename T>
T* buildArray(T* arr, int& arrayLength) //helper
{
    int i = 0;

    std::cout << "Array Size: ";
    std::cin >> arrayLength;

    arr = new T[arrayLength];

    do
    {
        std::cin >> arr[i++];
    } while (i < arrayLength);

    return arr;
}

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
    float* arr = new float;
    arr = buildArray(arr, arrLength);

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
    float* arr = new float;
    arr = buildArray(arr, arrLength);
    int position = 0;

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
    float* arr = new float;
    arr = buildArray(arr, arrLength);

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

void listPosNegativeNumber(void) //bai133
{
    std::vector<int> negativePos;
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);


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
    int* arr = new int;
    arr = buildArray(arr, arrLength);

    for (int i = arrLength - 1; i >= 0; --i)
    {
        if (arr[i] % 2 == 0)
            return ++i;
    }
    return -1;
}

int lastPerfectNumberPos(void) //bai139
{
    int arrLength = 0;
    std::vector<int> perfectNumberVec;
    int perfectNumber = 0;

    int* arr = new int;
    arr = buildArray(arr, arrLength);

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

int smallestPositiveNumberPos(void) //bai 141
{
    int arrLength = 0;

    float* arr = new float;
    arr = buildArray(arr, arrLength);

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
    return -1; //hmmmm
}

float biggestNegativeNumber(void)
{
    int arrLength = 0;

    float* arr = new float;
    arr = buildArray(arr, arrLength);

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

float closestMinX(void)
{
    int arrLength = 0;
    float x = 0;
    bool sign;

    float* arr = new float;
    arr = buildArray(arr, arrLength);

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

void printRange(float a, float b)
{
    int arrayLength = 0;

    float* arr = new float;
    arr = buildArray(arr, arrayLength);

    for (int i = 0; i < arrayLength; ++i) {
        if (arr[i] >= a && arr[i] <= b)
            std::cout << arr[i] << " ";
    }

}

bool productNearby(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);

    for (int i = 1; i < arrLength - 1; ++i)
    {
        if (arr[i - 1] * arr[i + 1] == arr[i])
            return true;
    }
    std::cout << "\nAnswer: ";
    return false;

}

int baseTwoInArray(void)
{
    int arrLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrLength);

    for (int i = 0; i < arrLength; ++i)
    {
        int n = (arr[i] < 0) ? -arr[i] : arr[i];
        bool check = true;
        while (n > 1) {
            if (n % 2 != 0)
                check = false;
            n /= 2;
        }
        if (check == true) {
            std::cout << "\nAnswer: ";
            return n;
        }

    }
    std::cout << "\nAnswer: ";
    return -1;
}

int biggestEvenLessThanOdd(void) //bai 169
{
    int arrLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrLength);

    int minOdd = arr[0];

    for (int i = 0; i < arrLength; ++i) //find min odd
    {
        if (arr[i] % 2 != 0)
            minOdd = std::max(arr[i], minOdd);
    }

    for (int i = 0; i < arrLength; ++i)
    {
        if (arr[i] % 2 == 0 && arr[i] < minOdd)
            return arr[i];
    }

    return -1;
}

int findLeastFrequency(void)
{
    int arrayLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrayLength);
    std::vector<int> v(10, 0);

    for (int i = 0; i < arrayLength; ++i)
    {
        int temp = arr[i];
        while (temp > 0)
        {
            ++v[temp % 10];
            temp /= 10;
        }
    }

    int leastOccurrence = v[arr[0] % 10]; //get existing element where > 0
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] != 0)
            leastOccurrence = (v[leastOccurrence] < v[i]) ? leastOccurrence : i;
    }

    std::cout << "\nAnswer: ";
    return leastOccurrence;


}

void listAllPairs(void)
{
    int arrLength = 0;
    float* arr = new float;

    arr = buildArray(arr, arrLength);

    if (arrLength % 2 == 0)
    {
        std::vector<std::vector<float>> result(arrLength / 2);
        //sort array first
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

        for (int i = 0; i < arrLength / 2; ++i)
        {
            result[i].push_back(arr[i]);
            result[i].push_back(arr[arrLength - i - 1]);
        }

        std::cout << "\nAnswer: ";

        for (int i = 0; i < result.size(); ++i)
        {
            std::cout << "(" << result[i][0] << ", " << result[i][1] << ") ";
        }

    }
    else
    {
        std::cout << "Array has 1 element that can't be pair up.\n";
    }
}

void listPairClosest(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);

    float minDistance = abs(arr[1] - arr[0]);
    std::vector<int> distancePairs;

    //find min distance
    for (int i = 0; i < arrLength; ++i)
    {
        for (int j = i + 1; j < arrLength - 1; ++j)
        {
            if (abs(arr[i] - arr[j]) < minDistance)
                minDistance = abs(arr[i] - arr[j]);
        }

    }

    //map min with min distance
    for (int i = 0; i < arrLength; ++i)
    {
        for (int j = i + 1; j < arrLength - 1; ++j)
        {
            if (minDistance == abs(arr[i] - arr[j]))
                std::cout << "\nAnswer: (" << arr[i] << ", " << arr[j] << ")\n";
        }
    }
}

void bai180(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);

    std::cout << "Answer: ";

    for (int i = 1; i < arrLength - 1; ++i)
    {
        if (arr[i] < abs(arr[i - 1]) && arr[i] > abs(arr[i + 1]))
            std::cout << arr[i] << " ";
    }

}

void listDiffSign(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);

    std::cout << "Answer: ";

    for (int i = 1; i < arrLength - 1; ++i)
    {
        if (arr[i] > 0)
        {
            if (arr[i - 1] < 0 || arr[i + 1] < 0)
                std::cout << arr[i] << " ";
        }
        if (arr[i] < 0)
        {
            if (arr[i - 1] > 0 || arr[i + 1] > 0)
                std::cout << arr[i] << " ";
        }
    }
}

void listOddDigit(void)
{
    int arrLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrLength);

    std::cout << "\nAnswer: ";

    for (int i = 0; i < arrLength; ++i)
    {
        bool checkOdd = true;
        int copy = arr[i];
        while (copy > 0)
        {
            if (copy % 10 % 2 == 0)
                checkOdd = false;

            copy /= 10;
        }
        if (checkOdd == true)
            std::cout << arr[i] << " ";

    }
}

void firstElementEven(void)
{
    int arrayLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrayLength);

    std::cout << "\nAnswer: ";

    for (int i = 0; i < arrayLength; ++i)
    {
        bool checkEven = false;
        int copy = arr[i];

        while (copy > 0) {
            if (copy % 2 == 0)
                checkEven = true;
            else
                checkEven = false;

            copy /= 10;
        }
        if (checkEven == true)
            std::cout << arr[i] << " ";
    }

}

void bai195(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);

    std::cout << "\nAnswer: ";

    for (int i = 0; i < arrLength; ++i)
    {
        for (int k = 0; k < arrLength; ++k)
        {
            for (int j = 0; j < arrLength; ++j)
            {
                if (arr[j] == arr[i] + arr[k])
                    std::cout << "(" << arr[j] << ", " << arr[i] << ", " << arr[k] << ")";
            }
        }
    }
}

void sumFirstDigitOdd(void)
{
    int arrLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrLength);
    int sum = 0;

    for (int i = 0; i < arrLength; ++i)
    {
        bool checkOdd = false;
        int copy = arr[i];

        while (copy > 0) {
            if (copy % 2 == 1)
                checkOdd = true;
            else
                checkOdd = false;

            copy /= 10;
        }
        if (checkOdd == true)
            sum += arr[i];
    }
    std::cout << "\nAnswer: " << sum;
}

void sumExtremeElement(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);
    float sum = 0;

    for (int i = 1; i < arrLength - 1; ++i)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            sum += arr[i];
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1])
            sum += arr[i];
    }

    std::cout << "\nANswer: " << sum;
}

void findAvgDistanceBetweenElements(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);
    float avg = 0;

    for (int i = 1; i < arrLength; ++i)
    {
        avg += abs(arr[i] - arr[i - 1]);
    }

    avg /= arrLength - 1;

    std::cout << "\nAnswer: " << avg << "\n";
}

int compareCountOddEven(void)
{
    int arrLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrLength);
    int countOdd = 0;
    int countEven = 0;

    for (int i = 0; i < arrLength; ++i)
    {
        if (arr[i] % 10 % 2 == 0)
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

void countNextToEven(void)
{
    int arrLength = 0;
    int* arr = new int;
    arr = buildArray(arr, arrLength);
    int countEven = 0;

    for (int i = 0; i < arrLength - 1; ++i)
    {
        if (arr[i] % 10 % 2 == 0 && arr[i + 1] % 10 % 2 == 0)
            ++countEven;
    }
    std::cout << "\nAnswer: " << countEven << "\n";
}

void countDistinctElement(void) //bai 230
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);
    std::map<float, int> m;

    for (int i = 0; i < arrLength; ++i)
    {
        if (m.find(arr[i]) == m.end())
            m.insert(std::pair<float, int>(arr[i], 1));
        else
            ++m[arr[i]];
    }

    std::map<float, int>::iterator itr;

    std::cout << "\nAnswer: \n";

    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        std::cout << itr->first << " : " << itr->second << "\n";
    }

}

void listDistinctElements(void)
{
    int arrLength = 0;
    float* arr = new float;
    arr = buildArray(arr, arrLength);
    std::map<float, int> m;

    for (int i = 0; i < arrLength; ++i)
    {
        if (m.find(arr[i]) == m.end())
            m.insert(std::pair<float, int>(arr[i], 1));
        else
            ++m[arr[i]];
    }

    std::map<float, int>::iterator itr;

    for (itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second == 1)
            std::cout << itr->first << " ";

    }


}

int main() {
    std::cout << "Bai 115: \n"; //bai 115
    avgGrade();
    std::cout << "\n\nBai 122:\n"; //bai 122
    maxNum();
    std::cout << "\nBai 123:\n"; //bai 123
    minNumPos();
    std::cout << "\nBai127: Sort\n"; //bai 127
    sortArr();
    std::cout << "\n\nBai 133\n"; //bai 133
    listPosNegativeNumber();
    std::cout << "\n\nBai 136: Find the position of the last positive number in an array. \n"; //bai136
    std::cout << "Last Position is " << findLastEvenNumber() << "\n";
    std::cout << "\nBai 137: \n";
    std::cout << "\nLast Position is " << lastPerfectNumberPos() << "\n"; //bai137
    std::cout << "Bai 141: Find the position of the smallest positive number\n"; //bai 141
    std::cout << "Smallest positive number's position is " << smallestPositiveNumberPos() << "\n";
    std::cout << "\nBai 150: Find the biggest negative number\n"; //bai 150
    std::cout << "\nBiggest negative number is " << biggestNegativeNumber() << "\n";
    std::cout << "\nBai 156: Find the closest value to X\n"; //bai 156
    std::cout << closestMinX();
    std::cout << "\nBai 157: Print [a,b] in the array.\n"; //bai 157
    printRange(3.5, 4); //print [3.5, 4] in the array
    std::cout << "\n\nBai 158: Find if the array contain X where X is the product of [x - 1] && [x + 1] \n"; //bai 162
    std::cout << productNearby() << "\n";
    std::cout << "\nBai 166: Find if the array contain elements whom value is 2^k\n"; //bai 166
    std::cout << baseTwoInArray() << "\n";
    std::cout << "\nBai 169: Find the biggest even number that is less than all of the odd numbers.\n"; //bai 169
    std::cout << "\nAnswer: " << biggestEvenLessThanOdd() << "\n";
    std::cout << "\nBai 173: \n"; // bai 173
    std::cout << findLeastFrequency() << "\n";
    std::cout << "\nBai 174: List all pairs in the array where a < b\n"; //bai 174
    listAllPairs();
    std::cout << "\n\nBai 175: Find two elements most closest in value.\n";
    listPairClosest();
    std::cout << "\n\nbai 180: list all numbers n in the array where: n < abs(-1); n > abs(+1)\n\n";
    bai180();
    std::cout << "\nBai 182: List all numbers that has at least one element next to it where the sign is different.\n";
    listDiffSign();
    std::cout << "\nBai 190: List all elements in the array where each of its digits are odd numbers.\n";
    listOddDigit();
    std::cout << "\nBai 192: List all elements in the array where the first digit is an even number.\n";
    firstElementEven();
    std::cout << "\nBai 195: List all 3 values in an array where a = b + c and a, b, c are distinct.\n";
    bai195();
    std::cout << "\nBai 202: Sum all numbers where their first digit is odd.\n";
    sumFirstDigitOdd();
    std::cout << "\nBai 207: Sum of all the extreme elements.\n";
    sumExtremeElement();
    std::cout << "\nBai 215: Find average distance between all elements in the array.\n";
    findAvgDistanceBetweenElements();
    std::cout << "\nBai 221: Count the numbers of odd and even. [-1 even > odd; 0 odd == even; odd > even]\n";
    std::cout << "\nAnswer: " << compareCountOddEven() << "\n";
    std::cout << "\nBai 226: Count numbers of elements in which the one next to it is also even.\n";
    countNextToEven();
    std::cout << "Bai 230: Count distinct elements and it's occurrences.\n\n";
    countDistinctElement();
    std::cout << "Bai 231: List all unique elements in the array.\n";
    listDistinctElements();


    return 0;
}