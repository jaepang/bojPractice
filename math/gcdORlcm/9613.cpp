/*
 * 9613. GCD합
 * 양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 테스트 케이스의 개수 t (1 ≤ t ≤ 100)이 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있다. 
 * 각 테스트 케이스는 수의 개수 n (1 < n ≤ 100)가 주어지고, 다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1000000을 넘지 않는다.
 *
 * 각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.
 *
 */
#include <stdio.h>
#include <stdlib.h>

long long gcdSum;
int n;
int *nums;
int gcd(int a, int b);
void add();

int main() {
    int t;
    scanf("%d", &t);
    for(int i=0; i<t; i++) {
        gcdSum = 0;
        scanf("%d", &n);
        nums = (int*)malloc(sizeof(int) * n);
        for(int j=0; j<n; j++) {
            scanf("%d", nums+j);
        }
        add();
        printf("%lld\n", gcdSum);
    }
    return 0;
}

int gcd(int a, int b) {
    int tmp;
    while(b > 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}
void add() {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            gcdSum += gcd(nums[i], nums[j]);
        }
    }
}
