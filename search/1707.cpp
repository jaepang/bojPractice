/*
 * 1707. 이분그래프
 * 그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록 분할할 수 있을 때, 
 * 그러한 그래프를 특별히 이분 그래프 (Bipartite Graph) 라 부른다.
 * 그래프가 입력으로 주어졌을 때, 이 그래프가 이분 그래프인지 아닌지 판별하는 프로그램을 작성하시오.
 *
 * 입력은 여러 개의 테스트 케이스로 구성되어 있는데, 첫째 줄에 테스트 케이스의 개수 K(2≤K≤5)가 주어진다. 
 * 각 테스트 케이스의 첫째 줄에는 그래프의 정점의 개수 V(1≤V≤20,000)와 간선의 개수 E(1≤E≤200,000)가 
 * 빈 칸을 사이에 두고 순서대로 주어진다. 각 정점에는 1부터 V까지 차례로 번호가 붙어 있다. 
 * 이어서 둘째 줄부터 E개의 줄에 걸쳐 간선에 대한 정보가 주어지는데, 
 * 각 줄에 인접한 두 정점의 번호가 빈 칸을 사이에 두고 주어진다.
 * 
 * K개의 줄에 걸쳐 입력으로 주어진 그래프가 이분 그래프이면 YES, 아니면 NO를 순서대로 출력한다.
 * 
 * Gold 4
 */
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <vector <int> > graph;
bool check(int v);

int main() {
    int n, v, e, a, b;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &v, &e);
        graph.resize(v+1);
        for(int j=0; j<e; j++) {
            scanf("%d%d", &a, &b);
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        printf("%s\n", check(v) ? "YES":"NO");
        graph.clear();
    }
    return 0;
}

bool check(int v) {
    int visited = 3; // 11(2)
    int cur, size;
    vector <int> color(v+1, 0);
    
    for(int i=1; i<=v; i++) {
        size = graph[i].size();
        for(int j=0; j<size; j++)
            color[graph[i][j]] = color[i]==0 ? 1:0;
    }
    for(int i=1; i<=v; i++) {
        // printf("cur: %d(%d)\n", i, color[i]);
        size = graph[i].size();
        for(int j=0; j<size; j++) {
            // printf("%d: %d(%d)\n", i, graph[i][j], color[graph[i][j]]);
            
            if((visited & (1<<graph[i][j])) && color[i] == color[graph[i][j]])
                return false;
            else {
                if((visited & (1<<graph[i][j])) == 0)
                    color[graph[i][j]] = color[i]==0 ? 1:0;
                visited |= (1 << graph[i][j]);
            }
        }
    }
    return true;
}
/*
2
3 2
1 3
2 3
4 4
1 2
2 3
3 4
4 2
for v in 1~graph.size:
	for n in 1~graph[v].size:
		if visited[n] && color[n]==color[v]:
			return false
		else:
			if not visited[n]:
				color[n] = not color[v]
			visited[n] = true
	return true
*/