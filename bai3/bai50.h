// 50. Hãy tìm chữ số đảo ngược của số nguyên dương n

#pragma once

int sn50(int n) {
    int result = 0;
    while (n != 0)
    {
        result = result * 10 + n % 10;
        n /= 10;
    }
    return result;
}
