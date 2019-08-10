#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


void generateCore(vector<string> &result, string ans, int left,int right)
{
	if (left == 0 && right == 0)
	{
		result.push_back(ans);
		return;
	}

	if (right > 0)
		generateCore(result, ans + ')', left, right-1);
	if(left>0)
		generateCore(result, ans + '(', left-1, right + 1);
}
vector<string> generateParenthesis(int n) {
   
	vector<string> result;
	generateCore(result, "", n, 0);
	return result;
}


void test()
{
	int n = 3;
	vector<string> result;
	result = generateParenthesis(n);
	for (int i = 0;i < (int)result.size();++i)
	{
		cout << result[i] << endl;
	}
	cout << endl;
}