#pragma once
#include<iostream>
#include<string.h>
using namespace std;

void replaceSpace(char *str, int length)
{
	if (str == NULL)
		return;

	int count = 0;
	for (int i = 0;i < length;++i)
	{
		if (str[i] == ' ')
			count++;
	}

	int j = 3 * count + length - count;
	int i = length;
	while (i >= 0 && j >= 0)
	{
		if (str[i] != ' ')
			str[j--] = str[i--];
		else
		{
			i--;
			str[j--] = '0';
			str[j--] = '2';
			str[j--] = '%';
		}
	}

}


int main()
{
	char str[100] = "We Are Happy";
	replaceSpace(str, strlen(str));
	cout << str << endl;
	system("pause");

	return 0;
}