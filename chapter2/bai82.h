// 82. Viết chương trình tìm số lớn nhất trong ba số thực a, b, c.

#pragma once

int maxNum(int a, int b, int c)
{
    int max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    return max;
}