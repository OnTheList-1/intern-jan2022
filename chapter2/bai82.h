// 82. Viết chương trình tìm số lớn nhất trong ba số thực a, b, c.

#pragma once

float maxNum(float a, float b, float c)
{
    int max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    return max;
}