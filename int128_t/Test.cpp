#include "int128_t.h"

void testConstructors()
{
	int128_t num1;
	int128_t num2("123");
	int128_t num3(num2);
	std::cout << "Testing constructors: \n";

	std::cout << "\nInt128_t() ... ";
	num1.PrintHex();
	std::cout << "\nInt128_t(std::string) ... ";
	num2.PrintHex();
	std::cout << "\nInt128_t(int128_t&)";
	num3.PrintHex();
	std::cout << "\n";
}

void testAdd()
{
	std::cout << "Testing Add: ";
	int128_t num1("123");
	int128_t num2("534123");

	std::cout << 123 << " + " << 534123 << " = ";
	int128_t num3(num1 + num2);

	num3.PrintHex();
	std::cout << "\n";

	std::cout << "Testing add negatives: ";
	int128_t num4("-123");
	int128_t num5("534123");

	std::cout << "-123" << " - " << "534123" << " = ";
	int128_t num6(num4 + num5);
	num6.PrintHex();
	std::cout << "\n";
}

void testSubtract()
{
	std::cout << "Testing Subtract: ";
	int128_t num1("83123554");
	int128_t num2("17294");
	std::cout << "83123554" << " - " << "17294" " = ";
	int128_t num3(num1 - num2);
	num3.PrintHex();
	std::cout << "\n";

	std::cout << "Testing subtract negatives: ";
	int128_t num4("-83123554");
	int128_t num5(num2);
	std::cout << "-83123554 - 17294 = ";
	int128_t num6(num4 - num5);
	num6.PrintHex();
	std::cout << "\n";
}

void testMultiply()
{
	std::cout << "Testing Multiply: ";
	int128_t num1("63");
	int128_t num2("384");
	std::cout << "63" << " * " << "384" << " = ";
	int128_t num3(num1 * num2);
	num3.PrintHex();
	std::cout << "\n";
}

void testDivide()
{

}

void testLogical()
{

}

void testBitwise()
{
	std::cout << "Left shift test: ";
	int128_t num5("52");
	num5 << 12;
	num5.PrintHex();

	std::cout << "\nRight shift test: ";
	int128_t num6("4");
	num6 >> 3;
	num6.PrintHex();
	std::cout << "\n";
}

void testConvertType()
{
	std::cout << "Testing Print: ";
	int128_t num1("123023459");
	std::cout << "\nPrint binary test: ";
	num1.PrintBinary();
	std::cout << "\n\n";

	std::cout << "\nPrint Decimal test: ";
	num1.PrintDecimal();
	std::cout << "\n\n";
}

void RunAllTests()
{
	std::cout << "Test Cases for int128_t datatype: \n";
	testConstructors();
	testAdd();
	testSubtract();
	testMultiply();
	testDivide();
	testLogical();
	testBitwise();
	testConvertType();
}