// 84. Giải phương trình và biện luận phương trình 𝑎𝑥 + 𝑏 = 0.

#pragma once

double solveX(double a, double b)
{
    if (a == 0)
    {
        if (b == 0) {
            std::cout << "this equation has infinite roots\n";
            return 0;
        }

        else
        {
            std::cout << "this equation has no root\n";
            return 0;
        }
    }
    return -b / a;
}