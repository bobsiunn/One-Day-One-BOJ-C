//scanf 오류 방지용
#define _CRT_SECURE_NO_WARNINGS
//min 함수 사전 정의
#define MIN(a,b) (a<b ? a:b)
#include <stdio.h>
//동적 할당을 위한 import
#include <stdlib.h>
//메인 함수
int main()
{
    //주어진 집의 숫자
    int n;
    scanf("%d", &n);
    //각 집을 RGB로 색칠하는 데 드는 비용 2차원 배열 동적 할당
    int **house = (int **)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        house[i] = (int *)calloc(3, sizeof(int));
        for(int j=0; j<3; j++)
        {
            int color;
            scanf("%d", &color);
            house[i][j] = color;
        }
    }
    //해당 집을 각각 R,G,B로 색칠 시 드는 비용의 최솟값을 저장하는 DP 2차원 배열
    int **dp = (int **)calloc(n, sizeof(int));
    for(int i=0; i<3; i++)
    {
        dp[i] = (int *)calloc(3, sizeof(int));
    }
    //첫번째 줄은 색칠 비용과 최솟값이 동일
    dp[0] = house[0];
    //모든 줄에 대해
    for(int i=1; i<n; i++)
    {
        //R 색칠 비용은 색칠비용 + 이전 줄 G, B 색칠 중 작은 값
        dp[i][0] = MIN(dp[i-1][1] + house[i][0], dp[i-1][2] + house[i][0]);
        //G 색칠 비용은 색칠비용 + 이전 줄 R, B 색칠 중 작은 값
        dp[i][1] = MIN(dp[i-1][0] + house[i][1], dp[i-1][2] + house[i][1]);
        //B 색칠 비용은 색칠비용 + 이전 줄 R, G 색칠 중 작은 값
        dp[i][2] = MIN(dp[i-1][0] + house[i][2], dp[i-1][1] + house[i][2]);
    }
    //마지막 줄에 저장된 RGB 색칠 비용 중 가장 작은 값을 출력
    printf("%d", MIN(dp[n-1][0], MIN(dp[n-1][1], dp[n-1][2])));
}