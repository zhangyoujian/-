#pragma once
#include<iostream>
#include<vector>
using namespace std;
// =====================================not AC=================================

void MinStable(vector<int>&A, int K)
{
	int N = A.size();
	int index1;
	int index2;
	int minStalVal = 0;
	int minStalValOld = -1;
	int maxVal = -1;
	int minVal = 10001;
	int m = 0;
	vector<pair<int, int>> result;
	for (int i = 0;i < K;++i)
	{
		 maxVal = -1;
		 minVal = 10001;
		for (int j = 0;j < N;++j)
		{
			if (A[j] > maxVal)
			{
				maxVal = A[j];
				index1 = j;
			}
		}

		for (int j = 0;j < N;++j)
		{
			if (A[j] < minVal)
			{
				minVal = A[j];
				index2 = j;
			}
		}

		A[index1]--;
		A[index2]++;
		result.push_back(make_pair(index1+1, index2+1));
		minStalVal = A[index1] - A[index2];
		if (minStalVal != minStalValOld)
		{
			minStalValOld = minStalVal;
			m++;
		}
		else
			break;
	}

	cout << minStalVal << " " << m << endl;
	for (vector<pair<int, int>>::iterator it = result.begin();it != result.end();++it)
	{
		cout << it->first << " " << it->second << endl;
	}

}

