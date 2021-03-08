//scanf 오류 방지
#define _CRT_SECURE_NO_WARNINGS
//MAX 함수 정규표현식
#define MAX(a,b) (a>b ? a:b)
#include <stdio.h>
//동적할당을 위한 모듈 import
#include <stdlib.h>

//메인 함수
int main()
{
    //포도주 잔의 개수 n
    //int = 4byte = 32bit
    int n;
    scanf("%d", &n);
    //각 포도주 잔에 있는 포도주의 양을 저장하는 배열 동적할당
    //grape = 4byte * n = 32bit * n
    int * grape = (int *)malloc(sizeof(int) * n);
    //해당 포도주 잔을 마실 때, 마신 포도주 양의 최대치를 저장하는 배열 동적할당
    //dp = 4byte * n = 32bit * n
    int * dp = (int *)calloc(n, sizeof(int));
    //각 포도주 잔에 있는 포도주의 양을 입력하여 저장
    for(int i=0; i<n; i++){
        scanf("%d", &grape[i]);
    }
    //처음 포도주 잔부터 마지막 포도주 잔까지
    for(int j=0; j<n; j++){
        //첫 포도주 잔일 때
        if(j == 0){
            //첫 잔을 마시면 되므로 DP에 첫 잔의 포도주 양 저장
            dp[j] = grape[0];
        }
        //두번째 잔일 때
        else if(j == 1){
            //첫잔과 둘째잔을 마시면 되므로 DP에 두 잔의 포도주 양 저장
            dp[j] = grape[0] + grape[1];
        }
        //셋째 잔일 때
        else if(j == 2){
            //첫잔과 둘째잔, 첫잔과 셋째잔, 둘째잔과 셋째잔을 마시는 경우 중 가장 많은 양을 저장
            dp[j] = MAX(grape[0] + grape[1], MAX(grape[0] + grape[2], grape[1] + grape[2]));
        }
        //그 이후 잔에 대해
        else{
            //해당 잔을 마시지 않는 경우, 해당 잔을 마시고 그 이전잔과 전전전잔을 마시는 경우, 해당 잔과 전전잔을 마시는 경우 중 가장 많은 양을 저장
            dp[j] = MAX(dp[j-1], MAX(dp[j-2] + grape[j], dp[j-3] + grape[j-1] + grape[j]));
        }
    }
    //마지막 잔의 DP에 저장된 포도주의 양 출력
    printf("%d", dp[n-1]);
}