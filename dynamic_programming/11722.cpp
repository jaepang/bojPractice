/*
 * 11722. 가장 긴 감소하는 부분수열
 * 수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.
 * 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
 *
 * 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
 * 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
 *
 * 첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.
 *
 * Silver 1
 */
#include <stdio.h>

int dp[1001];
int num[1001];

int main() {
    int n, biggest;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", num+i);
    dp[1] = 1;
    for(int i=2; i<=n; i++) {
        biggest = 0;
        for(int j=i-1; j>0; j--) {
            if(num[i] < num[j])
                biggest = biggest<dp[j] ? dp[j]:biggest;
            //printf("%d ", biggest);
        }
        dp[i] = biggest+1;
        //printf("%d\n", dp[i]);
    }
    biggest = dp[1];
    for(int i=2; i<=n; i++)
        biggest = biggest<dp[i] ? dp[i]:biggest;
    printf("%d\n", biggest);
    return 0;
}