// 92. Tìm ước số chung lớn nhất của hai số nguyên dương.

#pragma once

int gcd(int a, int b) {
    for (int i = std::min(a, b); i > 0; --i) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
}