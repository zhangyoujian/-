#pragma once
#include<iostream>
#include<vector>
using namespace std;
#define MIN_INT (31<<1)

int max(int a, int b, int c)
{
	return ((a > b ? a : b) > c) ? (a > b ? a : b) : c;
}

int min(int a, int b, int c)
{
	return ((a < b ? a : b) < c) ? (a < b ? a : b) : c;
}


int maxProduct(vector<int>& nums) {

	int N = nums.size();
	if (N < 1)
		return 0;

	int maxPro = nums[0];
	int maxP = nums[0];
	int minP = nums[0];
	int temp;

	for (int i = 1;i < N;++i)
	{
		temp = maxP;
		maxP = max(nums[i], temp*nums[i], minP*nums[i]);
		minP = min(nums[i], temp*nums[i], minP*nums[i]);

		maxPro = maxPro > maxP ? maxPro : maxP;
	}
	return maxPro;

}
