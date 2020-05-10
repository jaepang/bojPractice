/*
 * 1697. 숨바꼭질
 * 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 
 * 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 
 * 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
 * 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
 * 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
 * 
 * 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.
 * 
 * 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
 * 
 * Silver 1
 */
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int BFS(int n, int k);
bool visited[100001];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", BFS(n, k));
    return 0;
}

int BFS(int n, int k) {
    pair <int, int> cur;
    queue <pair <int, int> > q;
    q.push(make_pair(n, 0));
    visited[n] = true;
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(cur.first == k)
            break;
        if(cur.first<=100000 && !visited[cur.first+1]) {
            q.push(make_pair(cur.first+1, cur.second+1));
            visited[cur.first+1] = true;
        }
        if(0<cur.first && !visited[cur.first-1]) {
            q.push(make_pair(cur.first-1, cur.second+1));
            visited[cur.first-1] = true;
        }
        if(0<cur.first && cur.first*2<=100000 && !visited[cur.first*2] ) {
            q.push(make_pair(cur.first*2, cur.second+1));
            visited[cur.first*2] = true;
        }
    }
    return cur.second;
}
