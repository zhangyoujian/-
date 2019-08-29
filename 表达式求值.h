#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<unordered_map>
using namespace std;


bool InOPS(char ch)
{
	const char* OPS = "+-*/()";
	while (*OPS != '\0')
	{
		if (ch == *OPS)
		{
			return true;
		}
		OPS++;
	}
	if (!(ch >= '0' && ch <= '9'))
		throw std::exception("表达式格式出错");
	return false;
}


char Compare(char lastOp, char curOp)
{
	const char *StaTable = "+-*/()";
	const char ComTable[][7] = { ">><<<>",">><<<>",">>>><>",">>>><>","<<<<<=",">>>>->" };
	int index1 = -1;
	int index2 = -1;
	for (auto i = 0;i < strlen(StaTable);++i)
	{
		if (lastOp == StaTable[i])
			index1 = i;
		if (curOp == StaTable[i])
			index2 = i;
	}
	return ComTable[index1][index2];
}




double Excute(double a, double b, char op)
{
	double ret = -1;
	switch (op)
	{
	case '+':
		ret = a + b;break;
	case '-':
		ret = a - b;break;
	case '*':
		ret = a * b;break;
	case '/':
		ret = a / b;break;
	default:
		throw std::exception("运算表达式格式出错!"); break;
	}
	return ret;
}



double ExpExplanation(char *Seq, int N)
{
	if (Seq == NULL)
		return 0;
	double v, a, b;
	stack<double>operand;     //操作数
	stack<char>operator_;  //操作符
	char *Ch = Seq;

	while (*Ch != '\0')
	{
		if (!InOPS(*Ch))
		{
			double temp;
			temp = *Ch - '0';
			Ch++;
			while (*Ch != '\0' && (!InOPS(*Ch)))
			{
				temp = temp * 10 + (*Ch) - '0';
				Ch++;
			}
			operand.push(temp);
		}
		else
		{
			if (operator_.empty())
				operator_.push(*Ch);
			else
			{
				char TopOp = operator_.top();
				char cmp = Compare(TopOp, *Ch);
				switch (cmp)
				{
				case '<':operator_.push(*Ch); break;
				case '=':   //将括号内的表达式运算
					operator_.pop();
					break;

				case '>':
					b = operand.top();
					operand.pop();
					a = operand.top();
					operand.pop();
					v = Excute(a, b, operator_.top());
					operand.push(v);
					operator_.pop();
					if (!operator_.empty() && operator_.top() == '(')
					{
						operator_.pop();
						break;
					}
					operator_.push(*Ch);
					break;

				case '-':
					throw std::exception("表达式格式出错");
				}
			}
			Ch++;
		}
	}
	while (!operator_.empty() && (!operand.empty()))
	{
		if (operator_.top() == ')')
		{
			operator_.pop();
			continue;
		}
		b = operand.top();
		operand.pop();
		a = operand.top();
		operand.pop();
		v = Excute(a, b, operator_.top());
		operand.push(v);
		operator_.pop();
		if (!operator_.empty() && operator_.top() == '(')
			operator_.pop();
	}


	v = operand.top();
	return v;
}



int main()
{
	string Exp;
	cin >> Exp;
	double ret = ExpExplanation((char *)Exp.data(), Exp.length());
	cout << ret << endl;
	system("pause");
	return 0;
}