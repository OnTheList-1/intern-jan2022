// 75. Kiểm tra số nguyên 4 byte có dạng 2𝑘 hay không ?

#pragma once

bool sn75(int n) {
    n = (n < 0) ? -n : n;
    if (n < 2)
        return true;
    while (n > 1)
    {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }

    return true;
}