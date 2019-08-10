#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<map>
using namespace std;




// =====================================not AC=================================
#define MAXNUM 100
#define MAXROUTE ~((sizeof(int)*8-1)<<1)

static int minRoute = MAXROUTE;




bool findWaysCore(const vector<string>&route, int x, int y,int step,string Keys)
{
	if (x >= route.size() || y >= route[0].size() || x<0 || y<0)
		return false;

	if (step >= minRoute)
		return false;

	if (route[x][y] == '3')
	{
		minRoute = step;
		return true;
	}
	else if (route[x][y] == '0')
		return false;

	else if ('a' <= route[x][y] && route[x][y] <= 'z')
	{
		if (Keys.find(route[x][y]) == Keys.npos)
			Keys.push_back(route[x][y]);
	}
	else if ('A' <= route[x][y] && route[x][y] <= 'Z')
	{
		char ch = route[x][y] - 'A' + 'a';
		if (Keys.find(ch) == Keys.npos)
			return false;
	}

	return findWaysCore(route, x + 1, y, step + 1, Keys) |
		findWaysCore(route, x - 1, y, step + 1, Keys) |
		findWaysCore(route, x, y + 1, step + 1, Keys) |
		findWaysCore(route, x - 1, y, step + 1, Keys);

}



void findWays(vector<string>&route)
{
	int N = route.size();

	int origin = 0;
	for (;origin < N;++origin)
	{
		if (route[origin].find('2') != route[origin].npos)
			break;
	}

	int x = origin;
	int y = route[origin].find('2');
	bool ret = findWaysCore(route, x, y, 0, "");

	if (ret)
		cout << minRoute;
	else
		cout << -1;

}


int main()
{

	int N, M;
	cin >> M >> N;
	vector<string>route(N);
	for (int i = 0;i < N;++i)
		cin >> route[i];

	findWays(route);
	system("pause");
	return 0;
}
