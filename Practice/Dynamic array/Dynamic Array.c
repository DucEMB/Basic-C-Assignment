#include <stdio.h>
#include <stdlib.h>

void dynamic_array(int n,int q,int query[q][3])
{
	int lastans = 0;
	int i;
	int anssize = 0;
	int typeofquery;
	int x;
	int y;
	int idx;
	int cursize = 0;
	int * ans = (int *)malloc(q * sizeof(int));
	int** arr = (int**) malloc(n*sizeof(int*));
	for (i = 0;i < q;i++)
	{
		typeofquery = query[i][0];
		x = query[i][1];
		y = query[i][2];
		if (1 == typeofquery)
		{
			cursize = 0;
			idx = (x ^ lastans) % n;
			if (arr[idx] != NULL)
			{
				while (arr[idx][cursize] != 0)
				{
					cursize++;
				}
			}
			arr[idx] = (int *)realloc(arr[idx],(cursize + 2)*sizeof(int));
			arr[idx][cursize] = y;
			arr[idx][cursize + 1] = 0;
		}
		else if (2 == typeofquery)
		{
			idx = (x ^ lastans) % n;
			cursize = 0;
			if (arr[idx] != NULL)
			{
				while (arr[idx][cursize] != 0)
				{
					cursize++;
				}
				lastans = arr[idx][y % cursize];
				ans[anssize++] = lastans;
			}
		}
	}
	for (i = 0;i < n;i++)
	{
		free(arr[i]);
	}
	free(arr);
	for (i = 0;i < anssize;i++)
	{
		printf("%d\n",ans[i]);
	}
	free(ans);
}

int main() 
{
	int n;
	int q;
	int i;
	scanf("%d%d",&n,&q);
	int (*query)[3] = malloc(q * sizeof(query));
	for (i = 0;i < q;i++)
	{
		scanf("%d%d%d",&query[i][0],&query[i][1],&query[i][2]);
	}
	dynamic_array(n,q,query);
	free(query);
	return 0;
}
