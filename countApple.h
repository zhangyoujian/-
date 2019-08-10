#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


bool cmp(const pair<int, int>&a, const pair<int, int>&b)
{
	return a.first < b.first;
}


void countApple(vector<int>&A, vector<pair<int, int>>&Q)
{
	
	int n = A.size();
	int m = Q.size();
	long long ACC = A[0];
	sort(Q.begin(), Q.end(),cmp);
	vector<pair<int, int>>result(m);

	int index = 0;
	int i = 0;
	while (index < m  && i<=n-1)
	{
		if (Q[index].first <= ACC)
		{
			result.push_back(make_pair(Q[index].second, i+1));
			index++;
		}
		else
		{
			i++;
			if (i >= m)
				break;
			ACC += A[i];
		}
	}

	sort(result.begin(), result.end(), cmp);

	for (vector<pair<int, int>>::iterator it = result.begin(); it != result.end();++it)
		cout << it->second << endl;

}


int main()
{
	int n, m,a;
	cin >> n;
	vector<int>A;
	for (int i = 0;i < n;++i)
		cin >> A[i];

	cin >> m;
	vector<pair<int, int>>Q(m);
	int j = 0;
	for (;j < m;++j);
	{
		cin >> a;
		Q.push_back(make_pair(a,j));
	}
	countApple(A, Q);
	system("pause");
	return 0;
}