// bai3.cpp : This file contains the 'main' function. Program execution begins
// and ends there.
//

#include <cmath>
#include <iostream>
#include <vector>

#include "bai1.h"
#include "bai2.h"
#include "bai3.h"
#include "bai9.h"
#include "bai10.h"
#include "bai15.h"
#include "bai20.h"
#include "bai21.h"
#include "bai29.h"
#include "bai30.h"
#include "bai31.h"
#include "bai32.h"
#include "bai33.h"
#include "bai35.h"
#include "bai40.h"
#include "bai41.h"
#include "bai42.h"
#include "bai43.h"
#include "bai45.h"
#include "bai46.h"
#include "bai50.h"
#include "bai59.h"
#include "bai61.h"
#include "bai65.h"
#include "bai75.h"

int main() {
    printf("Bai 1: S(1) = %i; S(5) = %i; S(50) = %i\n", sn1(1), sn1(5), sn1(50)); //bai 1
    printf("Bai 2: S(1) = %i; S(5) = %i; S(50) = %i\n", sn2(1), sn2(5), sn2(50)); //bai 2
    printf("Bai 3: S(1) = %f, S(5) = %f; S(50) = %f\n", sn3(1), sn3(5), sn3(50)); //bai 3
    printf("Bai 9: S(1) = %i, S(5) = %i; S(10) = %i\n", sn9(1), sn9(5), sn9(10)); //bai 9
    printf("Bai 10: S(1, 5) = %f, S(5, 4) = %f, S(15, 0) = %f\n", sn10(1, 5), sn10(5, 4), sn10(15, 0)); //bai 10
    printf("Bai 15: S(1) = %f, S(5) = %f, S(20) = %f\n", sn15(1), sn15(5), sn15(20)); //bai 15

    std::vector<int> bai20 = sn20(40); //bai 20
    std::cout << "Bai 20: 40 - > ";
    for (auto i : bai20) {
        std::cout << i << " ";
    }

    std::cout << "\nBai 21: 40 -> " << sn21(40) << std::endl; //bai 21
    printf("Bai 29: 100 -> %i; 250 -> %i; 1 -> %i\n", sn29(100), sn29(250), sn29(1)); //bai 29
    std::cout << "Bai 30: 6 => " << sn30(6) << "; 15 => " << sn30(15) << "; 496 => " << sn30(496) << std::endl; //bai 30
    std::cout << "Bai 31: 5 => " << sn31(5) << "; 15 => " << sn31(15) << "; 149 => " << sn31(149) << std::endl; //bai 31
    std::cout << "Bai 32: 0 => " << sn32(0) << "; 576 => " << sn32(576) << "; 149 => " << sn32(149) << std::endl; //bai 32
    printf("Bai 33: S(1) = %f, S(5) = %f, S(10) = %f\n", sn33(1), sn33(5), sn33(10)); //bai 33
    printf("Bai 35: S(1) = %f, S(5) = %f, S(10) = %f\n", sn35(1), sn35(5), sn35(10)); //bai 35
    printf("Bai 40: S(1) = %f, S(5) = %f, S(10) = %f\n", sn40(1), sn40(5), sn35(10)); //bai 40
    printf("Bai 41: S(0) = %f, S(5) = %f, S(10) = %f\n", sn41(0), sn41(5), sn41(10)); //bai 41
    printf("Bai 42: n = 5; k = %i, n = 15; k = %i, n = 51; k = %i\n", sn42(5), sn42(15), sn42(51)); //bai 42
    printf("Bai 43: n = 1; ans = %i, n = 10; ans = %i, n = 211; ans = %i\n", sn43(1), sn43(10), sn43(211)); //bai 43
    printf("Bai 45: n = 1; ans = %i, n = 523; ans = %i, n = 122; ans = %i\n", sn45(1), sn45(523), sn45(122)); //bai 45
    printf("Bai 46: n = 1; ans = %i, n = 351; ans = %i, n = 928312; ans = %i\n", sn46(1), sn46(351), sn46(928312)); // bai 46
    printf("Bai 50: n = 1; ans = %i, n = 24; ans = %i, n = 928341; ans = %i\n", sn50(1), sn50(24), sn50(928341)); // bai 50
    std::cout << "Bai 59: n = 12; ans = " << sn59(12) << ", n = 1331; ans = " << sn59(1331) << ", n = 148841; ans = " << sn59(148841) << std::endl; //bai 59
    std::cout << "Bai 61: n = 12; ans = " << sn61(123) << ", n = 1331; ans = " << sn61(321) << ", n = 148841; ans = " << sn61(9621) << std::endl; // bai 61

    std::cout << "Bai 65:\na = 1; b = 2; c = 3\n";
    sn65(1, 2, 3);
    std::cout << "a = 1; b = 5; c = 6\n";
    sn65(1, 5, 6);

    std::cout << "\nBai 75: n = 15; ans = " << sn75(15) << ", n = 16; ans = " << sn75(16) << ", n = 64; ans = " << sn75(64) << std::endl; // bai 75
}
