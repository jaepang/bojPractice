/* 
 * 15988. 1, 2, 3 더하기 3
 * 정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.
 * 1+1+1+1
 * 1+1+2
 * 1+2+1
 * 2+1+1
 * 2+2
 * 1+3
 * 3+1
 * 정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 1,000,000보다 작거나 같다.
 *
 * 각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.
 *
 * Silver 2
 */
#include <stdio.h>
#include <vector>
using namespace std;

long long a[1000001];

int main() {
    int n, t, prev=3;
    a[0]=0;
    a[1]=1;
    a[2]=2;
    a[3]=4;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        scanf("%d", &n);
        // printf("prev: %d\n", prev);
        for(int j=prev+1; j<=n; j++)
            a[j] = (a[j-1]+a[j-2]+a[j-3])%1000000009;
        printf("%lld\n", a[n]);
        //for(int j=0; j<a.size(); j++)
        //    printf("%d ", a[j]);
        //printf("\n");
        prev = n>3 ? n:3;
    }
    return 0;
}