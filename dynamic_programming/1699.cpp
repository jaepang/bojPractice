/*
 * 1699. 제곱수의 합
 * 어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다. 예를 들어 11=32+12+12(3개 항)이다. 
 * 이런 표현방법은 여러 가지가 될 수 있는데, 11의 경우 11=22+22+12+12+12(5개 항)도 가능하다. 
 * 이 경우, 수학자 숌크라테스는 “11은 3개 항의 제곱수 합으로 표현할 수 있다.”라고 말한다. 
 * 또한 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로, 11을 그 합으로써 표현할 수 있는 제곱수 항의 최소 개수는 3이다.
 * 주어진 자연수 N을 이렇게 제곱수들의 합으로 표현할 때에 그 항의 최소개수를 구하는 프로그램을 작성하시오.
 * 
 * 첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 100,000)
 * 
 * 주어진 자연수를 제곱수의 합으로 나타낼 때에 그 제곱수 항의 최소 개수를 출력한다.
 * 
 * Silver 3
 */
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int n;
int dp[100001];

int main() {
    dp[1]=1; dp[2]=2; dp[3]=3;
    scanf("%d", &n);
    for(int i=2; i*i<=n; i++)
        dp[i*i] = 1;
    for(int i=4; i<=n; i++) {
        if(dp[i] == 1)
            continue;
        dp[i] = dp[i-1] + 1;
        int sqr = (int)sqrt(i);
        for(int j=sqr; j>=1; j--)
            dp[i] = min(dp[i], 1+dp[i-(j*j)]);
    }
    printf("%d\n", dp[n]);
    return 0;
}

int knapsack(int t) {
    //printf("===== knapsack(%d) =====\n", t);
    int dp[320];
    int lev = 0, cnt, tmp;
    dp[0] = t+1;
    while(true) {
        cnt = 0;
        lev++;
        tmp = t;
        if(lev*lev > tmp) {
            break;
        }
        cnt = tmp / (lev*lev);
        tmp -= lev*lev * cnt;
        //printf("cnt: %d\n", cnt);
        if(tmp > 0)
            cnt += knapsack(tmp);
        //printf("cnt': %d\n", cnt);
        dp[lev] = min(dp[lev-1], cnt);
        //printf("lev: %d dp: %d\n", lev, dp[lev]);
    }
    // printf("========================\nreturn %d\n", dp[lev-1]);
    return dp[lev-1];
}