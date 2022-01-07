// 15. Tính S(n)

#pragma once
double sn15(int n) {
    double result = 0;
    int sum = 0;

    for (int i = 1; i <= n; ++i) {
        sum += i;
        result += 1.0 / sum;
    }

    return result;
}