#include <iostream>
#include <vector>
#include <algorithm>

#include "chapter7.h"

template <typename T>
std::vector<std::vector<T>> buildMatrix(std::vector<std::vector<T>>& v)
{
    int size = 0;

    do {
        std::cout << "Enter the size of the matrix: ";
        std::cin >> size;

    } while (size == 0);

    std::vector<std::vector<T>> matrix(size, std::vector<T>(size));

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
    v = matrix;
    return v;
}

template <typename T>
void displayMatrix(std::vector<std::vector<T>>& matrix)
{
    std::cout << "\n";

    for (const auto& itr : matrix)
    {
        for (const auto& itr1 : itr)
            std::cout << itr1 << "\t";
        std::cout << "\n";
    }
}

template <typename T>
void displayUpperTriangle(std::vector<std::vector<T>> matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            if (j < i)
                matrix[i][j] = 0;
        }
    }

    displayMatrix(matrix);
}

template <typename T>
T sumDiagonalElements(const std::vector<std::vector<T>>& matrix) //bai 440
{
    T sum = 0;

    for (int i = 0; i < matrix.size(); ++i)
        sum += matrix[i][i];

    return sum;

}

template <typename T>
T findSmallestNumberInLowerTriangle(const std::vector<std::vector<T>>& matrix)//bai 444
{
    T min = matrix[0][0];
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
            if (j <= i)
                min = std::min(min, matrix[i][i]);

    }
    return min;
}

template <typename T>
void findPairClosestValue(const std::vector<std::vector<T>>& matrix)//bai 448
{
    T distance = matrix[0][1];
    std::pair<T, T> p = { 0, 0 };

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            for (int k = i + 1; k < matrix.size(); ++k) //might need a check for out of bound if size < 2
            {
                for (int l = j + 1; l < matrix.size(); ++l)
                {
                    if (distance > std::abs(matrix[i][j] - matrix[k][l]))
                    {
                        distance = std::min(distance, std::abs(matrix[i][j] - matrix[k][l]));
                        p.first = matrix[i][j];
                        p.second = matrix[k][l];
                    }
                }

            }
        }
    }
    std::cout << p.first << "\t" << p.second << "\n";
}

template <typename T>
bool isDiagonalAscending(const std::vector<std::vector<T>>& matrix)
{
    for (int i = 0; i < matrix.size() - 1; ++i)
    {
        for (int j = 0; j < matrix.size() - 1; ++j)
        {
            if (matrix[i][j] > matrix[i + 1][j + 1])
                return false;
        }
    }
    return true;
}

template <typename T>
bool isSymetrical(const std::vector<std::vector<T>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            if (i != j)
            {
                if (matrix[i][j] != matrix[j][i])
                    return false;
            }
        }
    }
    return true;
} //bai 457

template <typename T>
void swapRow(std::vector<std::vector<T>> matrix, int a, int b) //bai 462
{
    if (a - 1 < matrix.size() && b - 1 < matrix.size())
    {
        std::vector<T> temp;
        temp = matrix[a - 1];
        matrix[a - 1] = matrix[b - 1];
        matrix[b - 1] = temp;
    }
    else
        std::cout << "Can't swap due to accessing an out of bound element.\n";

    displayMatrix(matrix);
}

template <typename T>
void swapColumn(std::vector<std::vector<T>> matrix, int a, int b)
{
    if (a - 1 < matrix.size() && b - 1 < matrix.size())
    {
        std::vector<T> temp;
        for (int i = 0; i < matrix.size(); ++i)
        {
            temp.push_back(matrix[i][a - 1]);
            matrix[i][a - 1] = matrix[i][b - 1];
            matrix[i][b - 1] = temp[i];
        }

    }
    else
        std::cout << "Can't swap due to accessing an out of bound element.\n";

    displayMatrix(matrix);
}

template <typename T>
bool isMagicSquare(const std::vector<std::vector<T>>& matrix) //bai 459
{
    T sum = 0;
    T sum1 = 0;

    for (int i = 0; i < matrix.size(); ++i) //sum of diag 1
        sum += matrix[i][i];

    for (int i = 0; i < matrix.size(); ++i) //sum of diag 2
        sum1 += matrix[i][matrix.size() - i - 1];

    if (sum != sum1) //check 2 diag
        return false;

    for (int i = 0; i < matrix.size(); ++i)
    {
        T sumRow = 0;
        for (int j = 0; j < matrix.size(); ++j)
            sumRow += matrix[i][j];

        if (sumRow != sum)
            return false;
    }

    for (int i = 0; i < matrix.size(); ++i)
    {
        T sumCol = 0;
        for (int j = 0; j < matrix.size(); ++j)
            sumCol += matrix[j][i];

        if (sumCol != sum)
            return false;
    }

    return true;

}

