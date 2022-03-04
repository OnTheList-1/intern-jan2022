#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <vector>

#define BYTE_SIZE 16
#define BIT_SIZE 126

class int128_t
{
public:
	int128_t(); //implemented
	int128_t(const std::string&); //implemented
	int128_t(const int128_t&); //implemented


	void ReadConsoleString(); //implemented
	std::vector<int128_t> ReadTextFile(const std::string&); //implemented
	std::vector<int128_t> ReadBinaryFile(const std::string&);  //implemented
	void WriteBinaryFile(const std::string&, std::vector<int128_t>, const bool&); //implemented
	void WriteTextFile(const std::string&, std::vector<int128_t>); //implemented

	void ConvertToTwosComplement(); //implemented ?
	void PrintDecimal(); //implemented

	void SetBit(const size_t&); //implemented
	void UnsetBit(const size_t&); //implemented
	void ToggleBit(const size_t&); //implemented
	char GetBit(const size_t&); //implemented

	std::string StringToBinary(std::string); //implemented
	std::string BinaryToString(); //implemented
	std::string int128ToDecimal(); //implemented
	void BigEndianToLittleEndian(); //implemented

	std::string GetPolishNotation(std::string); //implemented
	void evalPolishNotation(const std::string&); //implemented

	friend int128_t operator+(const int128_t&, const int128_t&); //implemented
	friend int128_t operator-(const int128_t&, const int128_t&); //implemented
	friend int128_t operator*(const int128_t&, const int128_t&); //implemented
	friend int128_t operator/(const int128_t&, const int128_t&); //implemented
	friend bool operator>(const int128_t&, const int128_t&);//implemented
	friend bool operator>=(const int128_t&, const int128_t&); //implemented
	friend bool operator<(const int128_t&, const int128_t&); //implemented
	friend bool operator<=(const int128_t&, const int128_t&); //implemented
	friend bool operator==(const int128_t&, const int128_t&); //implemented
	friend bool operator!=(const int128_t&, const int128_t&); //implemented
	int128_t& operator++(); //implemented
	int128_t& operator++(int); //implemented
	int128_t& operator--(); //implemented
	int128_t& operator--(int); //implemented
	int128_t& operator<<(const int&); //implemented
	int128_t& operator>>(const int&); //implemented

	friend bool operator>(const int128_t&, const int&); //implemented
	friend bool operator<(const int128_t&, const int&); //implemented
	friend bool operator==(const int128_t&, const int&); //implemented

private:
	uint8_t bin[BYTE_SIZE];
};

