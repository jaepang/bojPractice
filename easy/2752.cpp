#include <stdio.h>

int main() {
    int n[3], temp;
    scanf("%d%d%d", n, n+1, n+2);
    if(n[0] > n[1]) {
        temp = n[0];
        n[0] = n[1];
        n[1] = temp;
    }
    if(n[1] > n[2]) {
        temp = n[1];
        n[1] = n[2];
        n[2] = temp;
    }
    if(n[0] > n[1]) {
        temp = n[0];
        n[0] = n[1];
        n[1] = temp;
    }
    printf("%d %d %d\n", n[0], n[1], n[2]);
}