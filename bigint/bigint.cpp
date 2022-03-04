#include <iostream>

#include "bigint.h"

bigint::bigint()
{
	negative = false;
	digit[0] = '\0';
}

bigint& bigint::operator+=(const bigint& b)
{

}

void bigint::ReadConsole()
{
	std::string userInput;
	bool checkInput = true;


	while (checkInput && CheckSize())
	{
		std::cout << "Enter your number: ";

		std::cin >> userInput;
		if (userInput.length() > 40)
			std::cout << "bigint can only values from " << MIN_BIGINT << " to " << MAX_BIGINT << "\n";

		else
		{
			if (userInput[0] == '-')
			{ // if negative number
				negative = true;
				digit[0] = '-';
				int i = 0;
				for (i; i < userInput.length(); ++i)
				{
					digit[i] = userInput[i];
				}
				digit[i] = '\0';
			}
			else
			{ //if positive number
				negative = false;
				int i = 0;
				for (i; i < userInput.length(); ++i)
				{
					digit[i] = userInput[i];
				}
				digit[i] = '\0';
			}
			checkInput = false;
		}

	}

}

void bigint::DisplayConsole()
{
	std::cout << "Your number is: ";

	int i = 0;
	while (digit[i] != '\0')
	{
		std::cout << digit[i];
		++i;
	}
}

void bigint::Clear()
{
	for (int i = 0; i < 41; ++i)
	{
		digit[i] = NULL;
	}
	digit[0] = '\0';
}

bool bigint::CheckSize()
{
	for (int i = 0; i < 40; ++i)
	{
		if (!negative && digit[i] != '\0')
		{
			if ((digit[i] - '0') > (MAX_BIGINT[i] - '0'))
			{
				return false;
			}
		}
	}
	return true;

}

bool bigint::GetSign() const
{ // if true then has sign
	if (digit[0] == '-')
		return true;

	return false;
}

int bigint::GetSize() const
{
	if ()
}