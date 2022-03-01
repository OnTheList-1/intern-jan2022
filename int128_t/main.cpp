#include "int128_t.h"

int main()
{
	int128_t test;
	int userInput = 0;
	bool flag = true;
	std::string strInput;

	while (flag)
	{
		std::cout << "1. Enter Expression.\n";
		std::cout << "2. Enter Decimal.\n";
		std::cout << "5. QUIT\n\n";
		std::cin >> userInput;

		switch (userInput)
		{
		case 1:
			std::cout << "Enter the expression: ";
			std::cin >> strInput;
			std::cout << test.GetPolishNotation(strInput) << "\n";
			break;
		case 2:
			test.ReadConsoleString();
			break;
		case 5:
			flag = false;
			break;
		default:
			break;
		}
	}
}