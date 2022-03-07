#include "int128_t.h"

#pragma region Polish Notation

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	return false;
}

bool isOperand(char c)
{
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
		return true;
	else
		return false;
}

int precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;

	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;
}

bool equalOrHigher(char op1, char op2)
{
	if (precedence(op1) == precedence(op2))
	{
		if (op1 == '^')
			return false;

		return true;
	}

	return precedence(op1) > precedence(op2) ? true : false;

}

int128_t operation(int128_t a, int128_t b, char op)
{
	int128_t zero("0");
	if (op == '+')
		return a + b;
	else if (op == '-')
		return a - b;
	else if (op == '*')
		return a * b;
	else if (op == '/')
		return a / b;
	else
		return zero;
}

std::string infixToPostfix(std::string infix)
{
	std::stack <char> s;
	std::string postfix = "";
	char ch;

	s.push('(');
	infix += ')';

	for (int i = 0; i < infix.length(); i++)
	{
		ch = infix[i];

		if (ch == ' ')
			continue;
		else if (ch == '(')
			s.push(ch);

		else if (isOperand(ch))
			postfix += ch;

		else if (isOperator(ch))
		{
			while (!s.empty() && equalOrHigher(s.top(), ch))
			{
				if (s.top() == ')')
					postfix += s.top();
				s.pop();
			}
			s.push(ch);
		}
		else if (ch == ')')
		{
			while (!s.empty() && s.top())
			{
				postfix += s.top();
				s.pop();
			}

		}
	}
	return postfix;
}

int128_t postfixEval(const std::string& postfix)
{
	int128_t a;
	int128_t b;
	std::string infix;
	std::stack<int128_t> s;

	for (int i = 0; i < postfix.length(); ++i)
	{
		if (!isOperator(postfix[i]))
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push(operation(a, b, postfix[i]));
		}
		else if (isOperand(postfix[i]))
		{
			std::string t;
			t.push_back(postfix[i]);
			s.push(t);
		}
	}
	return s.top();
}

std::string int128_t::GetPolishNotation(std::string in)
{
	return infixToPostfix(in) + '\n';
}

void int128_t::evalPolishNotation(const std::string& rhs)
{
	*this = postfixEval(rhs);
	PrintDecimal();
}

#pragma endregion

#pragma region Constructor

int128_t::int128_t()
{
	memset(bin, 0, BYTE_SIZE);
}

int128_t::int128_t(const std::string& in)
{
	memset(bin, 0, BYTE_SIZE);
	StringToBinary(in);
}

int128_t::int128_t(const int128_t& rhs)
{
	memcpy_s(bin, BYTE_SIZE, rhs.bin, BYTE_SIZE);
}

int128_t::int128_t(uint8_t buffer[BYTE_SIZE])
{
	memset(bin, 0, BYTE_SIZE);
	for (size_t i = 0; i < BYTE_SIZE; ++i)
	{
		bin[i] = buffer[i];
	}
}

#pragma endregion

#pragma region Read and Write

void int128_t::ReadConsoleString()
{
	std::string userInput;
	bool checkInput = true;

	std::cout << "Enter your number: ";
	std::cin >> userInput;

	StringToBinary(userInput);
	std::cout << "\nDecimal Representation: ";
	PrintDecimal();
	std::cout << "\n";
}

std::vector<int128_t> int128_t::ReadTextFile(const std::string& file_path)
{
	std::vector<int128_t> data;
	std::ifstream MyFile(file_path);

	if (!MyFile)
		std::cout << "can't locate the specified file path\n";
	else
	{
		char ch;
		MyFile >> ch;
		unsigned int n = ch - '0';
		std::string decimal = "";
		MyFile.get(ch);
		ch = 0;
		for (unsigned int i = 0; i < n; i)
		{
			MyFile.get(ch);
			if (ch == ' ' || MyFile.eof())
			{
				int128_t temp(decimal);
				data.push_back(temp);
				decimal = "";
				++i;
			}
			else
			{
				decimal += ch;
			}

		}
	}
	MyFile.close();
	return data;
}

