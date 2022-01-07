#pragma once
// Tính S(n) = 1 + 1 /2 + 1 / 3 + … + 1 / 𝑛
#pragma once
double sn3(int n)
{
    double result = 0.0;
    for (int i = 1; i <= n; ++i)
    {
        result += 1.0 / i;
    }

    return result;
};