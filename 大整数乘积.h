#pragma once
#include<iostream>
#include<vector>
using namespace std;

void normalize(vector<int>&C)
{
	C.push_back(0);
	for (auto i = 0;i < C.size();++i)
	{
		if (C[i] < 0)
		{
			int borrow = (abs(C[i]) + 9) / 10;
			C[i + 1] -= borrow / 10;
			C[i] += borrow * 10;
		}
		else
		{
			C[i + 1] += C[i] / 10;
			C[i] = C[i] % 10;
		}
	}

	while (C.size() > 0 && C.back() == 0)
		C.pop_back();
}

vector<int> mutiply(vector<int>&a, vector<int>&b)
{
	vector<int>C(a.size() + b.size() + 1, 0);


	for (auto i = 0;i < a.size();++i)
		for (auto j = 0;j < b.size();++j)
			C[i + j] = a[i] * b[j];

	normalize(C);
	return C;
}



#include <iostream> 
#include <string>
#include <sstream>
using namespace std;
string Add(string num1, string num2);
string Sub(string num1, string num2);
string Mul(string num1, string num2);
void OUTPUT_Mul(string num1, string num2);
string ChangeDigt(string num, int n);
void swap(string& a, string& b);
int main(int argc, char* argv[])
{
	int i, size, n;
	char exit;
	string bignum1, bignum2;
	while (true)
	{
		bignum1 = "";
		bignum2 = "";
		cout << "Please input num1: ";
		cin >> bignum1;
		cout << endl;
		cout << "Please input num2: ";
		cin >> bignum2;
		cout << endl << "num1 * num2 = ";
		OUTPUT_Mul(bignum1, bignum2);
		cout << endl << "Continue? y/n" << endl;
		cin >> exit;

		if (exit == 'n' || exit == 'N')
			break;
	}

	return 0;
}
void OUTPUT_Mul(string num1, string num2)
{
	int i, size, n;
	string mul;
	int begin1 = 0, begin2 = 0;

	if (num1[0] == '-')
	{
		begin1 = 1;
		//处理负号
		num1[0] = '0';
	}
	if (num2[0] == '-')
	{
		begin2 = 1;
		//处理负号
		num2[0] = '0';
	}
	size = (num1.length() - begin1 > num2.length() - begin2) ? num1.length() - begin1 : num2.length() - begin2;

	//较小数高位补零到相同位数
	if (num1.length() - begin1 < num2.length() - begin2)
	{
		for (i = num1.length() - begin1; i < num2.length() - begin2; i++)
			num1 = '0' + num1;
	}
	else if (num1.length() - begin1 > num2.length() - begin2)
	{
		for (i = num2.length() - begin2; i < num1.length() - begin1; i++)
			num2 = '0' + num2;
	}
	//补零到2^n次位
	for (i = 0; i < size; i++)
	{
		if (size < pow(2, i) || size == pow(2, i))
		{
			n = i;
			break;
		}
	}
	for (i = size; i < pow(2, n); i++)
	{
		num1 = '0' + num1;
		num2 = '0' + num2;
	}
	//改回负号
	if (begin1 == 1)
		num1[0] = '-';

	if (begin2 == 1)
		num2[0] = '-';

	mul = Mul(num1, num2);
	//去掉高位多余的零
	string::iterator it = mul.end();
	//如果结果为零
	if (mul[mul.length() - 1] == 0)
		mul = "0";
	else
	{
		string::iterator it = mul.begin();
		if (mul[0] == '-')
			it++;
		for (; *it == '0';)
		{
			if (*it == '0')
				it = mul.erase(it);
			else ++it;
		}
	}

	cout << mul << endl;

}
string Mul(string num1, string num2)
{
	string mul = "";
	bool Isneg = false;
	int begin1 = 0, begin2 = 0, n;
	int size1 = num1.length(), size2 = num2.length();
	int i;

	//处理符号，计算时跳过负号。
	if (num1[0] == '-')
		size1--, begin1++;
	if (num2[0] == '-')
		size2--, begin2++;

	int size = (size1 > size2) ? size1 : size2;

	if (num1[0] == '-' && num2[0] != '-')
		Isneg = true;
	else if (begin1 != 1 && begin2 == 1)
		Isneg = true;

	//本应该较小数高位补零，但已经控制输入是2^n位，可节省补零的消耗
	/*	if (size1  < size2)
	{
	for (i = size1; i < size2; i++)
	num1 = '0' + num1;
	}
	else if (size1  > size2)
	{
	for (i = size2; i < size1; i++)
	num2 = '0' + num2;
	}*/
	if (size == 0)
		return NULL;
	else if (size == 1)
	{
		int k = (num1[begin1] - '0') * (num2[begin2] - '0');
		stringstream stream;
		string str1;
		stream << k;
		stream >> str1;
		mul += str1;
		if (Isneg)
			mul = '-' + mul;
		return mul;
	}
	string A = num1.substr(begin1, size / 2);
	string B = num1.substr(size / 2 + begin1, size - size / 2);
	string C = num2.substr(begin2, size / 2);
	string D = num2.substr(size / 2 + begin2, size - size / 2);
	string AC = Mul(A, C);
	string BD = Mul(B, D);
	string AB = Sub(A, B);
	string DC = Sub(D, C);
	string M0 = Mul(AB, DC);
	string M1 = Add(M0, AC);
	string M2 = Add(M1, BD);
	string P0 = ChangeDigt(AC, size);
	string R0 = ChangeDigt(M2, size / 2);
	string W0 = Add(P0, R0);
	mul = Add(W0, BD);
	if (Isneg)
		mul = '-' + mul;
	return mul;
}
string Add(string num1, string num2)
{
	string sum, temp;
	string temp1 = num1, temp2 = num2;
	int tempSum, carry = 0;
	bool overcarry = false, Isneg = false;
	int size = (num1.length() > num2.length()) ? num1.length() : num2.length();
	int i, j = 0;

	//符号位判定
	if (num1[0] == '-' && num2[0] == '-')
	{
		num1[0] = '0';
		num2[0] = '0';
		Isneg = true;
	}
	else if (num1[0] == '-' && num2[0] != '-')
	{
		num1[0] = '0';
		return Sub(num2, num1);
	}
	else if (num2[0] == '-' && num1[0] != '-')
	{
		num2[0] = '0';
		return Sub(num1, num2);
	}

	//倒置，方便进位
	for (i = num1.length() - 1, j = 0; i >= 0; i--, j++)
		temp1[j] = num1[i];
	for (i = num2.length() - 1, j = 0; i >= 0; i--, j++)
		temp2[j] = num2[i];

	//短字符高位补零
	if (num1.length() < num2.length())
	{
		//使得sum和temp获得内存
		sum = num2;
		temp = num2;
		for (i = num1.length(); i < num2.length(); i++)
			temp1 += '0';
	}
	else if (num1.length() > num2.length())
	{
		sum = num1;
		temp = num1;		for (i = num2.length(); i < num1.length(); i++)
			temp2 += '0';
	}
	else
	{
		sum = num1;
		temp = num1;
	}

	//每一项相加
	for (i = 0; i < size; i++)
	{
		tempSum = temp1[i] - '0' + temp2[i] - '0' + carry;

		//如果产生进位
		if (tempSum > 9)
		{
			//如果产生溢出
			if (i == (size - 1))
				overcarry = true;
			carry = 1;
			sum[i] = tempSum - 10 + '0';
		}
		else
		{
			carry = 0;
			sum[i] = tempSum + '0';
		}
	}
	if (overcarry)
	{
		string str;
		str = carry + '0';
		sum += str;
		temp += '0';
		size++;
	}

	//再将sum倒置，得出结果
	for (i = 0, j = sum.length() - 1; i < sum.length(), j >= 0; i++, j--)
	{
		temp[i] = sum[j];
	}

	for (i = 0; i < sum.length(); i++)
		sum[i] = temp[i];

	//如果sum是负数
	if (Isneg)
	{
		return "-" + sum;
	}
	return sum;
}

