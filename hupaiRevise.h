#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


bool isHu(string nums)
{
	int n = nums.size();
	if (n < 1)
		return true;

	char num0 = nums[0];
	int count0 = 0;
	count0 = nums.find_last_of(num0)- nums.find_first_of(num0)+1;

	if ((n % 3 != 0) && (count0 >= 2) && isHu(string(nums.begin() + 2, nums.end())))
		return true;

	if ((count0 >= 3) && isHu(string(nums.begin() + 3, nums.end())))
		return true;

	if ((nums.find(num0) != nums.npos) && (nums.find(num0 + 1) != nums.npos) && nums.find(num0 + 2) != nums.npos)
	{
		string temp;
		temp = nums;
		temp.erase(temp.find(num0), 1);
		temp.erase(temp.find(num0+1), 1);
		temp.erase(temp.find(num0+2), 1);
		if (isHu(temp))
			return true;
	}

	
	return false;
}


void fn(string nums)
{
	vector<int> result;
	int conuter[10] = { 0 };
	for (string::iterator it = nums.begin();it != nums.end();it++)
		conuter[*it - '0']++;

	for (int i = 1;i <= 9;++i)
	{
		if (conuter[i] == 4)
			continue;

		string copyString = nums;
		char Ch = i+ '0';
		copyString.push_back(Ch);
		sort(copyString.begin(), copyString.end(), [](const char &s1, const char &s2)->bool {return s1 < s2;});
		if (isHu(copyString))
			result.push_back(i);
	}
	if (result.size() < 1)
		cout << 0;
	else
	{
		for (vector<int>::iterator it = result.begin();it != result.end();++it)
		{
			cout << *it << " ";
		}
	}
	cout << endl;
}

void test()
{
	string nums;
	char a;
	for (int i = 0;i < 13;++i)
	{
		cin >> a;
		nums.push_back(a);
	}
	fn(nums);
}
