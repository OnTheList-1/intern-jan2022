// 35. Tính S(n) = √1 + √2 + √3 + ⋯ √𝑛 − 1 + √𝑛 có n dấu căn.

#pragma once
double sn35(int n) {
    double result = 0;
    int i = n;
    while (i >= 1)
    {
        result = sqrt(i + result); // Reverse function
        --i;
    }
    return result;
}