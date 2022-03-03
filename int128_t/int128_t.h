#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <fstream>

#define BYTE_SIZE 16
#define BIT_SIZE 127

class int128_t
{
public:
	int128_t(); //implemented
	int128_t(const std::string&); //implemented
	int128_t(const int128_t&); //implemented


	void ReadConsoleString(); //implemented
	void ReadBinaryFile(const std::string&);
	void WriteBinaryFile(const std::string&);

	void ConvertToTwosComplement(); //implemented ?
	void PrintBinary(); //implemented
	void PrintDecimal(); //implemented
	void PrintHex(); //implemented

	void SetBit(const size_t&); //implemented
	void UnsetBit(const size_t&); //implemented
	void ToggleBit(const size_t&); //implemented
	char GetBit(const size_t&); //implemented

	std::string StringToBinary(std::string); //implemented
	std::string BinaryToString();
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

private:
	uint8_t bin[BYTE_SIZE];
};

