/*
 * 13023. ABCDE
 * BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.
 * 오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.
 * A는 B와 친구다.
 * B는 C와 친구다.
 * C는 D와 친구다.
 * D는 E와 친구다.
 * 위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.
 * 
 * 첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.
 * 둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.
 * 
 * 문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.
 * 
 * Gold 5
 */
#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int n, m, ans;
int VISITED_ALL;
vector <vector <int> > graph;
void DFS(int cur, int visited, int depth);

int main() {
    int a, b;
    scanf("%d%d", &n, &m);
    graph.resize(n);
    VISITED_ALL = (1<<n) - 1;
    for(int i=0; i<m; i++) {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=0; i<n; i++) {
        DFS(i, 1<<i, 1);
        if(ans) break;
    }
    printf("%d\n", ans);
}

void DFS(int cur, int visited, int depth) {
    if(depth == 5 || visited == VISITED_ALL) {
        ans = depth==5;
        return;
    }
    int size = graph[cur].size();
    for(int i=0; i<size; i++) {
        if((visited & (1 << graph[cur][i])) == 0)
            DFS(graph[cur][i], visited | (1<<graph[cur][i]), depth+1);
    }
}