std::vector<int128_t> int128_t::ReadBinaryFile(const std::string& file_path)
{
	std::vector<int128_t> data;
	std::ifstream MyFile(file_path, std::ios::binary);

	if (!MyFile)
		std::cout << "Can't locate the specified file path.";
	else
	{
		uint16_t buffer;
		uint8_t buffer1[BYTE_SIZE];
		uint16_t bigEndian = 0xfffe;
		uint16_t littleEndian = 0xfeff;

		// Read first two bytes
		MyFile.read((char*)&buffer, 2);

		if (buffer == littleEndian)
		{ // little endian

			//get the length of the file[n]
			MyFile.read((char*)&buffer1, 16);
			int128_t length(buffer1);
			length.BigEndianToLittleEndian();

			for (int i = 0; length > i; ++i)
			{
				memset(buffer1, 0, sizeof(BYTE_SIZE));
				MyFile.read((char*)&buffer1, 16);
				int128_t num(buffer1);
				num.BigEndianToLittleEndian();
				data.push_back(num);
			}

		}
		else if (buffer == bigEndian)
		{ // big endian
			// Get the length of the file [n]
			MyFile.read((char*)&buffer1, 16);
			int128_t length(buffer1);

			for (int i = 0; length > i; ++i)
			{ // loop till n; where n = length
				memset(buffer1, 0, sizeof(BYTE_SIZE));
				MyFile.read((char*)&buffer1, 16);
				int128_t num(buffer1);
				data.push_back(num);
			}
		}
		else
		{
			std::cout << "Can't read the file's bom.\n";
			return data;
		}
	}

	std::cout << "\n";

	MyFile.close();
	return data;
}

void int128_t::WriteTextFile(const std::string& file_path, std::vector<int128_t> data)
{
	std::ofstream MyFile(file_path);
	std::string length;

	// print the size
	length = std::to_string(data.size());
	MyFile << length << " ";
	if (MyFile)
	{
		for (int i = 0; i < data.size(); ++i)
		{
			std::string dataString = data[i].int128ToDecimal();
			MyFile << dataString << " ";
		}
	}
	else
	{
		std::cout << "can't create the file";
	}
	MyFile.close();
}

void int128_t::WriteBinaryFile(const std::string& file_path, std::vector<int128_t>data, const bool& bom)
{
	std::ofstream MyFile(file_path, std::ios::binary | std::ios::out);
	uint16_t bigEndian = 65279;
	uint16_t littleEndian = 65534;
	std::string length = std::to_string(data.size());
	int128_t length1(length);

	// Write first two bytes bom
	if (bom)
	{
		// Write length
		MyFile.write((char*)&littleEndian, sizeof(uint16_t));
		length1.BigEndianToLittleEndian();
		MyFile.write((char*)&length1, sizeof(int128_t));
	}
	else
	{
		MyFile.write((char*)&bigEndian, sizeof(uint16_t));
		MyFile.write((char*)&length1, sizeof(int128_t));
	}


	if (MyFile)
	{
		if (bom == false)
		{ // little endian
			for (int i = 0; i < data.size(); ++i)
			{
				data[i].BigEndianToLittleEndian();
				MyFile.write((char*)&data[i], sizeof(int128_t));
			}
		}
		else
		{ // big endian
			for (int i = 0; i < data.size(); ++i)
			{
				MyFile.write((char*)&data[i], sizeof(int128_t));
			}
		}
	}


	MyFile.close();
}

#pragma endregion

#pragma region Print and Convert
// Print & Convert

void int128_t::ConvertToTwosComplement()
{
	for (int i = 0; i < BIT_SIZE + 1; ++i)
	{ // flip bit
		ToggleBit(i);
	}

	int128_t one("1");
	*this = *this + one;

}

void int128_t::PrintDecimal()
{
	std::cout << int128ToDecimal();

}

#pragma endregion

#pragma region Overload Operators
// Overload Operators

int128_t operator+(const int128_t& rhs1, const int128_t& lhs1)
{
	bool carry = false;
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (size_t i = 0; i < BIT_SIZE; ++i)
	{
		if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
		{
			if (carry == true)
				rhs.UnsetBit(i);
			else
			{
				rhs.SetBit(i);
			}
			continue;
		}
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
		{
			if (carry == true)
				rhs.SetBit(i);
			else
			{
				carry = true;
				rhs.UnsetBit(i);
			}
			continue;

		}
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
				rhs.UnsetBit(i);
			else
				rhs.SetBit(i);
			continue;
		}
		if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
			{
				rhs.SetBit(i);
				carry = false;
			}
			else
				rhs.UnsetBit(i);
			continue;
		}
	}
	return rhs;
}

