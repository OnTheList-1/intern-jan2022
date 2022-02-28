#pragma once

#include <fstream>
#include <iostream>
#include <string>

class int128_t
{
public:
	int128_t();


	void ReadConsoleString();
	void PrintConsoleString();
	void PrintConsoleBinary();

private:
	uint64_t lo;
	uint64_t hi;
};