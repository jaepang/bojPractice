/*
 * 14002. 가장 긴 증가하는 부분수열 4
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 * 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.
 *
 * 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
 * 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
 *
 * 첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.
 * 둘째 줄에는 가장 긴 증가하는 부분 수열을 출력한다. 그러한 수열이 여러가지인 경우 아무거나 출력한다.
 *
 * Gold 4
 */
#include <stdio.h>

int dp[1001][2];
int num[1001];
int ans[1001];

int main() {
    int n, biggest, idx;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", num+i);
    dp[1][0] = 1;
    for(int i=2; i<=n; i++) {
        biggest = 0;
        for(int j=i-1; j>0; j--) {
            if(num[i] > num[j]) {
                if(biggest < dp[j][0]) {
                    biggest = dp[j][0];
                    dp[i][1] = j;
                }
            }
        }
        dp[i][0] = biggest+1;
    }
    biggest = dp[1][0];
    idx = 1;
    for(int i=2; i<=n; i++) {
        if(biggest < dp[i][0]) {
            biggest = dp[i][0];
            idx = i;
        }
    }
    for(int i=biggest; i>=1; i--) {
        ans[i] = num[idx];
        idx = dp[idx][1];
    }
    
    printf("%d\n", biggest);
    for(int i=1; i<=biggest; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}