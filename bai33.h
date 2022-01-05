// 33. Tính S(n) = √2 + √2 + √2 + ⋯ √2 + √2 có n dấu căn

#pragma once

double sn33(int n) {
  double result = 0;
  int i = 0;
  while (i < n) {
    result = sqrt(2 + result);
    ++i;
  }
  return result;
}
