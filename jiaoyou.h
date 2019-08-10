#pragma once
#include<iostream>
#include<vector>
using namespace std;

#define MAX_STUDENT_NUM 10
bool ismathch[MAX_STUDENT_NUM];



int countCouple(int n, const int *isfriend)
{
	int ret = 0;
	int FirstFirend = -1;
	for (int i = 0;i < n;++i)
	{
		if (!ismathch[i])
		{
			FirstFirend = i;
			break;
		}
	}
	if (FirstFirend == -1)
		return 1;

	for (int j = FirstFirend + 1;j<n;++j)
	{
		if (!ismathch[j] && isfriend[FirstFirend*MAX_STUDENT_NUM + j])
		{
			ismathch[FirstFirend] = ismathch[j] = true;
			ret += countCouple(n, isfriend);
			ismathch[FirstFirend] = ismathch[j] = false;
		}
	}
	return ret;
}

int fn(const int &n, const int &m, vector<int>&couple)
{
	int isfriend[MAX_STUDENT_NUM*MAX_STUDENT_NUM] = { 0 };
	for (int i = 0;i < MAX_STUDENT_NUM;++i)
	{
		ismathch[i] = false;
	}
	for (int i = 0;i < (int)couple.size() - 1;i += 2)
	{
		isfriend[couple[i] * MAX_STUDENT_NUM + couple[i + 1]] = 1;
	}

	int ret = countCouple(n, isfriend);
	return ret;
}

int main()
{
	int C;
	cin >> C;
	vector<int>result(C);
	for (int i = 0;i < C;++i)
	{
		int n, m;
		cin >> n >> m;
		vector<int>iscouple(2 * m);
		for (int j = 0;j < 2 * m;++j)
			cin >> iscouple[j];

		result[i] = fn(n, m, iscouple);
	}

	for (vector<int>::iterator it = result.begin();it != result.end();it++)
		cout << *it << endl;

	system("pause");
	return 0;
}