#pragma once
#include<iostream>
using namespace std;


//Ҫ���ܣ������1��2��5����������ͬ������ϵĺ�Ϊ100����ϸ���

int combinationOfsum(int num)
{
	int cnt = 0;

	for (int i = 0;i <= num;i += 5)
	{
		cnt += (i + 2) / 2;
	}
	return cnt;
}
