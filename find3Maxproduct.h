#pragma once
#include<iostream>
#include<vector>
using namespace std;


int maxThreeProduct(vector<int>&nums)
{
	long long maxVal[3], minVal[3];
	int N = nums.size();

	for (int i = 0;i < 3;++i)
	{
		for (int j = 0;j < N - i - 1;++j)
		{
			if (nums[j] > nums[j + 1])
			{
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
		maxVal[i] = nums[N - 1 - i];
	}

	for (int i = 0;i < 3;++i)
	{
		for (int j = 0;j < N - i - 1;++j)
		{
			if (nums[j] < nums[j + 1])
			{
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
		minVal[i] = nums[N - 1 - i];
	}

	long long max1 = maxVal[0] * maxVal[1] * maxVal[2];
	long long max2 = minVal[0] * minVal[1] * minVal[2];
	long long max3 = minVal[0] * minVal[1] * maxVal[0];


	long long ret = max1 > max2 ? max1 : max2;

	ret = ret > max3 ? ret : max3;
	return ret;
}


int main()
{
	int N;
	cin >> N;
	vector<int>nums(N);
	for (int i = 0;i < N;++i)
		cin >> nums[i];

	long long ret = maxThreeProduct(nums);
	cout << ret;
	system("pause");
	return 0;
}
