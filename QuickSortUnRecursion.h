#pragma once
#include<iostream>
#include<stack>
using namespace std;

int partition(int A[], int begin, int end)
{
	int temp;
	int i = begin;
	int j = i + 1;
	for (;j <= end;j++)
	{
		if (A[j] <= A[begin])
		{
			i++;
			if (i != j)
			{
				temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
	temp = A[begin];
	A[begin] = A[i];
	A[i] = temp;
	return i;
}


void QuickSortUnRecursion(int A[], int N)
{
	stack<pair<int,int>> Stack;
	int start = 0;
	int end = N - 1;

	int index = partition(A, start, end);

	if (index - 1> start)
		Stack.push(make_pair(start, index - 1));

	if(index+1<end)
		Stack.push(make_pair(index + 1, end));

	while (!Stack.empty())
	{
		pair<int, int> q = Stack.top();
		Stack.pop();
		start = q.first;
		end = q.second;
		index = partition(A, start, end);

		if (index - 1> start)
			Stack.push(make_pair(start, index - 1));

		if (index + 1<end)
			Stack.push(make_pair(index + 1, end));
	}
}


void QuickSortUnRecursionTest()
{
	int A[] = { 3,1,3,2,7,5 };
	int N = sizeof(A) / sizeof(A[0]);
	for (int i = 0;i<N;++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	QuickSortUnRecursion(A, N);
	for (int i = 0;i<N;++i)
	{
		cout << A[i] << " ";
	}
	cout << endl;


}
