// 41. Tính S(n) có n dấu phân số.

#pragma once

float sn41(int n) {
    float result = 0;
    int i = 0;
    while (i < n)
    {
        result = (1.0 / result);
        ++i;
    }

    return result;
}