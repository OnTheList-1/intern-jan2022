// 29. Tìm ước số lẻ lớn nhất của số nguyên dương n. Ví dụ n = 100 ước lẻ lớn
// nhất của 100 là 25
#pragma once

int sn29(int n) {
    int i = n;
    while (i > 0)
    {
        if (n % i == 0 && i % 2 != 0)
            return i;

        --i;
    }
}