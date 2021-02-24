//scanf 경고를 막기 위한 선언
#define _CRT_SECURE_NO_WARNINGS
//MAX 함수를 사전에 설정
#define MAX(a,b) (a>b ? a:b)
#include <stdio.h>
//malloc과 calloc을 사용하기 위한 선언
#include <stdlib.h>

//main 함수
int main()
{
    //미로의 세로 길이 n과 미로의 가로 길이 m 선언
    int n, m;
    //미로의 세로 길이 n과 미로의 가로 길이 m 입력
    scanf("%d %d", &n, &m);
    //미로 각 칸의 사탕 수를 저장하는 2차원 배열 메모리 할당
    int **maze = malloc(sizeof(int *) * n);
    //해당 미로로 이동할때 최대 사탕의 개수를 저장하는 DP 2차원 배열 메모리 할당
    int **dp = (int **)calloc(n, sizeof(int));
    //세로줄의 개수만큼 반복
    for(int i=0; i<n; i++)
    {
        //해당 미로 세로 칸에 대해 가로 칸의 길이만큼 메모리 할당
        maze[i] = malloc(sizeof(int *) * m);
        //해당 DP 세로 칸에 대해 가로 칸의 길이만큼 메모리 할당
        dp[i] = (int *)calloc(m, sizeof(int));
    }
    //미로 각 칸에 해당하는 사탕 개수 입력
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    //첫번째 칸은 해당 칸의 사탕 수가 곧 최대 사탕 개수이므로 그대로 받아오기
    dp[0][0] = maze[0][0];
    //모든 세로 칸에 대해
    for(int i=0; i<n; i++)
    {
        //첫번째 세로줄일 때
        if(i == 0)
        {
            //첫번째 새로줄의 2번째 가로 칸부터 끝까지
            for(int j=1; j<m; j++)
            {
                //이전 가로 칸에 저장된 사탕 수에 해당 가로 칸에 저장된 사탕 수 를 더하여 저장
                dp[i][j] = dp[i][j-1] + maze[i][j];
            }
        }
        //두번째~끝까지
        else
        {
            //모든 가로 칸에 대해
            for(int j=0; j<m; j++)
            {
                //첫번째 가로줄일 때
                if(j == 0)
                {
                    //이전 세로 칸에 저장된 사탕 수에 해당 세로 칸에 저장된 사탕 수를 더해 저장
                    dp[i][j] = dp[i-1][j] + maze[i][j];
                }
                //두번째 ~ 끝까지
                else
                {
                    //세로 위 칸, 가로 왼쪽 칸, 대각선 왼쪽 위 칸 중 가장 큰 값을 temp에 저장하고
                    int temp = MAX(dp[i-1][j], MAX(dp[i][j-1], dp[i-1][j-1]));
                    //해당 칸에 있는 사탕 수에 temp를 더함 (최대 사탕의 개수)
                    dp[i][j] = temp + maze[i][j];
                }
            }
        }
    }
    //가장 마지막 칸에 저장된 값을 출력
    printf("%d", dp[n-1][m-1]);
}