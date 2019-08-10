#pragma once
#include<iostream>
#include<vector>
using namespace std;
#define MAXC 10


bool isMatch(int N, char *visited, char *areFriend)
{
	int Unmatch = -1;
	for (int i = 0;i < N;++i)
	{
		if (!visited[i])
		{
			Unmatch = i;
			break;
		}
	}
	if (Unmatch == -1)
		return 1;

	int ret = 0;
	for (int i = Unmatch + 1;i < N;++i)
	{
		if (!visited[i] && areFriend[Unmatch*MAXC + i])
		{
			visited[Unmatch] = visited[i] = 1;
			ret += isMatch(N, visited, areFriend);
			visited[Unmatch] = visited[i] = 0;
		}
	}
	return ret;
}


int fn(int N, vector<pair<int, int>>&Couple)
{
	char visited[MAXC] = { 0 };
	char areFriend[MAXC*MAXC] = { 0 };

	for (vector<pair<int, int>>::iterator it = Couple.begin();it != Couple.end();++it)
	{
		areFriend[it->first*MAXC + it->second] = 1;
	}

	int ret = isMatch(N, visited, areFriend);
	return ret;
}




int main()
{
	int n, m;
	int a, b;
	cin >> n >> m;
	vector<pair<int, int>>Couple(m);
	for (int i = 0;i < m;++i)
	{
		cin >> a >> b;
		Couple[i].first = a;
		Couple[i].second = b;
	}
	int ret = fn(n, Couple);
	cout << ret;

	system("pause");
	return 0;
}