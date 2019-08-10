#pragma once
#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
int min(int a, int b)
{
	return a < b ? a : b;
}

int solve(vector<int>&A, int left, int right)
{
	if (left == right)
		return A[left];

	int mid = (left + right) / 2;
	int ret = max(solve(A, left, mid), solve(A, mid + 1, right));
	
	int lo = mid;
	int hi = mid + 1;
	int height = min(A[lo], A[hi]);
	ret = max(ret, 2 * height);

	while (lo > left || hi < right)
	{
		if (hi < right && ((lo == left) || A[lo - 1] < A[hi]))
		{
			hi++;
			height = min(height, A[hi]);
		}
		else
		{
			lo--;
			height = min(height, A[lo]);
		}
			
		ret = max(ret, (hi - lo + 1)*height);
	}

	return ret;
}

int maxCurve(vector<int>&A)
{

}







int main()
{


	return 0;
}


