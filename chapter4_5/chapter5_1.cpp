#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <iostream>

#include "chapter5_1.h"
#include "chapter5.h"

//  helper  //

bool isOdd(const std::string& fString)
{
    bool decimal = false;
    for (int i = (int)fString.length() - 1; i >= 0; i--) {

        if (fString[i] == '0' && decimal == false)
            continue;

        if (fString[i] == '.') {
            decimal = true;
            continue;
        }

        if ((fString[i] - '0') % 2 == 1)
            return true;

        return false;
    }

    return false;
}

template <typename T>
void printArray(T* array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

template <typename T>
void getUserInput(T& input)
{
    std::cin >> std::ws;
    std::cin >> input;
}

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

float roundFloat(float& a)
{
    int integer = (int)a;
    float getDecimal = a - (float)integer;
    if (getDecimal < 0.5) {
        return std::floor(getDecimal + integer);
    }

    return std::ceil(getDecimal + integer);
}

template <typename T>
bool checkAscending(T* array, const int& size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] > array[i + 1])
            return true;
    }
    return false;
}

int countAinB(const std::vector<float>& array1, const std::vector<float>& array2)
{
    if (array1.size() > array2.size())
        return 0;

    std::map<float, int> m;
    int countMin = -1;

    for (int i = 0; i < array2.size(); ++i)
    {
        for (int j = 0; j < array1.size(); ++j)
        {
            if (array1[j] == array2[i])
                m[array1[j]]++;
        }
    }

    for (const auto& itr : m)
    {
        if (countMin < 0)
            countMin = itr.second;
        countMin = std::min(countMin, itr.second);
    }

    return countMin;
}

void listModeInArray(const std::vector<int>& array)
{
    int occurrence = 0;
    std::map<int, int> m;

    for (int i = 0; i < array.size(); ++i)
        m[array[i]]++;

    for (const auto& itr : m)
    {
        occurrence = std::max(occurrence, itr.second);
    }

    for (const auto& itr1 : m)
    {
        if (itr1.second == occurrence)
            std::cout << itr1.first << " ";
    }
}

bool isConsecutiveZeros(const std::vector<int>& array)
{
    for (int i = 0; i < array.size() - 1; ++i)
    {
        if (array[i] == 0 && array[i + 1] == 0)
            return true;
    }

    return false;
}

bool isSymetricalArray(const std::vector<float>& array)
{
    for (int i = 0; i < array.size() / 2; ++i)
    {
        if (array[i] != array[array.size() - i - 1])
            return false;
    }
    return true;

}

bool isDescendingArray(const std::vector<float>& array)
{
    for (int i = 1; i < array.size(); ++i)
    {
        if (array[i] > array[i - 1])
            return false;
    }

    return true;
}

void sortArrayDescending(std::vector<float>& array)
{
    sort(array.begin(), array.end(), std::greater <>());
    printVector(array);
}

