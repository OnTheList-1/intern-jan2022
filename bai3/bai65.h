// 66. Giải phương trình 𝑎𝑥4 + 𝑏𝑥 2 + 𝑐 = 0.

#pragma once

std::vector<float> sn65(int a, int b, int c) {
  std::vector<float> result;
  float deltaPos = (-b + (pow(b, 2) - 4 * a * c)) / (2 * a);
  float deltaNeg = (-b - (pow(b, 2) - 4 * a * c)) / (2 * a);
  result.push_back(deltaPos);
  result.push_back(deltaNeg);
  return result;
}