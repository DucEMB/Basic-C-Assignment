#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	string input;
	getline(cin,input);
	stack<char> st;
	stack<int> idx;
	int i;
	for (i = 0;i < input.length();i++)
	{
		if ( input[i] == 47)
		{
			st.push(input[i]);
			idx.push(i);
		}
		else if (input[i] == 92)
		{
			reverse(input.begin() + idx.top(),input.begin() + i + 1);
			idx.pop();
		}
	}
	for (i = 0;i < input.length();i++)
	{
		if (input[i] != 47 && input[i] != 92)
		{
			cout<<input[i];
		}
	}
}
