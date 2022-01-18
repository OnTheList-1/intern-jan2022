#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#include "chapter6.h"

//  HELPER  //
bool isPrime(const int& a)
{
    if (a == 2)
        return true;

    if (a == 0)
        return false;

    if (abs(a) == 1)
        return false;

    for (int i = 2; i < a; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}

template <typename T>
void displayMatrix(std::vector<std::vector<T>> matrix)
{
    std::cout << "\n";

    for (const auto& itr : matrix)
    {
        for (const auto& itr1 : itr) {

            std::cout << itr1 << "\t";
        }

        std::cout << "\n";
    }
}

template <typename T>
void printVector(std::vector<T> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }

    std::cout << "\n";
}


//  Implementation  //

float findLargestValueMatrix(const std::vector<std::vector<float>>& matrix)
{
    float max = 0;
    for (const auto& itr : matrix)
    {
        for (const auto& itr1 : itr)
        {
            max = std::max(max, itr1);
        }
    }
    return max;
}

bool isBai316(const std::vector<std::vector<int>>& matrix)
{
    for (const auto& itr : matrix)
    {
        for (const auto& itr1 : itr)
        {
            if (itr1 < 2004 && itr1 % 2 == 0)
                return true;
        }
    }
    return false;
}

int countPrimeInMatrix(const std::vector<std::vector<int>>& matrix)
{
    int count = 0;
    for (const auto& itr : matrix)
    {
        for (const auto& itr1 : itr)
        {
            if (isPrime(itr1))
                ++count;
        }

    }
    return count;

}

void sortMatrix(std::vector<std::vector<float>>& matrix)
{
    for (auto& itr : matrix)
        sort(itr.begin(), itr.end());


    displayMatrix(matrix);
}

float sumPositiveinMatrix(const std::vector<std::vector<float>>& matrix)
{
    float sum = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] > 0)
                sum += matrix[i][j];
        }
    }
    return sum;
}

void sumRowinMatrix(const std::vector<std::vector<float>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        float sum = 0;
        for (int j = 0; j < matrix[i].size(); ++j)
            sum += matrix[i][j];

        std::cout << "Row " << i << ": " << sum << "\n";
    }
}

void calculateProductofColumn(const std::vector<std::vector<float>>& matrix)
{

    for (int i = 0; i < matrix[0].size(); ++i)
    {
        float sum = 0;
        for (int j = 0; j < matrix.size(); ++j)
        {
            if (matrix[j][i] > 0)
                sum *= matrix[j][i];
        }
        std::cout << "Column " << i << ": " << sum << "\n";
    }
}

void sumOddNumberinColumn(const std::vector<std::vector<int>>& matrix)
{

    for (int i = 0; i < matrix[0].size(); ++i)
    {
        int sum = 0;
        for (int j = 0; j < matrix.size(); ++j)
        {
            if (matrix[j][i] % 2 == 1)
                sum += matrix[j][i];
        }
        std::cout << "Column " << i << ": " << sum << "\n";
    }


}

int countXinMatrix(const std::vector<std::vector<float>>& matrix, const int& x)
{
    int count = 0;
    for (const auto& itr : matrix)
    {
        for (const auto& itr1 : itr)
        {
            if (itr1 == x)
                ++count;
        }
    }
    return count;
}

