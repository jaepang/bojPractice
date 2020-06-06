/* 
 * 13549. 숨바꼭질 3
 * 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 
 * 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
 * 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다. 
 * 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
 * 
 * 첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.
 * 
 * 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
 * 
 * Gold 5
 */
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int n, k;
bool visited[100001];
int BFS();

int main() {
    scanf("%d%d", &n, &k);
    printf("%d\n", BFS());
    return 0;
}

int BFS() {
    deque <pair <int, int> > q;
    pair <int, int> cur, nxt;
    q.push_front(make_pair(n, 0));
    while(!q.empty()) {
        cur = q.front();
        q.pop_front();
        visited[cur.first] = true;
        if(cur.first == k)
            return cur.second;
        nxt.second = cur.second+1;
        nxt.first = cur.first+1;
        if(0<=nxt.first && nxt.first<=100000 && !visited[nxt.first])
            q.push_back(nxt);
        nxt.first = cur.first-1;
        if(0<=nxt.first && nxt.first<=100000 && !visited[nxt.first])
            q.push_back(nxt);
        nxt.second = cur.second;
        nxt.first = cur.first*2;
        if(0<=nxt.first && nxt.first<=100000 && !visited[nxt.first])
            q.push_front(nxt);
    }
    return -1;
}