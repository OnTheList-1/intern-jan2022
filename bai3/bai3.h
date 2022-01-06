#pragma once
// Tính S(n) = 1 + 1 /2 + 1 / 3 + … + 1 / 𝑛
#pragma once
double sn3(int n) {
  double result = 0.0;
  for (float i = 1.0; i <= n; ++i) {
    result += (1 / i);
  }

  return result;
};