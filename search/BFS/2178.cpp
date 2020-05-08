/*
 * 2178. 미로 탐색
 * N×M크기의 배열로 표현되는 미로가 있다.
 * 1	0	1	1	1	1
 * 1	0	1	0	1	0
 * 1	0	1	0	1	1
 * 1	1	1	0	1	1
 * 미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 
 * 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
 * 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
 * 위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.
 * 
 * 첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 
 * 각각의 수들은 붙어서 입력으로 주어진다.
 * 
 * 첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
 * 
 * Silver 1
 */
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int map[100][100];
int visited[100][100];
int n, m;
void parse(int seq, char *str);
int BFS();
class node {
    public:
        int r;
        int c;
        int d;
        node(){}
        node(int row, int col, int dist) {
            r = row;
            c = col;
            d = dist;
        };
};

int main() {
    char str[101];
    //int ans=0;
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%s", str);
        parse(i, str);
    }
    int ans = BFS();
    printf("%d\n", ans);
    return 0;
}

void parse(int seq, char *str) {
    for(int i=0; i<m; i++)
        map[seq][i] = str[i] - '0';
}

int BFS() {
    queue <node> q; // 0,1:좌표 2:칸 수
    node cur;
    node init(0, 0, 1);
    node tmp;
    q.push(init);
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(!(0<=cur.r && cur.r<n && 0<=cur.c && cur.c<m)
            || map[cur.r][cur.c]==0 || visited[cur.r][cur.c])
            continue;
        if(cur.r == n-1 && cur.c == m-1)
            break;
        
        visited[cur.r][cur.c] = true;
        tmp.d = cur.d+1;

        tmp.r = cur.r-1;
        tmp.c = cur.c;
        q.push(tmp);
        tmp.r = cur.r;
        tmp.c = cur.c-1;
        q.push(tmp);
        tmp.r = cur.r;
        tmp.c = cur.c+1;
        q.push(tmp);
        tmp.r = cur.r+1;
        tmp.c = cur.c;
        q.push(tmp);
    }
    return cur.d;
}
