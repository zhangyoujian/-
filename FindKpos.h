#pragma once
#include<iostream>
#include<vector>
using namespace std;

int findKpos(vector<int> nums, int begin, int end, int K)
{
	if (begin >= end)
		return nums[begin];

	int i = begin;
	int j = i + 1;
	int temp;

	for (;j <= end;++j)
	{

		if (nums[j] <= nums[begin])
		{
			i++;
			if (i != j)
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}

	temp = nums[begin];
	nums[begin] = nums[i];
	nums[i] = temp;

	if (i + 1 == K)
		return nums[i];

	if (i + 1 < K && (i + 1 < end))
		return findKpos(nums, i + 1, end, K - i - 1);
	else if (i + 1 > K && (i - 1 > begin))
		return findKpos(nums, begin, i - 1, i);

	else
		return -1000000;

}