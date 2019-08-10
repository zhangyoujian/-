#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


int fn(vector<int>&Score, vector<int> &awake, int K)
{
	int n = Score.size();
	int maxScore = 0;
	int currentScore = 0;
	int maxSofar = 0;
	K = K < n ? K : n;

	for (int i = 0;i < n;++i)
	{
		if (awake[i] != 0)
		{
			maxSofar += Score[i];
		}
	}
	for (int i = 0;i < K;++i)
	{
		if (awake[i] == 0)
			currentScore += Score[i];
	}
	for (int j = K;j < n;++j)
	{
		if (awake[j] == 0)
			currentScore += Score[j];
		if (awake[j - K] == 0)
			currentScore -= Score[j - K];
		maxScore = maxScore > currentScore ? maxScore : currentScore;
	}

	return maxSofar + maxScore;
}


int main(int argc, char *argv[])
{
	int n, K;
	cin >> n >> K;
	vector<int>score(n);
	vector<int>awake(n);
	for (int i = 0;i < n;++i)
		cin >> score[i];
	for (int i = 0;i < n;++i)
		cin >> awake[i];

	int ret = fn(score, awake, K);
	cout << ret;

	system("pause");
	return 0;
}
