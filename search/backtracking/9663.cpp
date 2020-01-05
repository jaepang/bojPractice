/*
 * 9663.N-Queen
 *
 * N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
 * N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 N이 주어진다. (1 ≤ N < 15)
 *
 */
#include <stdio.h>
#include <vector>
using namespace std;

int result=0;
int n;
vector <int> chess[14];
void setQueen(int row, int col);
void restore(vector <int> chess[]);
void copychess(vector <int> src[], vector <int> dest[]);
void printchess(vector <int> chess[]);
bool BackTrack(int row, int col);

int main() {
	scanf("%d", &n);
	restore(chess);
	
	for(int i=0; i<n; i++) {
		BackTrack(0, i);
		restore(chess);
	}
	printf("%d\n", result);
	return 0;
}

void setQueen(int row, int col) {
	for(int i=0; i<n; i++) {
		chess[i][col] = 1;
		chess[row][i] = 1;
		if(0<=i+row-col && i+row-col<n)
			chess[i+row-col][i] = 1;
		if(0<=row+col-i && row+col-i<n)
			chess[i][row+col-i] = 1;
	}
}
void restore(vector <int> chess[]) {
	for(int i=0; i<n; i++)
		chess[i] = vector <int> (n, 0);
}
void printchess(vector <int> chess[]) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			printf("%d ", chess[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void copychess(vector <int> src[], vector <int> dest[]) {
	restore(dest);
	for(int i=0; i<n; i++) {
		copy(src[i].begin(), src[i].end(), dest[i].begin());
	}
}
bool BackTrack(int row, int col) {
	vector <int> bakChess[14];
	bool flag=false;
	if(chess[row][col] == 1)
		return false;
	else {
		if(row == n-1) {
			result++;
			return true;
		}
		setQueen(row, col);
		copychess(chess, bakChess);
		
		for(int i=0; i<n; i++) {
			copychess(bakChess, chess);
			if(chess[row+1][i] == 0)
				flag = BackTrack(row+1, i);
		}
		return flag;
	}
}
