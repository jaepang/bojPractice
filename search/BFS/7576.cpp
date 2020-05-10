/*
 * 7576. 토마토
 * 철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 
 * 토마토는 아래의 그림과 같이 격자 모양 상자의 칸에 하나씩 넣어서 창고에 보관한다. 
 * 창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 
 * 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 
 * 하나의 토마토의 인접한 곳은 왼쪽, 오른쪽, 앞, 뒤 네 방향에 있는 토마토를 의미한다. 
 * 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 
 * 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수를 알고 싶어 한다.
 * 토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 
 * 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 
 * 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.
 * 
 * 첫 줄에는 상자의 크기를 나타내는 두 정수 M,N이 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 
 * 단, 2 ≤ M,N ≤ 1,000 이다. 둘째 줄부터는 하나의 상자에 저장된 토마토들의 정보가 주어진다. 
 * 즉, 둘째 줄부터 N개의 줄에는 상자에 담긴 토마토의 정보가 주어진다. 
 * 하나의 줄에는 상자 가로줄에 들어있는 토마토의 상태가 M개의 정수로 주어진다. 
 * 정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 
 * 
 * 여러분은 토마토가 모두 익을 때까지의 최소 날짜를 출력해야 한다. 
 * 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다.
 * 
 * Silver 1
 */
#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int n, m;
vector <pair <int, int> > mature;
int map[1000][1000];
bool complete();
int BFS();
class node {
    public:
        int r;
        int c;
        int d;
        node(){}
        node(int row, int col, int days) {
            r = row;
            c = col;
            d = days;
        };
};


int main() {
    int days;
    scanf("%d%d", &m, &n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%d", &map[i][j]);
            if(map[i][j] == 1)
                mature.push_back(make_pair(i, j));
        }
    }
    days = BFS();
    if(complete())
        printf("%d\n", days);
    else
        printf("-1\n");
    
    return 0;
}

bool complete() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(map[i][j] == 0)
                return false;
        }
    }
    return true;
}

int BFS() {
    int r, c;
    int size = mature.size();
    node cur;
    queue <node> q;
    for(int i=0; i<size; i++)
        q.push(node(mature[i].first, mature[i].second, 0));
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        r = cur.r;
        c = cur.c;
        // printf("%d %d %d\n", cur.r, cur.c, cur.d);
        // -1 0 / 0 -1 / 0 +1 / +1 0
        if(0<=r-1 && map[r-1][c] == 0) {
            map[r-1][c] = 1;
            q.push(node(r-1, c, cur.d+1));
        }
        if(0<=c-1 && map[r][c-1] == 0) {
            map[r][c-1] = 1;
            q.push(node(r, c-1, cur.d+1));
        }
        if(c+1<m && map[r][c+1] == 0) {
            map[r][c+1] = 1;
            q.push(node(r, c+1, cur.d+1));
        }
        if(r+1<n && map[r+1][c] == 0) {
            map[r+1][c] = 1;
            q.push(node(r+1, c, cur.d+1));
        }
    }
    return cur.d;
}
