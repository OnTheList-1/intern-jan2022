// Lập chương trình in ra hình chữ nhật có kích thước m x n.

#pragma once

void printRectangleA(int l, int w)
{
    std::cout << "A. Hinh chu nhat dac.\n\n";
    for (int i = 1; i <= w; ++i)
    {
        for (int j = 1; j <= l; ++j)
        {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

void printRectangleB(int l, int w)
{
    std::cout << "B. Hinh chu nhat rong.\n\n";
    for (int i = 1; i <= w; ++i) {
        for (int j = 1; j <= l; ++j) {
            if (i == 1 || i == w || j == 1 || j == l) {
                std::cout << "* ";
            }
            else
            {

                std::cout << "  ";
            }
        }
        std::cout << "\n";
    }
}
