#pragma once
#include<iostream>
#include<string>
using namespace std;
#define MAXSIZE 101


bool isMatch(string w, string s)
{
	int pos = 0;
	while (pos < w.size() && pos < s.size()&&(w[pos] == '?' || w[pos]==s[pos]))
	{
		pos++;
	}
	if (pos == w.size())
		return pos == s.size();
	if (w[pos] == '*')
	{
		for (int skip = 0;skip + pos < s.size();++skip)
		{
			if (isMatch(w.substr(pos+1), s.substr(pos + skip)))
				return true;
		}
	}
	return false;
}

int cache[MAXSIZE][MAXSIZE];

int dpMatch(int w, int s,string W, string S)
{
	int &ret = cache[w][s];
	if (ret != -1)
		return ret;

	while (w < W.size() && s < S.size() && (W[w]=='?'||W[w]==S[s]))
	{
		w++;
		s++;
	}

	if (w == S.size())
		return ret = (s == S.size());

	if (W[w] == '*')
	{
		for (int i = 0;w + i <= S.size();++i)
		{
			if (dpMatch(w + 1, s + i, W, S))
				return ret = 1;
		}
	}
	
	return ret = 0;
}

int wiseMatch(int w, int s, string W, string S)
{
	int &ret = cache[w][s];
	if (ret != -1)
		return ret;

	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
	{
		return ret = wiseMatch(w + 1, s + 1, W, S);
	}

	if (w == S.size())
		return ret = (s == S.size());

	
	if (W[w] == '*')
	{
		return ret = wiseMatch(w + 1, s, W, S) || wiseMatch(w, s + 1, W, S);
		if (wiseMatch(w + 1, s, W, S)  || (wiseMatch(w, s + 1, W, S) && s<S.size()))
			return ret = 1;
	}
	 
	return ret = 0;
}





int main()
{
	string a, b;
	cin >> a>>b;
	bool ret = dpMatch(0,0,a, b);
	if (ret)
		cout << "Æ¥Åä" << endl;
	else
		cout << "Î´ÄÜÆ¥Åä" << endl;

	system("pause");
	return 0;
}




