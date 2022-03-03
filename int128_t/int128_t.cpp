#include "int128_t.h"
// Reverse Polish Notation functions
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

// Constructor

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

// Read and Write

void int128_t::ReadConsoleString()
{
	std::string userInput;
	bool checkInput = true;

	std::cout << "Enter your number: ";
	std::cin >> userInput;

	std::cout << "Hex representation: ";
	StringToBinary(userInput);
	PrintHex();
	std::cout << "String Representation: " << StringToBinary(userInput) << "\n";
	std::cout << "\nBinary Representation: ";
	PrintBinary();
	std::cout << "\nDecimal Representation: ";
	PrintDecimal();
	std::cout << "\n";
}

void int128_t::PrintHex()
{
	for (size_t i = 0; i < BYTE_SIZE; ++i)
	{
		printf("%02x ", bin[i]);
	}
	std::cout << "\n";
}

void int128_t::ReadBinaryFile(const std::string& file_path)
{
	std::ifstream MyFile(file_path);

	MyFile.close();
}

void int128_t::WriteBinaryFile(const std::string& file_path)
{
	std::ofstream MyFile(file_path);

	MyFile.close();
}


std::string int128_t::GetPolishNotation(std::string in)
{
	return infixToPostfix(in) + '\n';
}

void int128_t::evalPolishNotation(const std::string& rhs)
{
	*this = postfixEval(rhs);
	PrintBinary();

}

// Convert

void int128_t::ConvertToTwosComplement()
{
	for (int i = 0; i < BIT_SIZE + 1; ++i)
	{ // flip bit
		ToggleBit(i);
	}

	int128_t one("1");
	*this = *this + one;

}

void int128_t::PrintBinary()
{
	std::string binary;
	int count = 0;
	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (count == 8) //padding
		{
			count = 0;
			binary.push_back(' ');
		}
		if (GetBit(i) == 1)
			binary.push_back('1');
		else if (GetBit(i) == 0)
			binary.push_back('0');
		++count;
	}

	std::cout << binary;
}

void int128_t::PrintDecimal()
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

	std::cout << result;

}

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
		}
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
		{
			if (carry == true)
				rhs.SetBit(i);
			else
			{
				carry = true;
				rhs.UnsetBit(i);
			}

		}
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
				rhs.UnsetBit(i);
			else
				rhs.SetBit(i);
		}
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
			{
				rhs.SetBit(i);
				carry = false;
			}
			else
				rhs.UnsetBit(i);
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
		}
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
		{
			if (carry == true)
				rhs.SetBit(i);
			else
			{
				rhs.UnsetBit(i);
			}

		}
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
			{
				carry = false;
				rhs.UnsetBit(i);
			}
			else
				rhs.SetBit(i);
		}
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
		{
			if (carry == true)
			{
				rhs.SetBit(i);
				carry = false;
			}
			else
				rhs.UnsetBit(i);
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

	return rhs;
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
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (size_t i = 0; i < BIT_SIZE; ++i)
	{
		if (rhs.GetBit(i) == lhs.GetBit(i))
			return false;
	}

	return true;
}

bool operator<(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
			continue;
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
			return false;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
			return true;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
			continue;
	}
	return false;
}

bool operator<=(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
			continue;
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
			return false;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
			return true;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
			continue;
	}

	return true;
}

bool operator>(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
			continue;
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
			return true;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
			return false;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
			continue;
	}

	return false;
}

bool operator>=(const int128_t& rhs1, const int128_t& lhs1)
{
	int128_t rhs(rhs1);
	int128_t lhs(lhs1);

	for (int i = BIT_SIZE; i >= 0; --i)
	{
		if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 1)
			continue;
		else if (rhs.GetBit(i) == 1 && lhs.GetBit(i) == 0)
			return true;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 1)
			return false;
		else if (rhs.GetBit(i) == 0 && lhs.GetBit(i) == 0)
			continue;
	}

	return true;
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

// Conversion

std::string int128_t::StringToBinary(std::string in)
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
	std::string out;
	int c = 1;
	int count = 0;
	while (in.length()) {
		out.insert(0, 1, '0' + (in[in.length() - 1] & 1));
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

	return out;

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
