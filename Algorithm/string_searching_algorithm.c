#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void naive_pattern_searching(char str[],char pat[])
{
	int i;
	int j;
	int patlength = strlen(pat);
	int strlength = strlen(str);
	for (i = 0;i <= strlength - patlength;i++)
	{
		if (str[i] == pat[0])
		{
			for (j = 0;j < patlength;j++)
			{
				if (str[i + j] != pat[j])
				{
					break;
				}
			}
			if (j == patlength)
			{
				printf("%d ",i);
			}
		}	
	}
}
void compute_lps(char str[],char pat[],int lps[])
{
	lps[0] = 0;
	int i = 1;
	int patlength = strlen(pat);
	int len = 0;
	while (i < patlength)
	{
		if (pat[i] == pat[len])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len - 1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void kmp_searching(char str[],char pat[])
{
	int strlength = strlen(str);
	int patlength = strlen(pat);
	int lps[patlength];
	compute_lps(str,pat,lps);
	int i = 0;
	int j = 0;
	while (i < strlength)
	{
		if (pat[j] == str[i])
		{
			i++;
			j++;
		}
		if (j == patlength)
		{
			printf("%d ",i - j);
			j = lps[j - 1];
		}
		else if (i < strlen && pat[j] != str[i])
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
	}
}

int main()
{
	char str[100];
	char pat[10];
	printf("Nhap chuoi ban dau: ");
	gets(str);
	printf("Nhap chuoi con can tim: ");
	getchar();
	gets(pat);
	printf("Vi tri xuat hien cua chuoi con: ");
	kmp_searching(str,pat);
	return 0;
}