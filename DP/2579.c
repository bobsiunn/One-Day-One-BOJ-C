#define _CRT_SECURE_NO_WARNINGS
#define MAX(a,b) (a>b ? a:b)
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *s, *dp;
    scanf("%d", &n);

    //동적 할당을 이용한 s, dp생성
    s = (int *)malloc(sizeof(int) * n);
    dp = (int *)malloc(sizeof(int) * n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &s[i]);
        printf("%d", &s[i]);
    }

    for(int i=0; i<n; i++)
    {
        if(i == 0)
        {
            dp[i] = s[0];
        }
        else if(i == 1)
        {
            dp[i] = s[0] + s[1];
        }
        else if(i == 2)
        {
            dp[i] = MAX(s[0]+s[2], s[1]+s[2]);
        }
        else
            dp[i] = MAX(dp[i-3]+s[i-1]+s[i], dp[i-2]+s[i]);
    }
    printf("%d", dp[n-1]);
}
