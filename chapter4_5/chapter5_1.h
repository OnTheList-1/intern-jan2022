#pragma once

#include <vector>

//helper
bool isOdd(const std::string&);
float roundFloat(float& a);

int countAinB(const std::vector<float>&, const std::vector<float>&); //bai 236
void listModeInArray(const std::vector<int>&); //bai 238
bool isConsecutiveZeros(const std::vector<int>&); //bai 241
bool isSymetricalArray(const std::vector<float>&); //bai 246
bool isDescendingArray(const std::vector<float>&); //bai 249
void sortArrayDescending(std::vector<float>&); //bai 256
void sortArrayOddAscending(std::vector<float>&); //bai 257
void sortArrayPositiveAscending(std::vector<float>&); //bai 261
void sortArrayBai263(std::vector<float>&); //bai 263
void insertAtK(int*, int, const int&); //bai 266
void sortWhileInsert(float*, const int&);//bai 267
void deleteAllK(float*, int&, const float&); //bai 271
void deleteEvenNumbers(int*, int&); //bai 274
void deleteDuplicates(int*, int&); //bai 279
void sortBai281(int*, const int&); //bai 281
void reverseArray(int*, const int&); //bai 283
void reverseEvenPosition(int*, const int&); //bai284
void rotateArray(int*, const int&); //bai 286
void rotateArrayKTimes(int*, const int&, const int&); //bai 287
void printBai289(const int*, const int&); //bai 289
void arrayToInt(float*, const int&); //bai 292
void listArraySubset(int* array, const int& size); //bai 293
void listSubsetAscending(int* array, const int& size); //bai 295
void subsetSumM(int*, const int&, const int&); //bai 304
void positiveSubsetLargestSum(int*, const int&); // bai 305
void createArrayBai309(float*, const int&); //bai 309

