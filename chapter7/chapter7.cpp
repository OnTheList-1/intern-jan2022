#include <vector>
#include <algorithm>
#include <iostream>

#include "chapter7.h"

template <typename T>
void displayMatrix(const std::vector<std::vector<T>>& matrix)
{
    std::cout << "\n";

    for (const auto& itr : matrix)
    {
        for (const auto& itr1 : itr)
            std::cout << itr1 << "\t";
        std::cout << "\n";
    }

}

float findLargestNumber(const std::vector<std::vector<float>>& matrix)
{
    float max = matrix[0][0];

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
            max = std::max(matrix[i][j], max);
    }

    return max;
}

int countEvenNumberUpperTriangle(const std::vector<std::vector<int>>& matrix)
{
    int count = 0;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            if (j >= i)
                if (matrix[i][j] % 2 == 0)
                    ++count;
        }
    }
    return count;
}

void buildMagicSquare(const int& n)
{
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));

    int count = 1;
    int range = (int)(matrix.size() * matrix.size());
    int i = 0;
    int j = (int)matrix.size() / 2;
    matrix[0][j] = 1; //start from 1st row middle column

    while (count < range)
    {
        if ((i - 1) < 0 && (j - 1) < 0)    //increment i if out of lower bound 0
            ++i;

        else if ((i - 1) < 0) //when only row crosses range, set i to last row, and decrease j
        {
            i = (int)matrix.size() - 1;
            --j;
        }

        else if ((j - 1) < 0)
        {    //when only col crosses range, set j to last column, and decrease i
            j = (int)matrix.size() - 1;
            --i;
        }

        else if (matrix[i - 1][j - 1] != 0)    //when diagonal element is not empty, go to next row
            ++i;

        else
        {
            --i;
            --j;
        }
        matrix[i][j] = ++count;
    }

    displayMatrix(matrix);
}

int getDeterminant(std::vector<std::vector<int>> matrix, int n) //bai 474
{
    std::vector<std::vector<int>> subMatrix(n, std::vector<int>(n));
    int result = 0;


    if (n == 2)
        return (matrix[0][0] * matrix[1][1] - matrix[1][0] * matrix[0][1]);
    else
    {
        for (int i = 0; i < n; ++i)
        {
            int ii = 0;
            for (int j = 1; j < n; ++j)
            {
                int jj = 0;
                for (int k = 0; k < n; ++k)
                {
                    if (k != i)
                        subMatrix[ii][jj++] = matrix[j][k];

                }
                ++ii;
            }
            result += (int)std::pow(-1, i) * matrix[0][i] * getDeterminant(subMatrix, n - 1); //recursive call to matrix.size - 1
        }

    }
    return result;
}