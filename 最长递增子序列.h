#pragma once
#include<iostream>
#include<string.h>
#include<string>
#include<stack>
#include<vector>
using namespace std;

#define MAXSIZE 101
int cache[MAXSIZE];




//=================================动态规划法O(N^2)==================================================
int max(int a, int b)
{
	return a > b ? a : b;
}

int maxSubstringCore(string str, int next)
{
	int &ret = cache[next];
	if (ret != -1)
		return ret;

	ret = 1;
	if (next == str.size() - 1)
		return ret;

	for (int i = next + 1;i < str.size();++i)
	{
		if (str[i] > str[next])
			ret = max(ret, 1 + maxSubstringCore(str, i));
	}
	return ret;
}


int maxSubstrList(string str)
{
	memset(cache, -1, sizeof(cache));
	int ret = 0;
	for (int i = 0;i < str.size();++i)
	{
		ret = max(ret, maxSubstringCore(str, i));
	}

	return ret;
}

//====================================================二分查找法==========================

int binarySearch(int *A, int length, int X)
{
	if (A == NULL || length < 1)
		return -1;

	int start = 0;
	int end = length - 1;

	while (start <= end)
	{
		int mid = ((end - start) >> 2) + start;
		if (A[mid] < X)
			start = mid + 1;
		else if (A[mid] > X)
			end = mid - 1;
		else
			return mid;
	}
	return start;
}

int LIS(int *A, int N)
{
	if (A == NULL || N < 1)
		return 0;

	int *B = new int[N];
	memset(B, 0, sizeof(int)*N);
	B[0] = A[0];
	int len = 1;

	for (int i = 1;i < N;++i)
	{
		if (A[i] > B[len - 1])
		{
			B[len] = A[i];
			len++;
		}
		else
		{
			int pos = binarySearch(B, len, A[i]);
			B[pos] = A[i];
		}
	}
	return len;
}






int main()
{

	int N;
	cin >> N;
	vector<int>data(N);
	for (int i = 0;i < N;++i)
		cin >> data[i];

	int ret = LIS(data.data(), N);
	cout << ret << endl;
	system("pause");
	return 0;
}