// 45. Hãy tính tích các chữ số của số nguyên dương n.

#pragma once

int sn45(int n) {
    int result = 1;
    while (n > 0) {
        result *= n % 10;
        n /= 10;

    }
    return result;
}