// 32. Cho số nguyên dương n. Kiểm tra số nguyên dương n có phải là số chính
// phương hay không ?

#pragma once
#include <cmath>
bool sn32(int n) {
    bool flag = false;
    if (floor((double)sqrt(n)) == ceil((double)sqrt(n)))
        flag = true;


    return flag;
}