#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

#include "chapter10.h"

//helpers

int smallestNumber(const std::vector<int>& v, const size_t& start, const size_t end)
{
    int min = v[start];
    int index = 0;
    for (size_t i = start; i < end; ++i)
    {
        if (min > v[start])
        {
            min = v[start];
            index = (int)i;
        }
    }
    return index;
}

template <typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

//functions

int sumInteger(const int& n)
{
    if (n == 1)
        return n;

    return n + sumInteger(n - 1);
} //bai 702

int factorial(const int& n)
{
    if (n == 1)
        return n;

    return n * factorial(n - 1);
}

int countEven(const std::vector<int>& v, int i)
{
    int count = 0;

    if (i == v.size() - 1) //base case
        return 0;

    if (v[i] % 2 == 0)
        count = 1;
    else
        count = 0;


    return count + countEven(v, i + 1);
}

int countPositiveInReal(const std::vector<float>& v, size_t i)
{
    int count = 0;
    if (i == v.size() - 1)
        return 0;

    if (v[i] > 0)
        count = 1;

    return count + countPositiveInReal(v, i + 1);
}

int fibonacci(const size_t& n)
{
    if (n == 0 || n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

float sumBai710(const int& x, const int& n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return x;

    return (1 + x / n) * sumBai710(x, n - 1) - (x / n) * sumBai710(x, n - 2);
}

void printVector(const std::vector<int>& v, size_t size)
{
    if (size <= v.size() - 1)
        std::cout << v[size] << " ";

    else
        return;

    printVector(v, size + 1);
}

void printVectorReverse(const std::vector<int>& v, size_t size)
{
    if (size >= 0)
    {
        std::cout << v[size] << " ";
        if (size == 0)
            return;
        printVectorReverse(v, size - 1);
    }
    return;
}

int sumOfVectorInt(const std::vector<int>& v, size_t size)
{
    int sum = 0;
    if (size < v.size())
        sum += v[size];
    else
        return 0;

    return sum + sumOfVectorInt(v, size + 1);

}

float sumOfPositiveFloat(const std::vector<float>& v, size_t size)
{
    float sum = 0;
    if (size < v.size())
    {
        if (v[size] > 0)
            sum += v[size];
    }
    else
        return 0;

    return sum + sumOfPositiveFloat(v, size + 1);

}

int largestNumber(const std::vector<int>& v, size_t size)
{
    int big = v[size];
    if (size < v.size() - 1)
    {
        if (big < largestNumber(v, size + 1))
            big = largestNumber(v, size + 1);
    }
    else
        return big;
    return largestNumber(v, size + 1);
}

int indexLargestNumber(const std::vector<float>& v, size_t size)
{
    size_t big = size;
    if (size < v.size() - 1)
    {
        if (v[big] < indexLargestNumber(v, size + 1))
            big = indexLargestNumber(v, size + 1);
    }
    else
        return (int)big;

    return indexLargestNumber(v, size + 1);
}

void sortArray(std::vector<int>& v, size_t size)
{
    if (size < v.size())
    {
        int s = smallestNumber(v, size, v.size() - 1);
        swap(v[s], v[size]);
        sortArray(v, size + 1);

    }
    else
    {
        for (int i = 0; i < size; ++i)
            std::cout << v[i] << " ";

        std::cout << "\n";
    }
}

int sumNSquare(const int& n)
{
    int sum = 0;
    if (n > 0)
        sum = std::pow(n, 2);


    else
        return sum;

    return sum + sumNSquare(n - 1);
}

float sumFractionN(const int& n)
{
    float sum = 0;

    if (n > 0)
        sum += 1.0 / (float)(n * 2);
    else
        return sum;

    return sum + sumFractionN(n - 1);
}

float sumBai734(const int& n)
{
    float sum = 0;
    if (n >= 0)
    {
        sum += 1.0 / (float)(2 * n + 1);
    }
    else
        return sum;

    return sum + sumBai734(n - 1);
}

float sumBai735(const int& n, const int& start)
{
    float sum = 0;

    if (start < n + 1)
        sum += 1.0 / (start * (start + 1));

    else
        return sum;

    return sum + sumBai735(n, start + 1);

}

int xPowN(const int& x, const int& n)
{
    if (n == 0)
        return 1;

    return x * xPowN(x, n - 1);
}

int sumPower(const int& x, const int& n)
{
    int sum = 0;
    if (n == 0)
        return 1;
    else
        sum = xPowN(x, n);

    return sum + sumPower(x, n - 1);

}

int gcd(const int& x, const int& a)
{
    if (x % a == 0)
        if (a % 2 == 1)
            return a;

    gcd(x, a - 1);
}

float sumBai748(const int& n)
{
    if (n == 1)
        return std::sqrt(2);

    return std::sqrt(2 + sumBai748(n - 1));

}

float sumBai751(const int& n)
{
    if (n == 1)
        return 1.0;

    return 1.0 / (1.0 + sumBai751(n - 1));
}

int countDigit(int n)
{
    int count = 0;
    if (n >= 0)
    {
        ++count;
        n /= 10;
    }
    else
        return count;

    return count + countDigit(n - 1);

}

int productDigit(int n)
{
    if (n / 10 < 1)
        return n;
    else
        return n % 10 * productDigit(n / 10);

}

int firstDigit(int n)
{
    if (n / 10 < 1)
        return n;

    else
        return firstDigit(n / 10);


}

int reverseN(int n, int reverse)
{
    if (n == 0)
        return reverse;

    reverse = reverse * 10 + n % 10;
    return reverseN(n / 10, reverse);
}
