#include <iostream>
#include <map>
#include <algorithm>

#include "chapter6.h"

template <typename T>
std::vector<std::vector<T>> buildMatrix(std::vector<std::vector<T>>& v)
{
    int column = 0;
    int row = 0;

    do {
        std::cout << "Enter the number of columnns: ";
        std::cin >> column;
        std::cout << "Enter the number of rows: ";
        std::cin >> row;

    } while (column == 0 || row == 0);

    std::vector<std::vector<T>> matrix(row, std::vector<T>(column));

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            std::cin >> matrix[i][j];
        }
    }
    v = matrix;
    return v;
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

template <typename T> //bai 327
T sumBorderMatrix(const std::vector<std::vector<T>>& matrix)
{
    T sum = 0;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (i == 0 || i == matrix.size() - 1 || j == 0 || j == matrix[i].size() - 1) //check for first and last row
                sum += matrix[i][j];
        }
    }

    return sum;
}

template <typename T> //bai 320
void absMatrix(std::vector<std::vector<T>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] < 0)
                matrix[i][j] = abs(matrix[i][j]);
        }
    }

    displayMatrix(matrix);
}

template <typename T> //bai 346
int countQueenValue(std::vector<std::vector<T>>& matrix)
{
    int count = 0;
    int sz = (int)(matrix.size() > matrix[0].size() ? matrix.size() : matrix[0].size());

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            bool checkRow = true;
            bool checkColumn = true;
            bool checkDiagonal = true;

            for (int rowTraverse = 0; rowTraverse < matrix.size(); ++rowTraverse)
            {
                if (matrix[rowTraverse][j] > matrix[i][j])
                    checkRow = false;
            }

            for (int columnTraverse = 0; columnTraverse < matrix[0].size(); ++columnTraverse)
            {
                if (matrix[i][columnTraverse] > matrix[i][j])
                    checkColumn = false;
            }

            int row = i;
            int col = j;

            for (int traverseDiagonal = 1; traverseDiagonal < sz; ++traverseDiagonal)
            {
                if (row + traverseDiagonal < matrix.size() && row - traverseDiagonal >= 0 && col + traverseDiagonal < matrix[i].size() && col - traverseDiagonal >= 0) //check row and column
                {
                    if (matrix[row + traverseDiagonal][col + traverseDiagonal] > matrix[i][j]) //check diag down
                        checkDiagonal = false;
                    if (matrix[row - traverseDiagonal][col - traverseDiagonal] > matrix[i][j]) //check diag up
                        checkDiagonal = false;
                    if (matrix[row + traverseDiagonal][col - traverseDiagonal] > matrix[i][j]) //check mirror down
                        checkDiagonal = false;
                    if (matrix[row - traverseDiagonal][col + traverseDiagonal] > matrix[i][j]) //check mirror up
                        checkDiagonal = false;
                }
            }

            if (checkColumn == true && checkRow == true && checkDiagonal == true)
                ++count;
        }
    }
    return count;
}

template <typename T> //bai 347
int countSaddleValue(std::vector<std::vector<T>>& matrix)
{
    int count = 0;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size(); ++j)
        {
            bool checkRow = true;
            bool checkColumn = true;

            for (int rowTraverse = 0; rowTraverse < matrix.size(); ++rowTraverse)
            {
                if (matrix[rowTraverse][j] > matrix[i][j])
                    checkRow = false;
            }
            for (int columnTraverse = 0; columnTraverse < matrix[0].size(); ++columnTraverse)
            {
                if (matrix[i][columnTraverse] < matrix[i][j])
                    checkColumn = false;
            }
            if (checkColumn == true && checkRow == true)
                ++count;
        }

    }
    return count;
}

template <typename T> //bai 352
bool rowIsAscending(const std::vector<std::vector<T>>& matrix)
{
    bool flag = true;
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[0].size() - 1; ++j)
        {
            if (matrix[i][j] > matrix[i][j + 1])
                flag = false;
        }
    }
    return flag;

}

template <typename T> //bai 361
bool columnIsAscending(const std::vector<std::vector<T>>& matrix)
{
    bool flag = true;

    for (int i = 0; i < matrix[0].size(); ++i)
    {
        for (int j = 0; j < matrix.size() - 1; ++j)
        {
            if (matrix[j][i] < matrix[j + 1][i])
                flag = false;
        }
    }

    return flag;
}

template <typename T> //bai 370
T findLargestNegativeinMatrix(std::vector<std::vector<T>>& matrix)
{
    T negative = matrix[0][0];

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] < 0)
                negative = std::min(negative, matrix[i][j]);
        }
    }
    return negative;
}

