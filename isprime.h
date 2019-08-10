#pragma once
#include<iostream>
using namespace std;

//����ѭ����
//ʱ�临�Ӷ�ΪO(N2)
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

//����ɸѡ�� O(Nsqrt(N))
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


//���ϣ�Eratosthenes��ɸ�� O(Nloglog(N))

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

//ŷ����Euler��ɸѡ�� O(N)
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
//�ؼ�  ÿһ��ɸѡ����ֻ��һ��������������С�����ӣ����i % prime[j] == 0����֤�� i�к���prime[j]��������ӣ�����prime[j + 1] �� prime[prime.size()-1]��������С������
			if (i%prime[j] == 0)
				break;
		}
	}




	delete[] prime;
	delete[] visited;
	return cnt;
}