void sortArrayOddAscending(std::vector<float>& array)
{
    int positionOdd = 0;

    for (int i = 0; i < array.size(); ++i)
    {
        if (isOdd(std::to_string(array[i])) == true)
        {
            for (int j = i + 1; j < array.size(); ++j)
            {
                if (array[i] > array[j] && isOdd(std::to_string(array[j])) == true)
                {
                    float temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }

    }
    printVector(array);
}

void sortArrayPositiveAscending(std::vector<float>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] > 0)
        {
            for (int j = i + 1; j < array.size(); ++j)
            {
                if (array[i] > array[j] && array[j] > 0)
                {
                    float temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
    printVector(array);
}

void sortArrayBai263(std::vector<float>& array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        if (array[i] > 0)
        {
            for (int j = i + 1; j < array.size(); ++j)
            {
                if (array[j] > 0 && array[i] > array[j])
                {
                    float temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        if (array[i] < 0)
            for (int k = i + 1; k < array.size(); ++k)
            {
                if (array[k] < 0 && array[i] < array[k])
                {
                    float temp = array[i];
                    array[i] = array[k];
                    array[k] = temp;
                }
            }
    }
    printVector(array);
}

void insertAtK(int* array, int size, const int& k)
{
    int x = 0;
    getUserInput(x);

    for (int i = size; i > k; --i)
    {
        array[i] = array[i - 1];
    }
    array[k] = x;
    ++size;

    printArray(array, size);
}

void sortWhileInsert(float* array, const int& size)
{
    for (int i = 0; i < size; ++i)
    {
        float data = 0;
        getUserInput(data);
        array[i] = data;
        for (int j = 0; j < i; ++j)
        {
            if (array[i] > array[j])
            {
                float temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    printArray(array, size);
}

void deleteAllK(float* array, int& size, const float& k)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] == k)
        {
            for (int j = i; j < size - 1; ++j)
                array[j] = array[j + 1]; //shift left
            --size;
        }
    }

    printArray(array, size);
}

void deleteEvenNumbers(int* array, int& size)
{
    for (int i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 0)
        {
            for (int j = i; j < size - 1; ++j)
                array[j] = array[j + 1];
            --size;
        }
    }

    printArray(array, size);
}

void deleteDuplicates(int* array, int& size)
{
    std::map<int, int> m;
    for (int i = 0; i < size; ++i) // unique elements in map
        m[array[i]]++;

    int index = 0;
    for (const auto& itr : m) {
        array[index] = itr.first;
        ++index;
    }

    size = (int)m.size();

    printArray(array, size);
};

void sortBai281(int* array, const int& size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        for (int j = (size - 1) / 2; j >= 0; --j)
        {
            if (array[j] % 2 == 0 && array[i] % 2 == 1 && array[j] != 0)
                swap(array[i], array[j]);

        }
    }

    //deal with zero

    printArray(array, size);
}

void reverseArray(int* array, const int& size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        swap(array[i], array[size - i - 1]);
    }

    printArray(array, size);
}

void reverseEvenPosition(int* array, const int& size)
{
    for (int i = 0; i < size / 2; ++i)
    {
        if (array[i] % 2 == 0 || array[size - i - 1] % 2 == 0)
            swap(array[i], array[size - i - 1]);
    }

    printArray(array, size);
}

void rotateArray(int* array, const int& size)
{
    int first = array[0];
    for (int i = 0; i < size; ++i)
    {
        array[i] = array[i + 1];
    }
    array[size - 1] = first;

    printArray(array, size);
}

void rotateArrayKTimes(int* array, const int& size, const int& k)
{
    std::vector<int> position;
    for (int i = 0; i < k; ++i)
    {
        position.push_back(array[i]); //fix
    }

    for (int i = 0; i < size; ++i)
    {
        array[i] = array[i + k];
    }

    for (int i = 0; i < k; ++i)
    {
        array[size - i - 1] = position[k - i - 1];
    }

    printArray(array, size);

}

void printBai289(const int* array, const int& size)
{
    std::cout << "\nPrint Even: ";
    for (int i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 0)
            std::cout << array[i] << " ";
    }

    std::cout << "\nPrint Odd: ";
    for (int i = 0; i < size; ++i)
    {
        if (array[i] % 2 == 1)
            std::cout << array[i] << " ";
    }
    std::cout << "\n";
}

void arrayToInt(float* array, const int& size)
{
    for (int i = 0; i < size; ++i)
        array[i] = roundFloat(array[i]);

    printArray(array, size);
}

void listArraySubset(int* array, const int& size)
{
    for (int i = 0; i < (int)std::pow(size, 2) - 1; ++i)
    {
        std::cout << "{ ";
        for (int j = 0; j < size; ++j)
        {
            if ((i & (1 << j)) != 0)
                std::cout << array[j] << " ";
        }
        std::cout << "}\n";
    }
}

void listSubsetAscending(int* array, const int& size)
{
    int ascendingArray[100];

    for (int i = 0; i < size; ++i)
    {
        for (int j = 1; j <= size; ++j)
        {
            int temp = 0;
            for (int k = i; k < j; ++k)
            {
                ascendingArray[temp] = array[k];
                ++temp;
            }
            if (checkAscending(ascendingArray, temp) == false && temp > 1)
                printArray(ascendingArray, temp);
        }
    }
}