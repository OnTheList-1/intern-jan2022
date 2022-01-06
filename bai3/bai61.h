// 61. Hãy kiểm tra các chữ số của số nguyên dương n có giảm dần từ trái sang
// phải hay không ?

#pragma once

bool sn61(int n) {
  bool flag = true;
  int i = n % 10;
  n /= 10;
  while (n > 0) {
    if (i > n % 10) {
      flag = false;
    }
    i = n % 10;
    n /= 10;
  }

  return flag;
}