#pragma once

#include <vector>

//  helper  //
bool isPrime(const int&);

//  Interface   //

float findLargestValueMatrix(const std::vector<std::vector<float>>&); //bai 315
bool isBai316(const std::vector<std::vector<int>>&); //bai 316
int countPrimeInMatrix(const std::vector<std::vector<int>>&); //bai 317
void sortMatrix(std::vector<std::vector<float>>&); //bai 319
float sumPositiveinMatrix(const std::vector<std::vector<float>>&); //bai 320
void sumRowinMatrix(const std::vector<std::vector<float>>&); //bai 322
void calculateProductofColumn(const std::vector<std::vector<float>>&); //bai 323
void sumOddNumberinColumn(const std::vector<std::vector<int>>&); //bai 332
int countXinMatrix(const std::vector<std::vector<float>>&, const int& x); //bai 336
int countExtremeValueinMatrix(const std::vector<std::vector<float>>&); //bai 342
void printRowEven(const std::vector<std::vector<int>>&); //bai 358
void printBai361(const std::vector<std::vector<float>>&); //bai 361
float findModeMatrix(const std::vector<std::vector<float>>&); //bai 381
int findMostAppearDigit(const std::vector<std::vector<int>>&); //bai 384
void listColumnWithMostDigit(const std::vector<std::vector<int>>&); //bai 390
void buildBFromA428(std::vector<std::vector<int>>); //bai 428
