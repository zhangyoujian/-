#pragma once
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



void fn(int n, vector<int>&Q)
{
	int *Data = new int[n];
	for (int i = 0;i <n;++i)
	{
		Data[i] = i+1;
	}
	int N = 0;
	do
	{
		N++;
		bool isfind = true;
		for (int i = 0;i < n;++i)
		{
			if (Q[i] != Data[i])
			{
				isfind = false;
				break;
			}
		}
		if (isfind)
			break;
	} while (next_permutation(Data, Data + n));//调用全排列函数;

	N = n - N;
	sort(Data, Data + n);
	int K = 1;
	do {
		if (K == N)
		{
			for (int i = 0;i < n;++i)
			{
				cout << Data[i] << " ";
			}
			break;
		}
	} while (next_permutation(Data, Data + n));//调用全排列函数;

	delete[] Data;
	
}






int main()
{
	int n;
	cin >> n;
	vector<int>Q(n);
	for (int i = 0;i < n;++i)
	{
		cin >> Q[i];
	}

	fn(n, Q);
	system("pausre");
	return 0;
}