// 42. Cho n là số nguyên dương. Hãy tìm giá trị nguyên dương k lớn nhất sao cho
// S(k) < n.Trong đó chuỗi S(k) được định nghĩa như sau: S(k) = 1 + 2 + 3 + … +
// k
#pragma once

int sn42(int n) {
    int result = 0;
    int i = 0;
    while (i < n)
    {
        result += i++;
        if (result > n)
            return i - 1;
    }
}