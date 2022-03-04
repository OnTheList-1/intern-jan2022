#include "int128_t.h"

void testConstructors()
{
	int128_t num1;
	int128_t num2("123");
	int128_t num3(num2);
	std::cout << "Testing constructors: \n";
}

void testAdd()
{
	std::cout << "Testing Add: ";
	int128_t num1("123");
	int128_t num2("534123");

	std::cout << 123 << " + " << 534123 << " = ";
	int128_t num3(num1 + num2);

	num3.PrintDecimal();
	std::cout << "\n";

	std::cout << "Testing add negatives: ";
	int128_t num4("-123");
	int128_t num5("534123");

	std::cout << "-123" << " - " << "534123" << " = ";
	int128_t num6(num4 + num5);
	num6.PrintDecimal();
	std::cout << "\n";
}

void testSubtract()
{
	std::cout << "Testing Subtract: ";
	int128_t num1("83123554");
	int128_t num2("17294");
	std::cout << "83123554" << " - " << "17294" " = ";
	int128_t num3(num1 - num2);
	num3.PrintDecimal();
	std::cout << "\n";

	std::cout << "Testing subtract negatives: ";
	int128_t num4("-83123554");
	int128_t num5(num2);
	std::cout << "-83123554 - 17294 = ";
	int128_t num6(num4 - num5);
	num6.PrintDecimal();
	std::cout << "\n";
}

void testMultiply()
{
	std::cout << "Testing Multiply: ";
	int128_t num1("63");
	int128_t num2("384");
	std::cout << "63" << " * " << "384" << " = ";
	int128_t num3(num1 * num2);
	num3.PrintDecimal();
	std::cout << "\n";
}

void testDivide()
{
	int128_t num1("3750");
	int128_t num2("75");

	std::cout << "Testing division ...";

	int128_t num3(num1 / num2);
	num3.PrintDecimal();
	std::cout << "\n";

}

void testLogical()
{

}

void testReadFileText(std::vector<int128_t>& data)
{
	std::cout << "Read Text File Test: ";
	std::string file_path = "bin_file.txt";
	int128_t num;
	data = num.ReadTextFile(file_path);
	for (int i = 0; i < data.size(); ++i)
	{
		data[i].PrintDecimal();
		std::cout << " ";
	}
	std::cout << "\n";
}

void testReadFileBinary(std::vector<int128_t>& data1, std::vector<int128_t>& data2)
{
	std::cout << "Test read file binary ... \n";
	std::cout << "Testing Big Endian file: ";
	std::string file_path = "sample.bin";
	int128_t num;
	data1 = num.ReadBinaryFile(file_path);
	for (int i = 0; i < data1.size(); ++i)
	{
		data1[i].PrintDecimal();
		std::cout << " ";
	}

	std::cout << "\nTesting Little Endian file: ";
	std::string file_path1 = "sample_le.bin";
	int128_t num1;
	data2 = num1.ReadBinaryFile(file_path1);
	for (int i = 0; i < data2.size(); ++i)
	{
		data2[i].PrintDecimal();
		std::cout << " ";
	}
	std::cout << "\n";
}

void testWriteToFileText(std::vector<int128_t>& data3)
{
	int128_t num;
	num.WriteTextFile("write_text.txt", data3);
}

void testWriteToFileBinary(std::vector<int128_t> data0, std::vector<int128_t>data1)
{
	int128_t num;
	num.WriteBinaryFile("write_binary.txt", data0, true);

	int128_t num1;
	num1.WriteBinaryFile("write_binary_le.txt", data1, false);
}

void testBitwise()
{
	std::cout << "Left shift test: ";
	int128_t num5("52");
	num5 << 12;
	num5.PrintDecimal();

	std::cout << "\nRight shift test: ";
	int128_t num6("4");
	num6 >> 3;
	num6.PrintDecimal();
	std::cout << "\n";
}

void testConvertType()
{
	std::cout << "Testing Print: ";
	int128_t num1("123023459");
	std::cout << "\nPrint binary test: ";
	num1.PrintDecimal();
	std::cout << "\n\n";

	std::cout << "\nPrint Decimal test: ";
	num1.PrintDecimal();
	std::cout << "\n\n";
}

void RunAllTests()
{
	std::vector<int128_t> data0;
	std::vector<int128_t> data1;
	std::vector<int128_t> data2;

	std::cout << "Test Cases for int128_t datatype: \n";
	testConstructors();
	testAdd();
	testSubtract();
	testMultiply();
	testDivide();
	testLogical();
	testBitwise();
	testConvertType();
	testReadFileText(data0);
	testReadFileBinary(data1, data2);
	testWriteToFileText(data0);
	testWriteToFileBinary(data1, data2);
}