// 30. Cho số nguyên dương n. Kiểm tra số dương n có phải là số hoàn thiện hay
// không ?
#pragma once

bool sn30(int n) {
  int i = 1;
  int sum = 0;
  bool flag;
  while (i < n) {
    if (n % i == 0) {
      sum += i;
    }
    ++i;
  }
  if (n == sum) {
    flag = true;
  } else {
    flag = false;
  }
  return flag;
}
