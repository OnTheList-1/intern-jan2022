#include "int128_t.h"

int main()
{
	int128_t test;
	int userInput = 0;
	bool flag = true;
	std::string strInput;

	int128_t num1("121");
	int128_t num2("9");
	int128_t num3;
	num3 = num1 + num2;
	std::cout << "Addition Test:\nnum1 + num2 = ";
	num3.PrintConsoleHex();
	std::cout << "\n";

	std::cout << "Subtraction Test:\nnum1 + num2 = ";
	int128_t num4;
	num4 = num1 - num2;
	num4.PrintConsoleHex();
	std::cout << "\n";

	std::cout << "bool operators test: ";

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