#pragma once
#include <cmath>

int sn2(int n)
{
    int result = 0;
    for (int i = 1; i <= n; ++i)
    {
        result += i * i;
    }

    return result;
};