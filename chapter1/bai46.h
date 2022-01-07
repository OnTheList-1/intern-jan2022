// 46. Hãy đếm số lượng chữ số lẻ của số nguyên dương n.

#pragma once

int sn46(int n) {
    int result = 0;
    while (n > 0) {
        if (n % 2 == 1)
            ++result;
        n /= 10;
    }

    return result;
}