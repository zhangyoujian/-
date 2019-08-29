#pragma once
#include<iostream>
#include<string>
using namespace std;

#define MAXSIZE 100


string longestRepeateString(string str)
{
	if (str.size() <= 1)
		return str;

	bool isVisited[MAXSIZE][MAXSIZE];
	memset(isVisited, false, sizeof(isVisited));
	int N = str.size();
	int left = 0;
	int right = 0;
	for (int i = N - 2;i >= 0;i--)
	{
		isVisited[i][i] = true;
		for (int j = i + 1;j < N;++j)
		{
			isVisited[i][j] = (str.at(i) == str.at(j)) && ((j - i) < 3 || isVisited[i + 1][j - 1]);
			if (isVisited[i][j] && (right - left<j - i))
			{
				left = i;
				right = j;
			}
		}
	}

	return str.substr(left, right - left + 1);
}




int main()
{

	string str;
	cin >> str;

	string A = longestRepeateString(str);
	cout << "最长回文字符:" << A << "  :" << A.size() << endl;
	system("pause");

	return 0;
}