// 110.Cần có tổng 200.000đ từ 3 loại giấy bạc 1000đ, 2000đ, và 5000đ. Lập chương tình để tìm tất cả các phương án có thể.

#pragma once

void findChange() {
    int countWays = 0;
    for (int i = 0; i <= 200; ++i) {
        for (int j = 0; j <= 100; ++j) {
            for (int k = 0; k <= 40; ++k) {
                if (i * 1000 + j * 1000 + k * 1000 == 200000) {
                    std::cout << ++countWays << ". 1000d = " << i << "\t" << "2000d = " << j << "\t" << "5000d = " << k << "\t" << std::endl;
                }
            }
        }
    }
}