template <typename T> //bai 385
void largestValueRowMatrix(std::vector<std::vector<T>>& matrix)
{
    std::map<std::vector<T>, T> index;
    T sum = 0;
    T max = 0;

    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            sum += matrix[i][j];
        }
        max = std::max(sum, max);
        index[matrix[i]] = sum;
    }

    for (const auto& itr : index)
    {
        if (itr.second == max)
            printVector(itr.first);
    }

}

template <typename T>
void rotateMatrixRow(std::vector<std::vector<T>> matrix)
{
    std::vector<T> temp(1);
    temp = matrix[(int)(matrix.size()) - 1];

    for (int i = (int)matrix.size() - 1; i > 0; --i)
        matrix[i] = matrix[i - 1];

    matrix[0] = temp;
    displayMatrix(matrix);
}

template <typename T>
void rotateMatrixColumn(std::vector<std::vector<T>> matrix)
{
    for (auto& row : matrix)
        std::rotate(row.begin(), row.begin() + 1, row.end());

    displayMatrix(matrix);

}

template <typename T>
void deleteRow(std::vector<std::vector<T>> matrix)
{
    for (int i = 0; i < matrix.size() - 1; ++i)
        matrix[i] = matrix[i + 1];

    matrix.resize(matrix.size() - 1);
    displayMatrix(matrix);
}

template <typename T>
void deleteColumn(std::vector<std::vector<T>> matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
        matrix[i].erase(matrix[i].begin());

    displayMatrix(matrix);
}

template <typename T>
void symetricOnXAxis(std::vector<std::vector<T>> matrix)
{
    for (int i = 0; i < matrix.size() / 2; ++i)
    {
        std::vector<T> copy;
        copy = matrix[i];
        matrix[i] = matrix[matrix.size() - i - 1];
        matrix[matrix.size() - i - 1] = copy;
    }

    displayMatrix(matrix);
}

template <typename T>
void sortAscendingRow(std::vector<std::vector<T>> matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            for (int k = j + 1; k < matrix[i].size(); ++k) //sort
            {
                if (matrix[i][j] > matrix[i][k])
                {
                    T temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }

    displayMatrix(matrix);
}

template <typename T>
void sortDescendingColumn(std::vector<std::vector<T>> matrix)
{
    for (int i = 0; i < matrix[0].size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
        {
            for (int k = j + 1; k < matrix.size(); ++k)
            {
                if (matrix[j][i] < matrix[k][i])
                {
                    T temp = matrix[j][i];
                    matrix[j][i] = matrix[k][i];
                    matrix[k][i] = temp;
                }
            }
        }
    }
    displayMatrix(matrix);
}

template <typename T>
void sortClockwise(std::vector<std::vector<T>> matrix)
{
    if (matrix.size() <= 1) {
        std::cout << "Size too short, nothing to sort.\n";
    }
    else
    {

        std::vector<T> sortedVector;
        int indexAppending = 0;

        for (int i = 0; i < matrix.size(); ++i)  //append border elements to new vec and sort that new vector
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (i == 0 || j == 0 || i == matrix.size() - 1 || j == matrix[0].size() - 1)
                    sortedVector.push_back(matrix[i][j]);
            }
        }

        std::sort(sortedVector.begin(), sortedVector.end());

        for (int i = 0; i < matrix[0].size(); ++i) //replace first row
            matrix[0][i] = sortedVector[indexAppending++];

        for (int i = 1; i < matrix.size(); ++i)
            matrix[i][matrix[i].size() - 1] = sortedVector[indexAppending++];
        //replace right border

        for (int i = (int)matrix[0].size() - 2; i >= 0; --i)
            matrix[matrix[0].size() - 1][i] = sortedVector[indexAppending++];
        //replace last row

        for (int i = (int)matrix.size() - 2; i > 0; --i) //replace left border
            matrix[i][0] = sortedVector[indexAppending++];

        displayMatrix(matrix);
    }

}