int countExtremeValueinMatrix(const std::vector<std::vector<float>>& matrix)
{
    int count = 0;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            if (i - 1 >= 0) // down
            {
                if (matrix[i][j] <= matrix[i - 1][j])
                    continue;
            }

            if (i + 1 < matrix.size()) //up
            {
                if (matrix[i][j] <= matrix[i + 1][j])
                    continue;
            }

            if (j - 1 >= 0) //left
            {
                if (matrix[i][j] <= matrix[i][j - 1])
                    continue;
            }

            if (j + 1 < matrix[0].size()) //right
            {
                if (matrix[i][j] <= matrix[i][j + 1])
                    continue;
            }

            if (j + 1 < matrix[0].size() && i + 1 < matrix.size()) //bot right
            {
                if (matrix[i][j] <= matrix[j + 1][i + 1])
                    continue;
            }

            if (j + 1 < matrix[0].size() && i - 1 >= 0) //top right
            {
                if (matrix[i][j] <= matrix[i - 1][j + 1])
                    continue;
            }

            if (j - 1 >= 0 && i + 1 < matrix.size()) //bot left
            {
                if (matrix[i][j] <= matrix[i + 1][j - 1])
                    continue;
            }

            if (j - 1 >= 0 && i - 1 >= 0) //top left
            {
                if (matrix[i][j] <= matrix[i - 1][j - 1])
                    continue;
            }
            ++count;
        }
    }

    return count;
}

void printRowEven(const std::vector<std::vector<int>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] % 2 == 0)
            {
                printVector(matrix[i]);
                break;
            }
        }
    }
}

void printBai361(const std::vector<std::vector<float>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        bool checkZero = false;
        bool checkPositive = false;
        bool checkNegative = false;

        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] == 0)
                checkZero = true;
            if (matrix[i][j] > 0)
                checkPositive = true;
            if (matrix[i][j] < 0)
                checkNegative = true;
        }
        if (checkZero == true && checkPositive == true && checkNegative == true)
            printVector(matrix[i]);

    }
}

float findModeMatrix(const std::vector<std::vector<float>>& matrix)
{
    std::map<float, float> m;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
            m[matrix[i][j]]++;

    }

    const auto& itr = m.rbegin();
    return itr->first;
}

int findMostAppearDigit(const std::vector<std::vector<int>>& matrix)
{
    std::map<int, int> m;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            int copy = matrix[i][j];
            while (copy > 0)
            {
                m[copy % 10]++;
                copy /= 10;
            }
        }
    }

    const auto& itr = m.rbegin();
<<<<<<< HEAD
    return itr->second;
}

void listColumnWithMostDigit(const std::vector<std::vector<int>>& matrix)
{
    std::map<std::vector<int>, int> m;
    int max = 0;

    for (int i = 0; i < matrix[0].size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            int temp = matrix[j][i];
            do
            {
                m[matrix[j]]++; //m[matrix[i]]++
                temp /= 10;
            } while (temp > 0);
        }
    }


    for (const auto& itr : m) //get max   
        max = std::max(max, (int)itr.second);

    for (const auto& itr1 : m) //check second against max then print it out
    {
        if (itr1.second == max)
            printVector(itr1.first);
    }
}

void buildBFromA428(std::vector<std::vector<int>> matrix)
{

    std::vector<std::vector<int>> B(matrix.size());

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            int count = 0;

            if (i - 1 >= 0 && matrix[i - 1][j] > 0) //check above
                ++count;
            if (i + 1 <= matrix.size() - 1 && matrix[i + 1][j] > 0) //check below
                ++count;
            if (j + 1 <= matrix[0].size() - 1 && matrix[i][j + 1] > 0) //check right
                ++count;
            if (j - 1 >= 0 && matrix[i][j - 1] > 0) //check left
                ++count;

            if (i - 1 >= 0 && j - 1 >= 0 && matrix[i - 1][j - 1] > 0) //check bot left diag
                ++count;
            if (i + 1 <= matrix.size() - 1 && j + 1 <= matrix[0].size() - 1 && matrix[i + 1][j + 1] > 0) //check top right diag
                ++count;
            if (i + 1 <= matrix.size() - 1 && j - 1 >= 0 && matrix[i + 1][j - 1] > 0) //check bot right diag
                ++count;
            if (i - 1 >= 0 && j + 1 <= matrix[0].size() - 1 && matrix[i - 1][j + 1] > 0) //check top left diag
                ++count;


            B[i].push_back(count);

        }
    }
    displayMatrix(B);

=======
    return itr->first;
>>>>>>> main
}