#include <iostream>
#include <vector>

void printUnsignedNumbers(uint8_t arr)
{
	printf("%u\t\t\t", arr);
}

void printSignedNumbers(uint8_t num)
{
	int8_t result = -(((num >> 7) & 1) * (1 << 7));

	for (int8_t i = 0; i <= 6; ++i)
	{
		result += (((num >> i) & 1) * (1 << i));
	}

	printf("%d\t\t", result);
}

//void printTwosComplement(uint8_t arr[10])
//{
//	for (int i = 0; i < 10; ++i)
//	{ // get the index
//		std::vector<int> temp;
//
//		for (int j = 7; j >= 0; --j)
//		{ // 8 bit representation
//			int k = arr[i] >> j;
//			if (k & 1)
//				temp.push_back(1);
//			else
//				temp.push_back(0);
//		}
//
//		for (int j = temp.size() - 1; j >= 0; --j)
//		{ // get one's complement
//			if (temp[j] == 0)
//				temp[j] = 1;
//			else
//				temp[j] = 0;
//		}
//
//		// add one to one's complement
//		int c = 0;
//		for (int j = temp.size() - 1; j >= 0; --j)
//		{
//			if (j == temp.size() - 1)
//			{
//				if (temp[j] == 0)
//					temp[j] = 1;
//				else
//				{
//					temp[j] = 0;
//					c = 1;
//				}
//			}
//			else
//			{
//				if (c == 1 && temp[j] == 0)
//				{
//					temp[j] = 1;
//					c = 0;
//				}
//				else if (c == 1 && temp[j] == 1)
//				{
//					temp[j] = 0;
//					c = 1;
//				}
//			}
//
//		}
//
//		for (int x = 0; x < temp.size(); ++x)
//		{
//			printf("%d", temp[x]);
//		}
//		std::cout << ", ";
//
//	}
//}

void printTwosComplement(uint8_t arr)
{

	arr = ~arr;
	arr = arr + 1;

	for (int j = 7; j >= 0; --j)
	{
		int x = arr & (1 << j);
		if (x == 0)
			std::cout << 0;
		else
			std::cout << 1;
	}
	std::cout << "\n";
}

signed int TwosComplementToSignedInt(uint8_t arr[8])
{
	signed int msb = -arr[0] * std::pow(2, 7);
	signed int result = 0;
	result += msb;
	int exp = 0;
	for (int i = 7; i >= 1; --i)
	{
		result += arr[i] * std::pow(2, exp);
		++exp;
	}

	return result;
}

void TwosComplementToSignedInt1(uint8_t num)
{

	int8_t result = -(((num >> 7) & 1) * (1 << 7));

	for (int8_t i = 0; i <= 6; ++i)
	{
		result += (((num >> i) & 1) * (1 << i));
	}

	printf("%d\n", result);
	//std::cout << result << "\n";
}

void getBit(uint8_t arr)
{
	for (int j = 7; j >= 0; --j)
		std::cout << ((arr >> j) & 1);

	std::cout << "\t";

}

int main()
{
	uint8_t arr[10] = { 0, 1, 2, 126, 127, 128, 129, 130, 254, 255 };
	uint8_t binary[8] = { 1, 0, 0, 0, 0, 0, 1, 1 }; //125
	uint8_t binary1[8] = { 0, 1, 1, 1, 1, 1, 0, 1 };//-125
	printf("Bits\t | Unsigned Value\t | Signed Value\t | Two's Complement\n");
	for (int i = 0; i < 10; ++i)
	{
		getBit(arr[i]);
		printUnsignedNumbers(arr[i]);
		printSignedNumbers(arr[i]);
		TwosComplementToSignedInt1(arr[i]);
	}


	//printSignedNumbers(arr);
	//std::cout << TwosComplementToSignedInt(binary) << "\t" << TwosComplementToSignedInt(binary1);
	//std::cout << "\n" << TwosComplementToSignedInt1(arr22);

}