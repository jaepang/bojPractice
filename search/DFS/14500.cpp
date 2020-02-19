/*
 * 14500. 테트로미노
 * 폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.
 * 정사각형은 서로 겹치면 안 된다.
 * 도형은 모두 연결되어 있어야 한다.
 * 정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
 * 정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.
    1          2
    * * * *    * *   
               * *
  3 * 4 *    5
    *   * *  * * *
    * *   *    *

 * 아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.
 * 테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.
 * 테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.
 *                                                                        ^^^^^^^^^^^^^^^^^^^^^^^^^
 * 첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)
 * 둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 
 * 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.
 *
 * 첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
 *
 */
#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector < vector<int> > matrix;
vector < vector<bool> > visited;
pair<int, int> path[4];
int n, m;
int largest;
void DFS(int depth, int r, int c);
void calcT();
int getVal(int r, int c, pair<int, int> shape[]);

int main() {
    vector <int> input;
    int tmp;
    scanf("%d%d", &n, &m);
    visited = vector<vector<bool> >(n, vector<bool>(m, false));
    for(int i=0; i<n; i++) {
        input.clear();
        for(int j=0; j<m; j++) {
            scanf("%d", &tmp);
            input.push_back(tmp);
            
        }
        matrix.push_back(input);
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            DFS(0, i, j);
            //visited = vector<vector<bool> >(n, vector<bool>(m, false));
        }
    }
    calcT();
    printf("%d\n", largest);
    return 0;
}

void DFS(int depth, int r, int c) {
    if(!visited[r][c]) {
        path[depth] = make_pair(r, c);
        visited[r][c] = true;
        if(depth == 3) {
            int val = 0;
            for(int i=0; i<4; i++) {
                // printf("(%d,%d)->", path[i].first,path[i].second);
                val += matrix[path[i].first][path[i].second];
            }
            // printf("\n");
            largest = max(largest, val);
            visited[r][c] = false;
            return;
        }
        if(r-1>=0)  DFS(depth+1, r-1, c);
        if(c-1>=0)  DFS(depth+1, r, c-1);
        if(r+1<n)   DFS(depth+1, r+1, c);
        if(c+1<m)   DFS(depth+1, r, c+1);
        visited[r][c] = false;
    }
}

void calcT() {
    int val;
    int sum;
    pair<int, int> shape[4][4] = {{make_pair(0, 1), make_pair(1, 0), make_pair(1, 1), make_pair(2, 1)}, // ㅓ shape
                                  {make_pair(0, 0), make_pair(1, 0), make_pair(1, 1), make_pair(2, 0)}, // ㅏ
                                  {make_pair(0, 1), make_pair(1, 0), make_pair(1, 1), make_pair(1, 2)}, // ㅗ
                                  {make_pair(0, 0), make_pair(0, 1), make_pair(0, 2), make_pair(1, 1)}};// ㅜ

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) {
                val = getVal(i, j, shape[k]);
                // printf("T-val(%d,%d - %d): %d\n", i, j, k, val);
                largest = max(largest, val);
            }
        }
    }
}
int getVal(int r, int c, pair<int, int> shape[]) {
    pair <int, int> location[4];
    bool inRange;
    int sum=0;
    inRange = true;
    for(int i=0; i<4; i++) {
        inRange = inRange && r+shape[i].first<n && c+shape[i].second<m;
        location[i].first = r+shape[i].first;
        location[i].second = c+shape[i].second;
    }
    if(inRange) {
        for(int i=0; i<4; i++)
            sum += matrix[location[i].first][location[i].second];
    }
    return sum;
}