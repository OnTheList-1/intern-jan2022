// 20. Liệt kê tất cả “ước số” của số nguyên dương n.

#pragma once
std::vector<int> sn20(int n) {
    std::vector<int> result;
    for (int i = 1; i < n; ++i)
    {
        if (n % i == 0)
            result.push_back(i);

    }
    result.push_back(n);
    return result;
}
