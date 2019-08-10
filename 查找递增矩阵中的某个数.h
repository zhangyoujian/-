#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;



bool findMatrixData(int *A, int M, int N, int X)
{
	bool found = false;
	if (A == NULL || M < 1 || N < 1)
		return false;

	int row = 0;
	int col = N - 1;
	while (row <M && col>0)
	{
		if (A[row*N + col] == X)
		{
			found = true;
			return found;
		}
		else if (A[row*N + col] < X)
		{
			while (row < M)
			{
				if (A[row*N + col] == X)
				{
					found = true;
					return found;
				}
				else if (A[row*N + col] > X)
				{
					row--;
					break;
				}
				row++;
			}
		}

		col--;
	}


	return found;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {

	priority_queue<int, greater<int>> Q;

	for (int i = 0;i < matrix.size();++i)
		for (int j = 0;j < matrix[i].size();++j)
			Q.push(matrix);
	int i = 1;
	while (i <k)
	{
		Q.pop();
		i++;
	}

	int ret = Q.top();
	return ret;
}




int main()
{
	int M, N, K;
	cin >> M >> N>>K;

	vector<vector<int>>matrix(M);
	for (int i = 0;i < M;++i)
	{
		vector<int> temp(N);
		for (int j = 0;j < N;++j)
			cin >> temp[j];
		matrix[i] = temp;
	}

	int ret = kthSmallest(matrix, K);
	cout << ret << endl;
	system("pause");
	return 0;
}