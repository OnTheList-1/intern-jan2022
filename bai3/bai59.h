// 59. Hãy kiểm tra số nguyên dương n có phải số đối xứng hay không?

#pragma once

bool sn59(int n) {
  int copy = 0;
  int temp = n;
  bool flag = true;
  while (n > 0) {
    copy = copy * 10 + n % 10;
    n /= 10;
  }
  if (copy != temp) flag = false;
  return flag;
}