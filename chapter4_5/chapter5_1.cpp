#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <iostream>
#include <unordered_set>
#include <unordered_map>


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
void printArray(T* array, const int& size)
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
    float decimal = a - (float)integer;
    if (decimal < 0.5) {
        return std::floor(a);
    }

    return std::ceil(a);
}

template <typename T>
bool isAscending(T* array, const int& size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (array[i] > array[i + 1])
            return false;
    }
    return true;
}

int countAinB(const std::vector<float>& array1, const std::vector<float>& array2) // needs fix
{
    int count = 0;
    for (int i = 0; i < array2.size(); ++i)
    {
        if (array1[0] == array2[i] && array2.size() - i >= array1.size())
        {
            int start = i;
            bool flag = true;
            for (int j = 0; j < array1.size(); ++j)
            {
                if (array1[j] != array2[start])
                {
                    flag = false;
                    break;
                }
                ++start;
            }
            if (flag == true)
                ++count;

        }
    }
    return count;
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
        if (i % 2 == 1)
        {
            for (int j = i + 2; j < array.size(); ++j)
            {
                if (array[i] > array[j])
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

    int i = 0;
    while (i < size)
    {

        if (array[i] == k)
        {
            for (int j = i; j < size - 1; ++j)
                array[j] = array[j + 1]; //shift down

            --size;

        }
        else
        {
            ++i;
        }

    }

    printArray(array, size);
}

void deleteEvenNumbers(int* array, int& size) //needs fix
{
    int i = 0;
    while (i < size)
    {
        if (array[i] % 2 == 0)
        {
            for (int j = i; j < size - 1; ++j)
                array[j] = array[j + 1];
            --size;
        }
        else {
            ++i;
        }
    }

    printArray(array, size);
}

void deleteDuplicates(int* array, int& size)
{
    std::unordered_set<int> s;
    for (int i = 0; i < size; ++i) // unique elements in set
        s.insert(array[i]);

    int index = 0;
    for (const auto& itr : s) {
        array[index] = itr;
        ++index;
    }

    size = (int)s.size();

    printArray(array, size);
};

void sortBai281(int* array, const int& size) // needs fix
{
    int lastPositiveIndex = 0;
    for (int i = 0; i < size; ++i) // move even number to start of the array
    {
        if (array[i] % 2 == 0 && array[i] != 0)
        {
            int temp = array[i];
            for (int j = i; j > 0; --j)
                array[j] = array[j - 1];

            array[0] = temp;
        }
    }

    for (int i = 0; i < size; ++i) //find last positive index
    {
        if (array[i] % 2 != 0)
        {
            lastPositiveIndex = i;
            break;
        }
    }

    for (int i = 0; i < size; i++) //move 0 to last positive number's index
    {
        if (array[i] == 0)
        {
            for (int j = i; j > lastPositiveIndex; --j)
                array[j] = array[j - 1];

            array[lastPositiveIndex] = 0;
        }
    }

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
    for (int i = 0; i < size - 1; ++i)
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

    for (int i = 0; i < size - k; ++i)
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
            if (temp > 1 && isAscending(ascendingArray, temp) == true)
                printArray(ascendingArray, temp);
        }
    }
}

void subsetSumM(int* array, const int& size, const int& sum)
{
    std::vector<int> subset;
    bool flag = false;
    for (int i = 0; i < size; ++i)
    {
        if (flag == true) {
            printVector(subset);
            break;
        }
        int cSum = array[i];

        if (cSum < sum) {
            subset.push_back(array[i]);
            for (int j = i + 1; j < size; ++j)
            {
                if (cSum == sum) {
                    flag = true;
                    break;
                }
                if (cSum < sum) {
                    cSum += array[j];
                    subset.push_back(array[j]);
                }
                if (cSum > sum)
                    subset.clear();
            }
        }
        if (cSum == sum && subset.empty()) {
            subset.push_back(sum);
            printVector(subset);
        }
    }
}

void positiveSubsetLargestSum(int* array, const int& size)
{
    std::vector<int> subset;
    std::map<int, std::vector<int>> u_map;

    int indexV = 0;

    for (int i = 0; i < size; ++i)
    {
        if (array[i] >= 0)
        {
            subset.push_back(array[i]);
            int cSum = array[i];

            for (int j = i + 1; j < size; ++j)
            {
                if (array[j] < 0) {
                    //u_map.emplace(std::make_pair(cSum, subset));
                    //subset.clear();
                    break;
                }

                if (array[j] >= 0 && subset.size() <= size)
                {
                    cSum += array[j];
                    subset.push_back(array[j]);

                }
            }
            u_map.emplace(std::make_pair(cSum, subset));
            subset.clear();
        }
        else
            subset.clear();
    }

    auto lastIndex = u_map.rbegin();

    printVector((*lastIndex).second);
}

void createArrayBai309(float* array, const int& size)
{
    float* result = new float[size];

    for (int i = 1; i < size - 1; ++i)
    {
        if (i == 1)
            result[0] = array[0] + array[1];

        result[i] = array[i - 1] + array[i + 1];
    }

    result[size - 1] = array[size - 1] + array[size - 2];

    printArray(result, size);


}