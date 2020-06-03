/* 
 * 14226. 이모티콘
 * 영선이는 매우 기쁘기 때문에, 효빈이에게 스마일 이모티콘을 S개 보내려고 한다.
 * 영선이는 이미 화면에 이모티콘 1개를 입력했다. 이제, 다음과 같은 3가지 연산만 사용해서 이모티콘을 S개 만들어 보려고 한다.
 *  1. 화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장한다.
 *  2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
 *  3. 화면에 있는 이모티콘 중 하나를 삭제한다.
 * 모든 연산은 1초가 걸린다. 또, 클립보드에 이모티콘을 복사하면 이전에 클립보드에 있던 내용은 덮어쓰기가 된다. 
 * 클립보드가 비어있는 상태에는 붙여넣기를 할 수 없으며, 일부만 클립보드에 복사할 수는 없다. 
 * 또한, 클립보드에 있는 이모티콘 중 일부를 삭제할 수 없다. 화면에 이모티콘을 붙여넣기 하면, 클립보드에 있는 이모티콘의 개수가 화면에 추가된다.
 * 영선이가 S개의 이모티콘을 화면에 만드는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.
 * 
 * 첫째 줄에 S (2 ≤ S ≤ 1000) 가 주어진다.
 * 
 * 첫째 줄에 이모티콘을 S개 만들기 위해 필요한 시간의 최솟값을 출력한다.
 * 
 * Gold 5
 */
#include <stdio.h>
#include <queue>
#include <utility>
using namespace std;

int s;
int BFS();
bool visited[1001][1001];
class element {
    public:
        int wd;
        int clip;
        int time;
        element(){}
        element(int a, int b, int c) {
            this->wd = a;
            this->clip = b;
            this->time = c;
        }
};

int main() {
    scanf("%d", &s);
    printf("%d\n", BFS());
    return 0;
}

int BFS() {
    queue <element> q;
    element cur, nxt;
    q.push(*(new element(1, 0 ,0)));
    while(!q.empty()) {
        cur = q.front();
        // printf("(%d / %d / %d)\n", cur.wd, cur.clip, cur.time);
        if(cur.wd == s)
            return cur.time;
        nxt = cur;
        q.pop();
        visited[cur.wd][cur.clip] = true;
        // paste
        nxt.time++;
        nxt.wd += nxt.clip;
        if(0<nxt.wd && nxt.wd<=1000 && 0<nxt.clip && nxt.clip<=1000 && !visited[nxt.wd][nxt.clip])
            q.push(nxt);
        // copy
        nxt.clip = cur.wd;
        nxt.wd = cur.wd;
        if(0<nxt.wd && nxt.wd<=1000 && 0<nxt.clip && nxt.clip<=1000 && !visited[nxt.wd][nxt.clip])
            q.push(nxt);
        // delete
        nxt.wd --;
        nxt.clip = cur.clip;
        if(0<nxt.wd && nxt.wd<=1000 && 0<nxt.clip && nxt.clip<=1000 && !visited[nxt.wd][nxt.clip])
            q.push(nxt);
    }
    return -1;
}
