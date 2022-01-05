// 43. Hãy đếm số lượng chữ số của số nguyên dương n
#pragma once

int sn43(int n) {
  int result = 0;
  while (n > 0) {
    n /= 10;
    ++result;
  }
  return result;
}