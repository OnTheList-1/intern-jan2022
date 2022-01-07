// Viết chương trình in ra tam giác cân có độ cao h

#pragma once

void printTriangleA(int h)
{
    std::cout << "A. Tam giac can dac nam gia man hinh.\n\n";
    for (int i = 1, k = 0; i <= h; ++i, k = 0)
    {

        for (int space = 1; space <= h - i; ++space)
        {
            std::cout << "  ";
        }
        while (k != 2 * i - 1)
        {
            std::cout << "* ";
            ++k;
        }

        std::cout << std::endl;
    }

}

void printTriangleB(int h)
{
    std::cout << "B. Tam giac can rong nam giua man hinh.\n\n";
    for (int i = 1; i <= h; i++)
    {
        for (int space = 1; space <= h - i; space++)
        {
            std::cout << " ";
        }

        for (int j = 1; j <= 2 * i - 1; j++)
        {
            if (i == h || j == 1 || j == 2 * i - 1)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}


void printTriangleC(int h)
{
    std::cout << "C. Tam Giac Vuong Can Dac.\n\n";
    for (int i = 1; i <= h; ++i)
    {
        for (int j = i; j > 0; --j)
        {
            std::cout << "* ";
        }
        std::cout << "\n";
    }
}

void printTriangleD(int h)
{
    std::cout << "D. Tam giac vuong can rong.\n\n";
    for (int i = 1; i <= h; ++i) {
        if (i > 1 && i < h) {
            std::cout << "*";
        }

        for (int j = i; j > 0; --j)
        {
            if (i == h || j == 1 || j == 2 * i - 1)
            {
                std::cout << "*";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}