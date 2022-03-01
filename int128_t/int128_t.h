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
	int128_t(std::string); // work on this tmr
	int128_t(int);		   // work on this tmr


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

	int128_t operator+(const int128_t&);
	int128_t operator-(const int128_t&);


private:
	uint8_t bin[BYTE_SIZE];
};