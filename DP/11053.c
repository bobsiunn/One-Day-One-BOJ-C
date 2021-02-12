//scanf 에러 방지를 위한 define
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//calloc을 사용하기 위한 모듈 include
#include <stdlib.h>

//메인 함수 선언
int main()
{
    //수열의 길이 n 입력
    int n;
    scanf("%d", &n);
    //n을 동적메모리로 갖는 DP 배열 선언(해당 메모리의 값을 0으로 초기화)
    int * dp = (int *)calloc(n, sizeof(int));
    //n을 동적메모리로 갖는 array 배열 선언(해당 메모리의 값을 0으로 초기화)
    int * array = (int *)calloc(n, sizeof(int));
    //n번 동안
    for(int i=0; i<n; i++)
    {
        //array배열의 각 인덱스에 int 값을 배정(각 수열의 값)
        scanf("%d", &array[i]);
    }
    //n번 동안
    for(int i=0; i<n; i++)
    {
        //i번 동안(처음부터 i직전까지 탐색)
        for(int j=0; j<i; j++)
        {
            //i번째 숫자가 j번째 숫자보다 크고(증가하고), dp는 반대일때 (저장된 수열의 길이가 더 길 때)
            if(array[i] > array[j] && dp[i] < dp[j])
            {
                //j인덱스의 dp값을 i번째 dp값으로 받아온다(업데이트)
                dp[i] = dp[j];
            }
        }
        //값이 없데이트가 되건 되지 않건, 그 자체만으로 길이가 1이므로 1을 더해줌
        dp[i] += 1;
    }
    //dp 배열 내 가장 큰 값을 찾기 위한 max 변수 선언
    int max = 0;
    //n번 동안
    for(int i=0; i<n; i++)
    {
        //dp[i]가 저장된 max값보다 클 때
        if(dp[i] > max)
        {
            //dp[i] 값을 max 값으로 받아옴
            max = dp[i];
        }
    }
    //max값을 출력
    printf("%d", max);
    //함수 종료
    return 0;
}