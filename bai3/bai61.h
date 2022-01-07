// 61. Hãy kiểm tra các chữ số của số nguyên dương n có giảm dần từ trái sang
// phải hay không ?

#pragma once

bool sn61(int n) {
    int currentDigit = n % 10;
    n /= 10;
    while (n > 0)
    {
        if (currentDigit > n % 10)
            return false;

        currentDigit = n % 10;
        n /= 10;
    }

    return true;
}