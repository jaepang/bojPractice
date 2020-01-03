#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(vector <bool> &visited, vector <int> graph[], int visit);
void BFS(vector <bool> &visited, vector <int> graph[], int visit);

int main() {
	int nodes, edges, starter, v1, v2;
	
	scanf("%d%d%d", &nodes, &edges, &starter);
	vector <bool> visited(nodes+1, false);
	vector <int> graph[nodes+1];
	
	for(int i=0; i<edges; i++) {
		scanf("%d%d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for(int i=1; i<=nodes; i++)
		sort(graph[i].begin(), graph[i].end());
	DFS(visited, graph, starter);
	printf("\n");
	visited = vector<bool>(nodes+1, false);
	BFS(visited, graph, starter);
	printf("\n");
	return 0;
}

void DFS(vector <bool> &visited, vector <int> graph[], int visit) {
	if(!visited[visit]) {
		visited[visit] = true;
		printf("%d ", visit);
		for(int i=0; i<graph[visit].size(); i++) {
			if(!visited[graph[visit][i]])
				DFS(visited, graph, graph[visit][i]);
		}
	}
}
void BFS(vector <bool> &visited, vector <int> graph[], int visit) {
	int tar;
	queue <int> q;
	q.push(visit);
	while(!q.empty()) {
		tar = q.front();
		if(visited[tar]) {
			q.pop();
			continue;
		}
		visited[tar] = true;
		printf("%d ", tar);
		for(int i=0; i<graph[tar].size(); i++) {
			if(!visited[graph[tar][i]])
				q.push(graph[tar][i]);
		}
		q.pop();
	}
}
