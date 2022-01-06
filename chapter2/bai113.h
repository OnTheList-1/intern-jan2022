// Lập chương trình sin(x) với độ chính xác 0.00001 theo công thức:

#pragma once
#define epsilon 1e-5

double findSin(double rad) {
    double result;
    double factorial = 1;
    double exponent;
    double sign = -1;
    int i = 3;
    double compute;
    result = rad, compute = rad, exponent = rad;

    for (i; compute > epsilon; i += 2, sign = -sign) {
        compute = (exponent *= rad * rad) / (factorial *= i * (i - 1));
        result += sign * compute;
    }
    return result;
}