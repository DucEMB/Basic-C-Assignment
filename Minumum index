#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	int q;
	int i;
	int tmp;
	int sum;
	cin >> n >> q;
	int a[100000];
	for (i = 0;i < n;i++)
	{
		cin >> a[i];
	}
	int sumarr[100000];
	for (i = 0;i < n;i++)
	{
		tmp = a[i];
		sum = 0;
		while (tmp > 0)
		{
			sum += (tmp % 10);
			tmp /= 10;
		}
		sumarr[i] = sum;
	}
	while (q--)
	{
		int query;
		cin >> query;
		int ans = -1;
		for (i = query;i < n;i++)
		{
			if (a[i] > a[query - 1] && sumarr[i] < sumarr[query - 1])
			{
				ans = i + 1;
				break;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
