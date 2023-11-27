#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<string.h>

// link problem : https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/palindrome-swapping-37143cf3/

int main()
{
    char* T = (char*)malloc(200000 * sizeof(char));
    scanf("\n%[^\n]s", T);
    char* S = (char*)malloc(200000 * sizeof(char));
    scanf("\n%[^\n]s", S);
    int i;
    int cnt[256] = {0};
    for (i = 0;i < strlen(T);i++)
    {
        cnt[T[i]]++;
        cnt[S[i]]++;
    }
    for (i = 0;i < 256;i++)
    {
        if (cnt[i] > 0 && cnt[i] % 2 != 0)
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}