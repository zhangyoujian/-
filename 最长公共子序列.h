#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
#define MAXLENGTH 100


void printStr(int i, int j, int flag[][MAXLENGTH], string a)
{
	if (i == 0 || j == 0)
	{
		return;
	}

	if (flag[i][j] == 0)
	{
		printStr(i - 1, j - 1, flag, a);
		cout << a[i - 1];
	}
	else if (flag[i][j] == 1)
	{
		printStr(i - 1, j, flag, a);
	}

	else
		printStr(i, j - 1, flag, a);

}


int lengestComeSubs(string a, string b)
{
	unsigned int m = a.size();
	unsigned int n = b.size();

	int d[MAXLENGTH][MAXLENGTH];
	int flag[MAXLENGTH][MAXLENGTH];
	memset(d, 0, sizeof(d));
	memset(flag, 0, sizeof(flag));

	for (auto i = 1;i <= m;++i)
		for (auto j = 1;j <= n;++j)
		{
			if (a[i - 1] == b[j - 1])
			{
				d[i][j] = d[i - 1][j - 1] + 1;
				flag[i][j] = 0;
			}
			else
			{
				if (d[i - 1][j] > d[i][j - 1])
				{
					d[i][j] = d[i - 1][j];
					flag[i][j] = 1;
				}
				else
				{
					d[i][j] = d[i][j - 1];
					flag[i][j] = -1;
				}
			}
		}
	cout << "最长公共子序列:" << endl;
	printStr(m, n, flag, a);
	cout << endl;
	return d[m][n];
}



int main()
{
	string a, b;
	cin >> a >> b;
	int ret = lengestComeSubs(a, b);
	cout << ret << endl;

	system("pause");
	return 0;
}