template <typename T>
void getProduct(const std::vector<std::vector<T>>& matrix, const std::vector<std::vector<T>>& matrix1)
{
    std::vector<std::vector<T>> result(matrix.size(), std::vector<T>(matrix.size(), 0));

    for (int i = 0; i < result.size(); ++i)
    {
        for (int j = 0; j < result.size(); ++j)
        {
            for (int k = 0; k < result.size(); ++k)
                result[i][j] += matrix[i][k] * matrix1[k][j];
        }

    }

    displayMatrix(result);
}



int main()
{
    std::cout << "--------------- Chapter 7 ---------------\n\n";
    std::cout << "\nBai 429 & 331: Enter an integer matrix.\n";
    std::vector<std::vector<int>> intMatrix;
    buildMatrix(intMatrix);
    displayMatrix(intMatrix);

    std::cout << "\nBai 430 & 432: Enter a float matrix.\n";
    std::vector<std::vector<float>> floatMatrix;
    buildMatrix(floatMatrix);
    displayMatrix(floatMatrix);

    std::cout << "\nBai 433: Find the largest number in the matrix.\n";
    std::cout << "Answer: " << findLargestNumber(floatMatrix);
    std::cout << "\nBai 438: Find the upper triangle in the matrix.\n";
    displayUpperTriangle(intMatrix);
    displayUpperTriangle(floatMatrix);
    std::cout << "\nBai 440: Find the sum of elements that lies on the diagonal line of the matrix.\n";
    std::cout << "Answer: " << sumDiagonalElements(intMatrix) << "\n";
    std::cout << "Answer: " << sumDiagonalElements(floatMatrix) << "\n";
    std::cout << "\nBai 444: Find the smallest value in the lower triangle.\n";
    std::cout << "Answer: " << findSmallestNumberInLowerTriangle(intMatrix) << "\n";
    std::cout << "Answer: " << findSmallestNumberInLowerTriangle(floatMatrix) << "\n";
    std::cout << "\nBai 448: Find two numbers that are closest in terms of value in the matrix.\n";
    findPairClosestValue(intMatrix);
    std::cout << "\nBai 455: Count the number of even numbers in the upper triangle of a square matrix.\n";
    std::cout << countEvenNumberUpperTriangle(intMatrix) << "\n";
    std::cout << "\nBai 456: Are the values on the diagonal line ascending top to bottom.\n";
    std::cout << "Answer: " << isDiagonalAscending(intMatrix) << "\n";
    std::cout << "Answer: " << isDiagonalAscending(floatMatrix) << "\n";
    std::cout << "\nBai 458: Is the matrix symetrical through y = x.\n";
    std::cout << "Answer: " << isSymetrical(intMatrix) << "\n";
    std::cout << "Answer: " << isSymetrical(floatMatrix) << "\n";
    std::cout << "\nBai 459: Is the matrix a magic square.\n";
    std::cout << "Answer: " << isMagicSquare(intMatrix) << "\n";
    std::cout << "Answer: " << isMagicSquare(floatMatrix) << "\n";
    std::cout << "\nBai 462: Swap rows\n";
    swapRow(intMatrix, 1, 2);
    swapRow(floatMatrix, 1, 3);
    std::cout << "\nBai 463: Swap columns\n";
    swapColumn(intMatrix, 1, 2);
    swapColumn(floatMatrix, 1, 3);
    std::cout << "\nBai 468: Build an n x n magic square matrix.\n";
    buildMagicSquare(5);
    std::cout << "\nBai 469: Product of two matrices.\n";
    getProduct(floatMatrix, floatMatrix);
    getProduct(intMatrix, intMatrix);
    std::cout << "\nBai 473: Find the determinant of the matrix.\n";
    std::cout << "Answer: " << getDeterminant(intMatrix, (int)intMatrix.size()) << "\n";

    return 0;
}