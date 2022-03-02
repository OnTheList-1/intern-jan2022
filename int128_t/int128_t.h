#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <stack>

#define BYTE_SIZE 16
#define BIT_SIZE 127

class int128_t
{
public:
	int128_t();
	int128_t(const std::string&);
	int128_t(const int128_t&);


	void ReadConsoleString();
	void PrintConsoleHex();
	void PrintConsoleBinary();
	void ConvertToTwosComplement();

	void SetBit(const size_t&);
	void UnsetBit(const size_t&);
	void ToggleBit(const size_t&);
	char GetBit(const size_t&);

	std::string StringToBinary(std::string);
	std::string GetPolishNotation(std::string);

	friend int128_t operator+(const int128_t&, const int128_t&); //implemented
	friend int128_t operator-(const int128_t&, const int128_t&); //implemented
	friend int128_t operator*(const int128_t&, const int128_t&);
	friend int128_t operator/(const int128_t&, const int128_t&);
	friend bool operator>(const int128_t&, const int128_t&);//implemented
	friend bool operator>=(const int128_t&, const int128_t&); //implemented
	friend bool operator<(const int128_t&, const int128_t&); //implemented
	friend bool operator<=(const int128_t&, const int128_t&); //implemented
	friend bool operator==(const int128_t&, const int128_t&); //implemented
	friend bool operator!=(const int128_t&, const int128_t&); //implemented


private:
	uint8_t bin[BYTE_SIZE];
};

