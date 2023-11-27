#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

// link problem : https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/unique-substrings-71b184fb/

int main()
{
	string input;
	getline(cin,input);
	int k;
	cin >> k;
	int i;
	int j;
	int cnt = 0;
	for (i = 0;i < input.length();i++)
	{
		if (input[i] != '#')
		{
			for (j = 1;j <+ k;j++)
			{
				if (input[i+j] == input[i])  // xoa ky tu trung cua substring
				{
					input[i+j] = '#';
					cnt++;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}