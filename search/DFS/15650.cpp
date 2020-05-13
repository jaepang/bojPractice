/* 
 * 15650. N과 M (2)
 * 자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
 * 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
 * 고른 수열은 오름차순이어야 한다.
 * 
 * 첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)
 * 
 * 한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.
 * 수열은 사전 순으로 증가하는 순서로 출력해야 한다.
 * 
 * Silver 3
 */
#include <stdio.h>
#include <stdlib.h>

int n, m;
void DFS(int cur, int depth, int *arr);

int main() {
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n-m+1; i++)
        DFS(i, 0, (int*)malloc(sizeof(int) * m));
    return 0;
}

void DFS(int cur, int depth, int *arr) {
    arr[depth] = cur;
    if(depth == m-1) {
        for(int i=0; i<m; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for(int i=cur+1; i<=n-m+depth+2; i++)
        DFS(i, depth+1, arr);
}
