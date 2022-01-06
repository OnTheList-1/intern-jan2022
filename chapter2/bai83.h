// 83. Viết chương trình nhập vào hai số thực. Kiểm tra xem chúng có cùng

#pragma once

std::string checkSign()
{
    int n1;
    int n2;
    std::cout << "So 1: ";
    std::cin >> n1;
    std::cout << "So 2: ";
    std::cin >> n2;
    return n1 * n2 > 0 ? "True" : "False";

}