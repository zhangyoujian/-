#pragma once
#include<iostream>
using namespace std;


//要求功能：求出用1，2，5这三个数不同个数组合的和为100的组合个数

int combinationOfsum(int num)
{
	int cnt = 0;

	for (int i = 0;i <= num;i += 5)
	{
		cnt += (i + 2) / 2;
	}
	return cnt;
}
