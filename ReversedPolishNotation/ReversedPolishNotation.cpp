#include <iostream>
#include <stack>
#include <vector>

bool isOperand(char c)
{
	if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
		return true;

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

	return -1;
}

std::string infixToPostfix(std::string s)
{

	std::stack<char> st;
	std::string result;

	for (int i = 0; i < s.length(); i++)
	{
		char ch = s[i];

		if (ch == ' ')
			continue;

		if (isOperand(ch))
		{
			result += ch;
			result += " ";
		}

		else if (ch == '(')
			st.push('(');

		else if (ch == ')')
		{
			while (st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		else
		{
			while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
			{
				result += st.top();
				result += " ";
				st.pop();
			}
			result += " ";
			st.push(ch);
		}
	}

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	return result;
}

int evaluatePostfix(const std::string& expr)
{
	std::stack<int> s;
	for (int i = 0; i < expr.length(); i++)
	{

		if (isdigit(expr[i]))
			s.push(expr[i] - '0');

		else if (expr[i] == ' ')
		{
			continue;
		}
		else
		{
			int op2 = s.top();
			s.pop();
			int op1 = s.top();
			s.pop();

			if (expr[i] == '+')
				s.push(op1 + op2);
			else if (expr[i] == '-')
				s.push(op1 - op2);
			else if (expr[i] == '*')
				s.push(op1 * op2);
			else if (expr[i] == '/')
				s.push(op1 / op2);
		}
	}
	return s.top();
}


int main()
{
	std::string infix = "((2+9)*3)-5";
	std::string infix1 = "2 + 9 * 3- 5";

	std::cout << infixToPostfix(infix) << std::endl;
	std::cout << infixToPostfix(infix1) << std::endl;
	std::cout << evaluatePostfix(infixToPostfix(infix1));
}