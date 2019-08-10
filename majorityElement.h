#pragma once
#include<iostream>
#include<vector>
#include<map>
using namespace std;


int majorityElement(vector<int>& nums) {

	map<int,int>Buffer;
	int N = nums.size();
	for (int i = 0;i < N;++i)
	{
		if (Buffer.count(nums[i]))
			Buffer[nums[i]] += 1;
		else
			Buffer[nums[i]] = 1;
	}
	int ACC = -8000000;
	int res;
	
	for (map<int, int>::iterator it = Buffer.begin();it != Buffer.end();it++)
	{
		if (it->second > ACC)
		{
			ACC = it->second;
			res = it->first;
		}
			
	}

	return res;
}

int majorityElement1(vector<int>& nums) {

	int N = nums.size();
	if (N < 1)
		return 0;

	int times = 1;
	int result = nums[0];
	for (int i = 1;i < N;++i)
	{
		if (times == 0)
		{
			result = nums[i];
			times++;
		}
		else if(result == nums[i])
			times++;
		else
			times--;
	}
	return result;
}



void testmajorityElement()
{
	vector<int> nums = { 3,3,4};
	int ret = majorityElement(nums);
	cout << ret << endl;
}
