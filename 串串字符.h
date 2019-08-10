#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

const int delat[8][2] = { { -1,-1 },
{ -1,0 },
{ -1,+1 },
{ 0,-1 },
{ 0,1 },
{ +1,-1 },
{ +1,0 },
{ +1,1 } };


bool hasWord(vector<string>&dic, int i, int j, string word)
{
	if (i < 0 || i >= dic.size() || j < 0 || j >= dic[0].size())
		return false;

	if (dic[i][j] != word[0])
		return false;

	if (word.size() == 1)
		return true;

	for (int k = 0;k < 8;++k)
	{
		if (hasWord(dic, delat[k][0] + i, delat[k][1] + j, word.substr(1)))
			return true;
	}
	return false;
}

bool Hasword(vector<string>&dic, string word)
{
	for (int k = 0;k < 8;++k)
	{
		if (hasWord(dic, delat[k][0] + 0, delat[k][1] + 0, word))
			return true;
	}
	return false;
}


int main()
{
	int m;
	cin >> m;
	vector<string>dic(m);
	for (int i = 0;i < m;++i)
	{
		cin >> dic[i];
	}
	string T;
	cin >> T;
	bool ret = Hasword(dic, T);
	if (ret)
		cout << "find";
	else
		cout << "not find";

	system("pause");
	return 0;
}
