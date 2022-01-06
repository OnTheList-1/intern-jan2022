// 21. Tính tổng tất cả “ước số” của số nguyên dương n.

#pragma once
int sn21(int n) {
  std::vector<int> result;
  int sum = 0;
  for (int i = 1; i < n; ++i) {
    if (n % i == 0) {
      result.push_back(i);
    }
  }

  for (int i = 0; i < n; ++i) {
    sum += result[i];
  }
  return sum;
}