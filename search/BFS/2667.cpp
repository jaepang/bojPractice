/*
 * 2667. 단지번호붙이기
 * <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 
 * 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 
 * 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. 
 * <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 
 * 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.
 * 
 * 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 
 * 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.
 * 
 * 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
 * 
 * Silver 1
 */
#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int map[25][25];
bool visited[625];
vector <pair <int, int> > houses;
int n, groups, h;
void parse(int seq, int arr[], char str[]);
int BFS(int idx);
int search(int r, int c);

int main() {
    vector <int> gcnt;
    char input[26];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%s", input);
        parse(i, map[i], input);
    }
    for(int i=0; i<h; i++) {
        if(!visited[i]) {
            groups++;
            gcnt.push_back(BFS(i));
        }
    }
    printf("%d\n", groups);
    sort(gcnt.begin(), gcnt.end());
    for(int i=0; i<groups; i++)
        printf("%d\n", gcnt[i]);
    return 0;
}

void parse(int seq, int arr[], char str[]) {
    for(int i=0; i<n; i++) {
        arr[i] = str[i]-'0';
        if(arr[i] == 1) {
            h++;
            houses.push_back(make_pair(seq, i));
        }
    }
}

int search(int r, int c) {
    if(0<=r && r<n && 0<=c && c<n) {
        for(int i=0; i<h; i++) {
            if(houses[i].first == r && houses[i].second == c)
                return i;
        }
    }
    return -1;
}

int BFS(int idx) {
    queue <int> q;
    int cur, r, c, cnt=0;
    int dir;
    q.push(idx);
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        if(visited[cur] || cur==-1)
            continue;
        visited[cur] = true;
        cnt++;
        r = houses[cur].first;
        c = houses[cur].second;
        //printf("%d %d (%d)\n", r, c, cur);
        dir = search(r-1, c);
        if(dir >= 0 && !visited[dir])
            q.push(dir);
        
        dir = search(r+1, c);
        if(dir >= 0 && !visited[dir])
            q.push(dir);
        
        dir = search(r, c-1);
        if(dir >= 0 && !visited[dir])
            q.push(dir);
        
        dir = search(r, c+1);
        if(dir >= 0 && !visited[dir])
            q.push(dir);
    }
    //printf("\n");
    return cnt;
}
