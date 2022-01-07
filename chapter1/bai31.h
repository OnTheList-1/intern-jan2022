// 31. Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số nguyên tố
// hay không ?

#pragma once

bool sn31(int n) {
    bool flag = true;
    int i = 2;

    while (i < n) {
        if (n % i == 0)
        {
            flag = false;
            break;
        }
        ++i;
    }

    return flag;
}