#include<iostream>
#include<stack>
#include<string>


using namespace std;

int precedence(char x)
{
	if (x == '+' || x == '-')
	{
		return 1;
	}
	if (x == '*' || x == ' / ')
	{
		return 2;
	}
	if (x == '^')
	{
		return 3;
	}
	return 0;
}

string postfix(string infix)
{
	stack<char>s;
	string postfix;
	int i = 0;
	while (infix[i] != '\0')
	{
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix = postfix + infix[i];
			i++;
		}
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
			i++;
		}
		else if (infix[i] == ')')
		{
			while (s.top() != '(')
			{
				postfix = postfix + s.top();
				s.pop();
			}
			s.pop();
			i++;
		}
		else
		{
			while (!s.empty() && precedence(infix[i]) <= precedence(s.top()))
			{
				postfix = postfix + s.top();
				s.pop();
			}
			s.push(infix[i]);
			i++;
		}


	}
	while (!s.empty())
	{
		postfix = postfix + s.top();
		s.pop();
	}

	return postfix;
}


int power(int base, int exp)
{
	if (exp !=0)
		return (base* power(base,exp-1));
	else
		return 1;
}
int multi(int a, int b)
{
	if (b != 0)
		return a + multi(a, b - 1);
	else
		return 0;
}

int main()
{
	string infix;
	string opt = "0";
	int sum = 0;
	while (opt != "6")
	{
		cout << "1)infix to postfix" << endl;
		cout << "2)infix to prefix" << endl;
		cout << "3)postfix evaluation" << endl;
		cout << "4)calculate power" << endl;
		cout << "5)calculate multiplation" << endl;
		cout << "6)exit" << endl;
		cin >> opt;
		if (opt == "1")
		{
			cout << "ENTER INFIX :" << endl;
			cin >> infix;
			cout << "POSTFIX = " << postfix(infix) << endl;
			system("pause");
			system("cls");
		}
		else if (opt == "2")
		{
			cout << "Enter Infix :" << endl;
			cin >> infix;
			system("pause");
			system("cls");
		}
		else if (opt == "4")
		{
			cout << "ENTER BASE: " << endl;
			int base;
			cin >> base;
			cout << "ENTER POWER: " << endl;
			int exp;
			cin >> exp;
			cout << "Answer: " << power(base, exp);
			system("pasue");
			system("cls");

		}
		else if (opt == "5")
		{
			cout << "Enter first number: ";
			int a;
			cin >> a;
			cout << "Enter second number: ";
			int b;
			cin >> b;
			cout << "Answer: "<<multi(a,b)<<endl;
			system("pause");
			system("cls");
		}

		else if (opt == "6")
		{
			cout << "Thank you :)" << endl;
		}
		else
		{
			cout << "Invalid Input" << endl;
			system("pause");
			system("cls");
		}
	}


	return 0;
}