string Sub(string num1, string num2)
{
	string minus, temp;
	string temp1 = num1, temp2 = num2;
	int tempMinus, Dec = 0;
	bool overDec = false, Isneg = false;
	int  size = (num1.length() > num2.length()) ? num1.length() : num2.length();
	int	 i, j = 0;
	//判断符号位
	if (num1[0] == '-' && num2[0] == '-')
	{
		num2[0] = '0';
		num1[0] = '0';
		return Sub(num2, num1);
	}
	else if (num1[0] == '-' && num2[0] != '-')
	{
		string str = "-";
		num2 = str + num2;
		return Add(num1, num2);
	}
	else if (num1[0] != '-' && num2[0] == '-')
	{
		num2[0] = '0';
		Add(num1, num2);
	}

	//倒置，方便退位
	for (i = num1.length() - 1, j = 0; i >= 0; i--, j++)
		temp1[j] = num1[i];
	for (i = num2.length() - 1, j = 0; i >= 0; i--, j++)
		temp2[j] = num2[i];

	//短字符高位补零
	if (num1.length() < num2.length())
	{
		//使得minus和temp获得内存
		minus = num2;
		temp = num2;
		for (i = num1.length(); i < num2.length(); i++)
			temp1 += '0';
	}
	else if (num1.length() > num2.length())
	{
		minus = num1;
		temp = num1;
		for (i = num2.length(); i < num1.length(); i++)
			temp2 += '0';
	}
	else
	{
		minus = num1;
		temp = num1;
	}
	//判断大小
	for (i = size - 1; i >= 0; i--)
	{
		if (temp1[i] > temp2[i])
		{
			break;
		}
		else if (temp1[i] < temp2[i])
		{
			Isneg = true;
			swap(temp1, temp2);
			break;
		}
	}
	//每一项相减
	for (i = 0; i < size; i++)
	{
		tempMinus = (temp1[i] - '0') - (temp2[i] - '0') + Dec;
		//如果产生退位
		if (tempMinus < 0)
		{
			//如果结果是负数
			if (i == (size - 1))
				overDec = true;
			Dec = -1;
			minus[i] = tempMinus + 10 + '0';
		}
		else
		{
			Dec = 0;
			minus[i] = tempMinus + '0';
		}
	}

	//再将minus倒置，得出结果
	for (i = 0, j = size - 1; i < size, j >= 0; i++, j--)
		temp[i] = minus[j];

	for (i = 0; i < size; i++)
		minus[i] = temp[i];

	if (Isneg)
	{
		return "-" + minus;
	}
	return minus;
}
string ChangeDigt(string num, int n)
{
	if (num == "0")
		return num;
	else
	{
		for (int i = 0; i < n; i++)
			num += '0';
	}
	return num;
}
void swap(string& a, string& b)
{
	string temp;
	temp = a;
	for (int i = 0; i < a.length(); i++)
		temp[i] = a[i];
	for (int j = 0; j < a.length(); j++)
		a[j] = b[j];
	for (int k = 0; k < a.length(); k++)
		b[k] = temp[k];
}




int main()
{

	string A, B;
	cin >> A >> B;
	string res = Mul(A, B);
	cout << res << endl;
	system("pause");
	return 0;
}