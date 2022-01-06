// 88. Hãy sử dụng vòng lặp for để xuất tất cả các ký tự A tới Z

#pragma once

void printAtoZ()
{
    for (char c = 'a'; c <= 'z'; ++c) {
        std::cout << c << " ";
    }

}