int main()
{
    std::cout << "--------------- Chapter 6 ---------------\n\n";
    std::cout << "\nBai 311 & 313: Enter an integer matrix.\n";
    std::vector<std::vector<int>> intMatrix;
    buildMatrix(intMatrix);
    displayMatrix(intMatrix);

    std::cout << "\nBai 312 & 314: Enter a float matrix.\n";
    std::vector<std::vector<float>> floatMatrix;
    buildMatrix(floatMatrix);
    displayMatrix(floatMatrix);

    std::cout << "\nBai 315: Find the largest value in a float type matrix.\n";
    std::cout << "Answer: " << findLargestValueMatrix(floatMatrix) << "\n";
    std::cout << "\nBai 316: Find if the matrix exist a value less than 2004 and is even.\n";
    std::cout << "Answer: " << isBai316(intMatrix) << "\n";
    std::cout << "\nBai 317: Count the number of prime numbers in a matrix.\n";
    std::cout << "Answer: " << countPrimeInMatrix(intMatrix) << "\n";
    std::cout << "\nBai 319: Sort Matrix in ascending order from top to bottom & left to right.\n";
    std::vector<std::vector<float>> bai319(floatMatrix.begin(), floatMatrix.end());
    sortMatrix(bai319);
    std::cout << "\nBai 320: Calculate the sum of all positive numbers in the matrix.\n";
    std::cout << "Answer: " << sumPositiveinMatrix(floatMatrix) << "\n";
    std::cout << "\nBai 322: Calculate the sum of every rows in the matrix.\n";
    std::cout << "Answer: \n";
    sumRowinMatrix(floatMatrix);
    std::cout << "\nBai 323: Calculate the product of positive elements in the column.\n";
    std::cout << "Answer: \n";
    calculateProductofColumn(floatMatrix);
    std::cout << "\nBai 327: Sum of the matrix' border.\n";
    std::cout << "Answer: \n" << sumBorderMatrix(floatMatrix);
    std::cout << "\nBai 329: Replace negative values in the matrix with it's equivalence positive.\n";
    absMatrix(intMatrix);
    absMatrix(floatMatrix);
    std::cout << "\nBai 332: Calculate the sum of all odd numbers in the matrix' column.\n";
    sumOddNumberinColumn(intMatrix);
    std::cout << "\nBai 336: Count the number of X in the matrix.\n";
    std::cout << "Answer: " << countXinMatrix(floatMatrix, 1) << "\n";
    std::cout << "\nBai 342: Count extreme values\n";
    std::cout << "Answer: " << countExtremeValueinMatrix(floatMatrix) << "\n";

    std::cout << "\nBai 346: Count Queen values\n";
    std::cout << "Answer: " << countQueenValue(floatMatrix) << "\n";
    std::cout << "Answer: " << countQueenValue(intMatrix) << "\n";

    std::cout << "\nBai 343: Count saddle values\n";
    std::cout << "Answer: " << countSaddleValue(floatMatrix) << "\n";
    std::cout << "\nBai 352: T/F row ascending matrix\n";
    std::cout << "Answer: " << rowIsAscending(floatMatrix) << "\n";
    std::cout << "\nBai 353: T/F column ascending matrix\n";
    std::cout << "Answer: " << columnIsAscending(floatMatrix) << "\n";
    std::cout << "\nBai 358: Print rows that contain at least one even number\n";
    printRowEven(intMatrix);
    std::cout << "\nBai 361: Print rows that satisfy this condition: contain 0 ; positive; negative\n";
    printBai361(floatMatrix);
    std::cout << "\nBai 370: Find the largest number in the matrix\n";
    std::cout << findLargestNegativeinMatrix(floatMatrix);
    std::cout << "\nBai 381: Find mode in the matrix\n";
    std::cout << findModeMatrix(floatMatrix);
    std::cout << "\nBai 384: Find digit that show up the most in the matrix\n";
    std::cout << findMostAppearDigit(intMatrix);
    std::cout << "\nBai 385: Find largest sum row\n";
    largestValueRowMatrix(floatMatrix);
    largestValueRowMatrix(intMatrix);
    std::cout << "\nBai 390: List the column with the most digit.\n";
    listColumnWithMostDigit(intMatrix);
    std::cout << "\nBai 394: Rotate matrix' row.\n";
    rotateMatrixRow(intMatrix);
    rotateMatrixRow(floatMatrix);
    std::cout << "\nBai 396: Rotate matrix column.\n";
    rotateMatrixColumn(intMatrix);
    rotateMatrixColumn(floatMatrix);
    std::cout << "\nBai 400: Delete a row in a given matrix\n";
    deleteRow(intMatrix);
    deleteRow(floatMatrix);
    std::cout << "\nBai 401: Delete a column in a given matrix\n";
    deleteColumn(intMatrix);
    deleteColumn(floatMatrix);
    std::cout << "\nBai 405: Print the mirror image of the matrix on x-axis.\n";
    symetricOnXAxis(intMatrix);
    symetricOnXAxis(floatMatrix);
    std::cout << "\nBai 407: Sort elements in the row in ascending order.\n";
    sortAscendingRow(intMatrix);
    sortAscendingRow(floatMatrix);
    std::cout << "\nBai 410: Sort elements in the column in descending order.\n";
    sortDescendingColumn(intMatrix);
    sortDescendingColumn(floatMatrix);
    std::cout << "\nBai 420: Sort border elements in ascending order following clockwise rotation.\n";
    sortClockwise(intMatrix);
    sortClockwise(floatMatrix);

    std::cout << "\nBai 428: Build matrix B from A, where B[i][j] is the number of positive numbers around A[i][j].\n";
    buildBFromA428(intMatrix);

    return 0;
}

