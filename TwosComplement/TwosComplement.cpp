#include <iostream>
#include <vector>
void printUnsignedNumbers(int arr[10])
{
	printf("Unsigned Numbers: ");
	for (int i = 0; i < 10; ++i)
		printf("%u, ", arr[i]);
}

void printSignedNumbers(int arr[10])
{
	printf("Signed Numbers: ");
	for (int i = 0; i < 10; ++i)
		printf("%d, ", arr[i]);
}

void printTwosComplement(int arr[10])
{
	for (int i = 0; i < 10; ++i)
	{ // get the index
		std::vector<int> temp;

		for (int j = 7; j >= 0; --j)
		{ // 8 bit representation
			int k = arr[i] >> j;
			if (k & 1)
				temp.push_back(1);
			else
				temp.push_back(0);
		}

		for (int j = temp.size() - 1; j >= 0; --j)
		{ // get one's complement
			if (temp[j] == 0)
				temp[j] = 1;
			else
				temp[j] = 0;
		}

		// add one to one's complement
		int c = 0;
		for (int j = temp.size() - 1; j >= 0; --j)
		{
			if (j == temp.size() - 1)
			{
				if (temp[j] == 0)
					temp[j] = 1;
				else
				{
					temp[j] = 0;
					c = 1;
				}
			}
			else
			{
				if (c == 1 && temp[j] == 0)
				{
					temp[j] = 1;
					c = 0;
				}
				else if (c == 1 && temp[j] == 1)
				{
					temp[j] = 0;
					c = 1;
				}
			}

		}

		for (int x = 0; x < temp.size(); ++x)
		{
			printf("%d", temp[x]);
		}
		std::cout << ", ";

	}
}

int main()
{
	int arr[10] = { 0, 1, 2, 126, 127, 128, 129, 130, 254, 255 };
	printUnsignedNumbers(arr);
	std::cout << "\n";
	printSignedNumbers(arr);
	std::cout << "\n";
	printTwosComplement(arr);
}