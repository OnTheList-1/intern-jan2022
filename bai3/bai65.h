// 65. Giải phương trình 𝑎𝑥2 + 𝑏𝑥 + 𝑐 = 0.

#pragma once

void sn65(int a, int b, int c)
{
    double delta = (b * b) - (4 * a * c);
    if (a == 0)
    {
        double x1 = -c / b;
        std::cout << "x1 = " << x1 << std::endl;

    }
    else if (delta > 0)
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        std::cout << "x1 = " << x1 << std::endl;
        std::cout << "x2 = " << x2 << std::endl;
    }
    else if (delta == 0)
    {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        std::cout << "x1 = " << x1 << std::endl;
    }
    else
    {
        int realNumber = -b / (2 * a);
        int imaginary = sqrt(-delta) / (2 * a);
        std::cout << "x1 = " << realNumber << " + " << imaginary << "i\n";
        std::cout << "x2 = " << realNumber << " - " << imaginary << "i\n";
    }
}

