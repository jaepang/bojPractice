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
            if(num[i] > num[j])
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