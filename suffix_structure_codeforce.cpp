#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	string s;
	string t;
	getline(cin,s);
	getline(cin,t);
	int cnts[256] = {0};
	int cntt[256] = {0};
	int i;
	int j;
	string tmp_t;
	string tmp_s;
	tmp_s = s;
	int idx = 0;
	bool check_suffix = true;
	bool check_automaton = true;
	for (i = 0;i < s.length();i++)
	{
		cnts[s[i] + '\0']++;
	}
	for (i = 0;i < t.length();i++)
	{
		cntt[t[i] + '\0']++;
	}
	for (i = 97;i < 123;i++)
	{
		if (cnts[i] < cntt[i])
		{
			cout << "need tree"<<endl;
			return 0;
		}
	}
	if (s.length() == t.length())
	{
		bool check_suffix = true;
		for (i = 0;i < 256;i++)
		{
			if (cnts[i] != cntt[i])
			{
				check_suffix = false;
				break;
			}
		}
		if (check_suffix == true)
		{
			cout << "array" <<endl;
			return 0;
		}
	}
	for (i = 0;i < t.length();i++)
	{
		for (j = idx;j < tmp_s.length();j++)
		{
			if (tmp_s[j] == t[i])
			{
				tmp_t.push_back(t[i]);
				tmp_s[j] = '\0';
				idx = j;
				break;
			}
		}
	}
	for (i = 0;i < t.length();i++)
	{
		if (t[i] != tmp_t[i])
		{
			check_automaton = false;
			break;
		}
	}
	if (check_automaton == true)
	{
		cout << "automaton" <<endl;
		return 0;
	}
	if (s.length() > t.length())
	{
		cout << "both" <<endl;
		return 0;
	}
}
