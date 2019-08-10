#pragma once
#include<iostream>
#include<vector>
using namespace std;


void crossSort(int A[], int N)
{
	if (N <=1)
		return;
	int j = 0;
	int X;
	for (int i = 0;i < N;++i)
	{
		if (A[i] < 0)
			continue;
		X = A[i];
		j = i;
		while (j > 0 && A[j - 1] < 0)
		{
			
			A[j] = A[j - 1];
			A[j - 1] = X;
			j--;
		}
	}

	int mid = N / 2 - 1;
	int temp;
	while (mid >= 2)
	{
		temp = A[mid];
		A[mid] = A[N / 2 + mid];
		A[N / 2 + mid] = temp;
		mid -= 2;
	}




}


int main()
{

	
	return 0;
}