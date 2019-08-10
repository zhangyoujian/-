#pragma once
#include<iostream>
#include<string>
using namespace std;

bool ismatch(char *str, char *pattern)
{
	if (*str == '\0' && *pattern=='\0')
		return true;

	if (*pattern == '\0')
		return false;

	char *pnext = pattern;
	pnext++;

	if (*pnext == '*')
	{
		if (*str == *pattern || (*pattern == '.' && *str!='\0'))
			return ismatch(str + 1, pattern + 2) | ismatch(str + 1, pattern) | ismatch(str, pattern + 2);
		else
			return ismatch(str, pattern + 2);
	}
	
	if (*str == *pattern || (*pattern == '.' && *str != '\0'))
		return ismatch(str+1, pattern + 1);
	
	return false;
}


bool RegularExmatch(char *str, char *pattern)
{
	if (str == NULL || pattern == NULL)
		return false;

	return ismatch(str, pattern);
}