int128_t operator-(const int128_t& rhs1, const int128_t& lhs1)
{
	bool carry = false;
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (size_t i = 0; i < BIT_SIZE; ++i)
	{
		if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
		{
			if (carry == true)
				rhs.UnsetBit(i);
			else
			{
				rhs.SetBit(i);
				carry = true;
			}
			continue;
		}
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
		{
			if (carry == true)
				rhs.SetBit(i);
			else
			{
				rhs.UnsetBit(i);
			}
			continue;

		}
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
			{
				carry = false;
				rhs.UnsetBit(i);
			}
			else
				rhs.SetBit(i);
			continue;
		}
		if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
			{
				rhs.SetBit(i);
				carry = false;
			}
			else
				rhs.UnsetBit(i);
			continue;
		}
	}

	return rhs;

}

int128_t operator*(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);
	int128_t zero("0");
	int128_t one("1");

	if (rhs == zero || lhs == zero)
		return zero;

	if (rhs == one)
		return lhs;

	if (lhs == one)
		return rhs;

	int128_t result;

	while (!(lhs == zero))
	{

		if (lhs.GetBit(0) & 1)
		{
			result = result + rhs;
		}
		rhs << 1;
		lhs >> 1;
	}

	return result;
}

int128_t operator/(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);
	int128_t one("1");
	int128_t zero("0");
	int128_t result;
	int128_t temp("1");
	if (lhs == rhs)
		return one;
	if (rhs < lhs)
		return zero;

	while (lhs <= rhs)
	{
		lhs = lhs << 1;
		temp = temp << 1;
	}

	while (temp > one)
	{
		lhs = lhs >> 1;
		temp = temp >> 1;
		if (rhs >= lhs)
		{
			rhs = rhs - lhs;
			result = result + temp;
		}
	}


	return result;
}

bool operator==(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (size_t i = 0; i < BIT_SIZE; ++i)
	{
		if (rhs.GetBit(i) != lhs.GetBit(i))
			return false;
	}
	return true;
}

bool operator!=(const int128_t& rhs1, const int128_t& lhs1)
{
	return !(rhs1 == lhs1);
}

bool operator<(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
			return false;
		if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
			return true;
	}
	return false;
}

bool operator<=(const int128_t& rhs1, const int128_t& lhs1)
{
	return (rhs1 < lhs1) || (rhs1 == lhs1);
}

bool operator>(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
			return true;
		if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
			return false;
	}

	return false;
}

bool operator>=(const int128_t& rhs1, const int128_t& lhs1)
{
	return (rhs1 > lhs1) || (rhs1 == lhs1);
}

int128_t& int128_t::operator++()
{ //prefix increment
	int128_t temp("1");
	*this = *this + temp;
	return *this;
}

int128_t& int128_t::operator++(int)
{ //postfix increment
	int128_t temp = *this;
	++(*this);
	return temp;
}

int128_t& int128_t::operator--()
{ //prefix decrement
	int128_t temp("1");
	*this = *this - temp;
	return *this;
}

int128_t& int128_t::operator--(int)
{ //postfix decrement
	int128_t temp = *this;
	--(*this);
	return temp;
}

int128_t& int128_t::operator<<(const int& pos)
{
	for (int i = BIT_SIZE; i >= 0; --i)
	{ // set bit @ i - pos
		if (GetBit(i) == 1)
			if (i + pos <= BIT_SIZE)
			{
				SetBit(i + pos);
				UnsetBit(i);
			}
			else
				UnsetBit(i);
	}


	return *this;
}

int128_t& int128_t::operator>>(const int& pos)
{
	for (int i = 0; i < BIT_SIZE; ++i)
	{
		if (GetBit(i) == 1)
			if (i - pos >= 0)
			{
				SetBit(i - pos);
				UnsetBit(i);
			}
			else
				UnsetBit(i);
	}
	return *this;
}

