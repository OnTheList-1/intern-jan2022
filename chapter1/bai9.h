#pragma once
// Tính T(n) = 1 𝑥 2 𝑥 3 𝑥 … . 𝑥 𝑛.

int sn9(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
};
