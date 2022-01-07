// 40. Tính S(n) = √𝑥 n + √𝑥 n−1 + √𝑥 n−2 + ⋯ √𝑥 2 + √𝑥 có n dấu căn.

#pragma once
float sn40(int n, int x) {
    float result = 0;
    float temp = 1;
    int i = 1;

    while (i <= n)
    {
        temp *= x;
        result = sqrt(temp + result);
        // fix
        ++i;
    }
    return result;
}