#pragma once
#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;



void mutiply(string a, string b)
{
	int n = a.size();
	int m = b.size();

	if (n < 1 || m < 1 || a == "0" || b == "0")
		cout << 0;

	char Flaga = a[0];
	char Flagb = b[0];
	if (Flaga == '-' || Flaga == '+')
	{
		a.erase(0, 1);
		n--;
	}
	if (Flagb == '-' || Flagb == '+')
	{
		b.erase(0, 1);
	}
		
	char *Buffer = new char[m + n + 2];
	memset(Buffer, 0, sizeof(char)*(m + n+2));
	int OverFlow = 0;
	int i = 0;

	for (int P = 0;P < m;++P)
	{
		for (i = 0;i < n;++i)
		{
			Buffer[i + P] = (Buffer[i + P]+ (a[i] - '0')*(b[P] - '0') + OverFlow ) % 10;
			OverFlow = (Buffer[i + P] + (a[i] - '0')*(b[P] - '0') + OverFlow) / 10;
		}
		Buffer[i + P] = OverFlow;
		OverFlow = 0;
	}

	string flag = "";
	if ((Flaga == '-' && Flagb != '-') || (Flaga != '-' && Flagb == '-'))
		flag = "-";
	cout << flag;

    
	bool firstNozerso = false;
	for (int i = m + n - 1;i >= 0;i--)
	{
		if (Buffer[i] != 0)
			firstNozerso = true;
		if(firstNozerso)
			cout << Buffer + '0';
	}

	delete[] Buffer;
}



int main()
{

	string a;
	string b;
	cin >> a >> b;
	mutiply(a, b);
	return 0;
}