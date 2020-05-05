/*
 * 4963. 섬의 개수
 * 정사각형으로 이루어져 있는 섬과 바다 지도가 주어진다. 섬의 개수를 세는 프로그램을 작성하시오.
 * 한 정사각형과 가로, 세로 또는 대각선으로 연결되어 있는 사각형은 걸어갈 수 있는 사각형이다. 
 * 두 정사각형이 같은 섬에 있으려면, 한 정사각형에서 다른 정사각형으로 걸어서 갈 수 있는 경로가 있어야 한다. 
 * 지도는 바다로 둘러싸여 있으며, 지도 밖으로 나갈 수 없다.
 * 
 * 입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 지도의 너비 w와 높이 h가 주어진다. 
 * w와 h는 50보다 작거나 같은 양의 정수이다. 둘째 줄부터 h개 줄에는 지도가 주어진다. 1은 땅, 0은 바다이다.
 * 입력의 마지막 줄에는 0이 두 개 주어진다.
 * 
 * 각 테스트 케이스에 대해서, 섬의 개수를 출력한다.
 * 
 * Silver 1
 */
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int w, h, islands;
int map[50][50];
bool visited[50][50];
void clearMap(int w, int h);
void BFS(int r, int c);

int main() {
    while(true) {
        scanf("%d%d", &w, &h);
        if(w==0 && h==0)
            break;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++)
                scanf("%d", &map[i][j]);
        }
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(map[i][j]==1 && !visited[i][j]) {
                    islands++;
                    BFS(i, j);
                }
            }
        }
        printf("%d\n", islands);
        clearMap(w, h);
        islands=0;
    }
    return 0;
}

void clearMap(int w, int h) {
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            map[i][j] = 0;
            visited[i][j] = false;
        }
    }
}

void BFS(int r, int c) {
    pair <int, int> cur;
    queue <pair <int,int> > q;
    q.push(make_pair(r, c));
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(!(0<=cur.first && cur.first<h && 0<=cur.second && cur.second<w) 
            || map[cur.first][cur.second]==0 || visited[cur.first][cur.second]) {
            // printf("skip: not in range or not island or visited area\n");
            continue;
        }
        visited[cur.first][cur.second] = true;
        q.push(make_pair(cur.first-1, cur.second-1));
        q.push(make_pair(cur.first-1, cur.second));
        q.push(make_pair(cur.first-1, cur.second+1));

        q.push(make_pair(cur.first, cur.second-1));
        q.push(make_pair(cur.first, cur.second+1));

        q.push(make_pair(cur.first+1, cur.second-1));
        q.push(make_pair(cur.first+1, cur.second));
        q.push(make_pair(cur.first+1, cur.second+1));
    }
}
/*
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
*/