// 45. Hãy tính tích các chữ số của số nguyên dương n.

#pragma once

int sn45(int n) {
  int result = 1;
  int i = 0;
  while (n > 0) {
    n /= 10;
    result *= ++i;
  }
  return result;
}