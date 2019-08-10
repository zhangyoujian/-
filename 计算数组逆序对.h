#pragma once
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

#define MODNUM 1000000007

long long InversePairs(int  *data, int N)
{
	if (N <= 1)
		return 0;

	int mid = N / 2;
	int *leftData = new int[mid];
	int *rightData = new int[N - mid];

	memcpy(leftData, data, sizeof(int)*mid);
	memcpy(rightData, data + mid, sizeof(int)*(N - mid));

	long long leftCnt = InversePairs(leftData, mid);
	long long rightCnt = InversePairs(rightData, N - mid);

	int P1 = mid - 1;
	int P2 = N - mid - 1;
	int P3 = N - 1;
	long long cnt = 0;
	while (P2 >= 0 && P1 >= 0)
	{
		if (rightData[P2] > leftData[P1])
		{
			data[P3--] = rightData[P2--];
		}
		else
		{
			cnt += P2 + 1;
			data[P3--] = leftData[P1--];

		}
	}
	while (P2 >= 0)
	{
		data[P3--] = rightData[P2--];
	}
	while (P1 >= 0)
	{
		data[P3--] = leftData[P1--];
	}

	delete[] rightData;
	delete[] leftData;
	return cnt + leftCnt + rightCnt;
}

int InversePairs(vector<int>&data)
{
	int *buffer = new int[data.size()];

	for (int i = 0;i < data.size();++i)
	{
		buffer[i] = data[i];
	}

	int ret = InversePairs(buffer, data.size()) % MODNUM;
	delete[] buffer;
	return ret;
}


int main()
{
	int N;
	cin >> N;
	vector<int>data(N);
	for (int i = 0;i < N;++i)
		cin >> data[i];

	int ret = InversePairs(data);

	cout << ret << endl;
	system("pause");
	return 0;
}