bool operator>(const int128_t& rhs, const int& lhs1)
{
	int128_t lhs(std::to_string(lhs1));

	return rhs > lhs;
}

bool operator<(const int128_t& rhs, const int& lhs1)
{
	int128_t lhs(std::to_string(lhs1));

	return rhs < lhs;
}

bool operator==(const int128_t& rhs, const int& lhs1)
{
	int128_t lhs(std::to_string(lhs1));

	return rhs == lhs;
}

#pragma endregion

#pragma region Conversion

// Conversion

void int128_t::StringToBinary(std::string in)
{
	bool flag = false;
	if (in[0] == '-')
	{ // if it's a negative number
		flag = true;
		in = in.substr(1, in.length() - 1);
		SetBit(BIT_SIZE);
	}

	for (size_t i = 0; i < in.length(); ++i)
		in[i] -= '0';
	int c = 1;
	int count = 0;
	while (in.length()) {
		if ((in[in.length() - 1] & 1) == 1)
			SetBit(count);
		else
			UnsetBit(count);
		++count;

		char overflow = 0;
		if (in[0] <= 1) {
			overflow = 10;
			if (c > in.length())
				in.erase();
			else
			{
				in = in.substr(c, in.length());
			}

		}
		for (size_t i = 0; i < in.length(); ++i) {
			in[i] += overflow;
			overflow = 10 * (in[i] & 1);
			in[i] /= 2;
		}
	}

	//if (flag == true)
		//this->ConvertToTwosComplement();

}

std::string int128_t::BinaryToString()
{
	std::string result;
	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (GetBit(i) == 1)
			result.push_back('1');
		else if (GetBit(i) == 0)
			result.push_back('0');
	}

	return result;
}

std::string int128_t::int128ToDecimal()
{
	std::string binAsString = BinaryToString();
	std::string result{};
	bool flag = false;

	constexpr unsigned int numberBase{ 10 };

	if (GetBit(BIT_SIZE) == 1)
	{
		UnsetBit(BIT_SIZE);
		flag = true;
		binAsString = BinaryToString();
	}

	do {

		unsigned int remainder{};
		std::string dividedNumberAsString{};

		for (const char bit : binAsString)
		{
			remainder = remainder * 2 + (bit - '0');

			if (remainder >= numberBase)
			{ //overflow i.e. in the 10th

				remainder -= numberBase;
				dividedNumberAsString += "1";
			}
			else
				dividedNumberAsString += "0";

		}
		binAsString = dividedNumberAsString;
		result.insert(0, 1, '0' + remainder);

	} while (std::count(binAsString.begin(), binAsString.end(), '1'));

	if (flag)
		result.insert(0, "-");

	return result;
}

void int128_t::BigEndianToLittleEndian()
{
	for (size_t i = 0; i < BYTE_SIZE / 2; ++i)
	{
		uint8_t temp = bin[i];
		bin[i] = bin[BYTE_SIZE - i - 1];
		bin[BYTE_SIZE - i - 1] = temp;
	}
}

#pragma endregion

#pragma region Bit Manipulation
// Bit manipulation

void int128_t::SetBit(const size_t& pos)
{
	size_t r_pos_byte = 15 - (pos / 8);
	size_t r_pos_bit = pos >= 8 ? pos % 8 : pos;

	bin[r_pos_byte] |= (1 << r_pos_bit);
}

void int128_t::UnsetBit(const size_t& pos)
{
	size_t r_pos_byte = 15 - (pos / 8);
	size_t r_pos_bit = pos >= 8 ? pos % 8 : pos;

	bin[r_pos_byte] &= (~(1 << r_pos_bit));
}

void int128_t::ToggleBit(const size_t& pos)
{
	size_t r_pos_byte = 15 - (pos / 8);
	size_t r_pos_bit = pos >= 8 ? pos % 8 : pos;

	bin[r_pos_byte] ^= (1 << r_pos_bit);
	//bin[r_pos_byte] &= ~(1 << r_pos_bit);
}

char int128_t::GetBit(const size_t& pos)
{
	size_t r_pos_byte = 15 - (pos / 8);
	size_t r_pos_bit = pos >= 8 ? pos % 8 : pos;

	return (1 & (bin[r_pos_byte] >> (r_pos_bit)));
}

#pragma endregion
