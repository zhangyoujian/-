#pragma once
#include<iostream>
#include<vector>
using namespace std;
typedef unsigned int UINT;


// N个数的数组中，每个数的范围都在0~N-1范围内
bool findDuplicatie(vector<int>A, int &duplicate)
{

	bool ret = false;
	UINT  N = A.size();
	if (N <= 1)
		return false;

	for (UINT i = 0;i < N;++i)
	{
		while (A[i] != i)
		{
			if (A[i] == A[A[i]])
			{
				duplicate = A[i];
				return true;
			}
			int temp = A[i];
			A[i] = A[temp];
			A[temp] = temp;

			//注意三面三行代码不可以写成
			/*int temp = A[i];
			A[i] = A[A[i]];
			A[A[i]] = temp;*/
		}
	}
	return ret;
}


int countRange(vector<int>A, int start, int end)
{
	int count = 0;
	for (int i = 0;i < A.size();++i)
	{
		if (start <= A[i] && A[i] <= end)
		{
			count++;
		}
	}
	return count;
}



int findDuplicateUnRevise(vector<int>A, int &duplicate)
{
	bool ret = false;
	UINT  N = A.size();
	if (N <= 1)
		return false;

	int start = 1;
	int end = N;
	int mid;
	int count = 0;

	while (start <= end)
	{
		mid = (end - start) >> 2 + start;
		count = countRange(A, start, mid);
		if (start == end)
		{
			if (count >1)
			{
				duplicate = A[start];
				return true;
			}
			else
				return false;
		}
		else
		{
			if (count > mid - start + 1)
			{
				end = mid - 1;

			}
			else
				start = mid + 1;
		}

	}
	return false;
}



int main()
{
	int N;

	cin >> N;
	vector<int>A(N);
	for (int i = 0;i < N;++i)
	{
		cin >> A[i];
	}
	int duplicate;
	bool ret = findDuplicatie(A, duplicate);
	if (ret)
	{
		cout << duplicate << endl;
	}
	else
	{
		cout << "not find" << endl;
	}
	system("pause");
	return 0;
}
