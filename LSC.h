#pragma once
#include<iostream>
using namespace std;
#define MAXDATASIZE 100

 int Recursion(int i, int j, int d[][MAXDATASIZE], char Z[][MAXDATASIZE], const string &s1, const string &s2)
{
	 if (s1[i - 1] == s2[j - 1])
	 {
		 Z[i][j] = 'O';
		 return d[i - 1][j - 1] + 1;
	 }
	 else if (d[i - 1][j] >= d[i][j - 1])
	 {
		 Z[i][j] = 'R';
		 return d[i - 1][j];
	 }
	 else
	 {
		 Z[i][j] = 'C';
		 return d[i][j - 1];
	 }
}

 void printLCS(char Z[][MAXDATASIZE], const string &s1, int m, int n)
 {
	 if (m == 0 || n == 0)
		 return;

	 if (Z[m][n] == 'O')
	 {
		 printLCS(Z, s1, m - 1, n - 1);
		 cout << s1[m - 1];
	 }
	 else if (Z[m][n] == 'R')
		 printLCS(Z, s1, m - 1, n);
	 else
		 printLCS(Z, s1, m, n-1);
		  
 }


int fn(string s1, string s2)
{
	const int M = s1.size();
	const int N = s2.size();
	int d[MAXDATASIZE][MAXDATASIZE];
	char Z[MAXDATASIZE][MAXDATASIZE];

	for (int i = 0;i <= M;++i)
		d[i][0] = 0;
	for (int j = 0;j <= N;++j)
		d[0][j] = 0;

	for (int i = 1;i <= M;++i)
		for (int j = 1;j <= N;++j)
			d[i][j] = Recursion(i, j, d, Z, s1, s2);


	printLCS(Z, s1, M, N);
	cout << endl;
	int maxlength = d[M][N];
	return maxlength;
}

void LSCtest()
{
	string s1 = "ABCBDAB";
	string s2 = "BDCABA";

	cout << fn(s1, s2) << endl;

}



