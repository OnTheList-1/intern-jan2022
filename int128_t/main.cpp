#include "int128_t.h"
#include "Test.h"
int main()
{
	RunAllTests();
	int128_t test;
	int userInput = 0;
	bool flag = true;
	std::string strInput;


	while (flag)
	{
		std::cout << "1. Enter Decimal.\n";
		std::cout << "2. Enter Expression to get Polish Notation.\n";
		std::cout << "3. Enter Polish Notation: \n";
		std::cout << "5. QUIT\n\n";
		std::cin >> userInput;

		switch (userInput)
		{
		case 1:
			test.ReadConsoleString();
			break;
		case 2:
			std::cout << "Enter the expression: ";
			std::cin >> strInput;
			std::cout << test.GetPolishNotation(strInput) << "\n";
			break;

		case 3:
			std::cout << "Enter the Polish Notation: ";
			std::cin >> strInput;
			test.evalPolishNotation(strInput);
		case 5:
			flag = false;
			break;
		default:
			break;
		}
	}

}

/*

	Make sure to check and deal with all cases when the number is negative.
		- Start with increment and decrement
		- Then bool operators
		- Then + - * /

*/