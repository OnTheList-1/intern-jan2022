#include "int128_t.h"

int128_t::int128_t()
{
	lo = 0;
	hi = 0;
}

void int128_t::ReadConsoleString()
{
	std::cout << "Enter A Number: ";
	std::string userInput;
	std::cin >> userInput;

	int inputLength = userInput.length();

	while (inputLength > 0)
	{
		if (inputLength < 20)
		{
			lo *= 10;
			lo += userInput[inputLength - 1] % 2;
		}
		else
		{
			hi *= 10;
			hi += userInput[inputLength - 1] % 2;
		}

	}
}