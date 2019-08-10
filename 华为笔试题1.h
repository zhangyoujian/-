#pragma once
#pragma once
#include<iostream>
#include<vector>
using namespace std;


void exchangeArray(int A[], int N)
{
	if (N <= 1)
		return;
	int i, j, k;
	bool flag = true;
	i = j = k = 0;
	while (i < N || j < N)
	{
		if (flag && i<N)
		{
			if (A[i] > 0)
			{
				A[k++] = A[i++];
				flag = !flag;
			}
			else
				i++;
		}
		else if (!flag && j<N)
		{
			if (A[j] < 0)
			{
				A[k++] = A[j++];
				flag = ~flag;
			}
			else
				j++;
		}
		else
		{
			if (flag)
				i++;
			else
				j++;
		}
	}
}


int main()
{

	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0;i < N;++i)
		cin >> A[i];
	exchangeArray(A.data(), N);
	for (int i = 0;i < N;++i)
		cout << A[i] << " ";
	cout << endl;

	return 0;
}