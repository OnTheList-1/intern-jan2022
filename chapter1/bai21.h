﻿// 21. Tính tổng tất cả “ước số” của số nguyên dương n.

#pragma once
int sn21(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i)
    {
        if (n % i == 0)
            sum += i;
    }

    sum += n;

    return sum;


}