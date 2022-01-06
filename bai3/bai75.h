// 75. Kiểm tra số nguyên 4 byte có dạng 2𝑘 hay không ?

#pragma once

bool sn75(int n) {
    bool flag = true;
    n = (n < 0) ? -n : n;
    if (n < 2)
        return 1;
    while (n > 1)
    {
        if (n % 2 != 0)
            flag = false;
        n /= 2;
    }

    return flag;
}