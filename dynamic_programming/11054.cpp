/*
 * 11054. 가장 긴 바이토닉 부분수열
 * 수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN을 만족한다면, 그 수열을 바이토닉 수열이라고 한다.
 * 예를 들어, {10, 20, 30, 25, 20}과 {10, 20, 30, 40}, {50, 40, 25, 10} 은 바이토닉 수열이지만,  {1, 2, 3, 2, 1, 2, 3, 2, 1}과 {10, 20, 30, 40, 20, 30} 은 바이토닉 수열이 아니다.
 * 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이를 구하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 수열 A의 크기 N이 주어지고, 
 * 둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ N ≤ 1,000, 1 ≤ Ai ≤ 1,000)
 *
 * 첫째 줄에 수열 A의 부분 수열 중에서 가장 긴 바이토닉 수열의 길이를 출력한다.
 *
 * Gold 3
 */
#include <stdio.h>

int dp[1001][2];
int num[1001];

int main() {
    int n, biggest, largest;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", num+i);
    dp[1][0] = 1; dp[1][1] = 1;
    for(int i=2; i<=n; i++) {
        biggest = 0;
        largest = 0;
        for(int j=i-1; j>0; j--) {
            if(num[i] > num[j])
                biggest = biggest<dp[j][0] ? dp[j][0]:biggest;
            if(num[j] > num[i]) {
                largest = largest<dp[j][0] ? dp[j][0]:largest;
                largest = largest<dp[j][1] ? dp[j][1]:largest;
            }
           //printf("%d %d ", biggest, largest);
        }
        dp[i][0] = biggest+1;
        dp[i][1] = largest+1;
        //printf("%d %d\n", dp[i][0], dp[i][1]);
    }
    biggest = dp[1][0];
    for(int i=2; i<=n; i++) {
        biggest = biggest<dp[i][0] ? dp[i][0]:biggest;
        biggest = biggest<dp[i][1] ? dp[i][1]:biggest;
    }
    printf("%d\n", biggest);
    return 0;
}