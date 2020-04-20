/*
 * 2225. 합분해
 * 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수를 구하는 프로그램을 작성하시오.
 * 덧셈의 순서가 바뀐 경우는 다른 경우로 센다(1+2와 2+1은 서로 다른 경우). 또한 한 개의 수를 여러 번 쓸 수도 있다.
 *
 * 첫째 줄에 두 정수 N(1 ≤ N ≤ 200), K(1 ≤ K ≤ 200)가 주어진다.
 *
 * 첫째 줄에 답을 1,000,000,000으로 나눈 나머지를 출력한다.
 * 
 * Gold 5
 */
#include <stdio.h>
#define BILLION 1000000000

long long dp[201][201];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i=0; i<=201; i++) {
        dp[i][1] = 1;
        dp[0][i] = 1;
        // printf("%d: %lld %lld\n", i, dp[i][1], dp[0][i]);
    }
    //printf("???: %lld\n", dp[0][n]);
    for(int j=2; j<=k; j++) {
        for(int i=1; i<=n; i++) {
            for(int l=0; l<=i; l++) {
                // printf("dp[%d][%d]: %lld(%d,%d)+%lld(%d,%d) = %lld\n", i, j, dp[i][j], i, j, dp[l][j-1], l, j-1, dp[i][j]+dp[l][j-1]);
                dp[i][j] = (dp[i][j]+dp[l][j-1]) % BILLION;
            }
        }
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}