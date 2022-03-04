#include <iostream>
#include <stack>
#include <vector>

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

int main()
{
	std::string infix = "((2+9)*3)-5";

	std::cout << infixToPostfix(infix) << std::endl;
}