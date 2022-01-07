// 95. Viết chương trình nhập 3 số thực. Hãy thay tất cả các số âm bằng trị tuyệt đối của nó.

#pragma once

void abs() {
    float a;
    float b;
    float c;
    std::cout << "So 1: ";
    std::cin >> a;
    std::cout << "So 2: ";
    std::cin >> b;
    std::cout << "So 3: ";
    std::cin >> c;

    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    if (c < 0)
        c *= -1;

    /*if (a < 0)
        a = (a >> ((sizeof(a) * 8 - 1) | 1)) * a;
    if (b < 0)
        b = (b >> ((sizeof(b) * 8 - 1) | 1)) * b; cannot shift bit float
    if (c < 0)
        c = (c >> ((sizeof(c) * 8 - 1) | 1)) * c;*/

    std::cout << a << "\t" << b << "\t" << c << std::endl;
}