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
#include <math.h>
int n;
int result=0;
int map[14]; // idx: col val: depth
bool canPos(int col);
void backtrack(int col);

int main() {
	scanf("%d", &n);
	backtrack(0);
	printf("%d\n", result);
	return 0;
}

bool canPos(int col) {
	for(int i=0; i<col; i++) {
		if(map[col]==map[i] || abs(map[col]-map[i]) == col-i)
			return false;
	}
	return true;
}
void backtrack(int col) {
	if(col == n) {
		result++;
		return;
	}
	for(int i=0; i<n; i++) {
		map[col] = i;
		if(canPos(col))
			backtrack(col+1);
	}
}
