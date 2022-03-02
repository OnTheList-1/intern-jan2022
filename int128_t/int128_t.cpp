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
	PrintConsoleHex();
	std::cout << "String Representation: " << StringToBinary(userInput) << "\n";
	std::cout << "Two's Complement Representation: ";
	PrintConsoleHex();
}

void int128_t::PrintConsoleHex()
{
	for (size_t i = 0; i < BYTE_SIZE; ++i)
	{
		printf("%02x ", bin[i]);
	}
	std::cout << "\n";
}

void int128_t::PrintConsoleBinary()
{

}

void int128_t::ConvertToTwosComplement()
{
	for (int i = 0; i < BIT_SIZE + 1; ++i)
	{ // flip bit
		ToggleBit(i);
	}

	int128_t one("1");
	*this = *this + one;

}

std::string int128_t::GetPolishNotation(std::string in)
{
	return infixToPostfix(in) + '\n';
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



	return rhs;
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

// Conversion

std::string int128_t::StringToBinary(std::string in)
{
	bool flag = false;
	if (in[0] == '-')
	{ // if it's a negative number
		flag = true;
		in = in.substr(1, in.length() - 1);
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

	if (flag == true)
		this->ConvertToTwosComplement();

	return out;

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
