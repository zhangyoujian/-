#pragma once
#include<iostream>
using namespace std;

//暴力循环法
//时间复杂度为O(N2)
int PrimeSimple(int N)
{
	int cnt = 0;
	for (int i = 2;i <= N;++i)
	{
		bool flag = true;
		for (int j = 2;j < i;++j)
		{
			if (i%j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	return cnt;
}

//朴素筛选法 O(Nsqrt(N))
int PrimeSqrt(int N)
{
	int cnt = 0;
	for (int i = 2;i <= N;++i)
	{
		bool flag = true;
		for (int j = 2;j*j <=i;++j)
		{
			if (i%j == 0)
			{
				flag = false;
				break;
			}
		}
		if (flag)
			cnt++;
	}
	return cnt;
}


//埃氏（Eratosthenes）筛法 O(Nloglog(N))

int PrimeEra(int n)
{
	char *buffer = new char[n+1];
	memset(buffer, 0, sizeof(char)*n);
	int cnt = 0;
	for (int i = 2;i <= n;++i)
	{
		if (buffer[i] == 0)
		{
			cnt++;
			for (int j = i;j <= n;j += i)
			{
				buffer[j] = 1;
			}
		}
	}

	delete[] buffer;
	return cnt;
}

//欧拉（Euler）筛选法 O(N)
int primeEu(int N)
{
	char *visited = new char[N + 1];
	int *prime = new int[N + 1];

	memset(visited, 0, sizeof(char)*N);
	int cnt = 0;
	for (int i = 2;i <= N;++i)
	{
		if (!visited[i])
			prime[cnt++] = i;

		for (int j = 0;j < cnt && i*prime[j] <= N;++j)
		{
			visited[i*prime[j]] = 1;
//关键  每一个筛选数，只被一个数乘以它的最小素因子，如果i % prime[j] == 0，则证明 i中含有prime[j]这个素因子，所以prime[j + 1] 至 prime[prime.size()-1]都不是最小素因子
			if (i%prime[j] == 0)
				break;
		}
	}




	delete[] prime;
	delete[] visited;
	return cnt;
}