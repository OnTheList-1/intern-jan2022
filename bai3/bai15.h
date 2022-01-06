// 15. Tính S(n)

#pragma once
double sn15(int n) {
  double result = 0;
  int sum = 0;

  for (float i = 1.0; i <= n; ++i) {
    sum += i;
    result += (float)1 / (sum);
  }

  return result;
}