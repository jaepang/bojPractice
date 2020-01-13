/*
 * 2580. 스도쿠
 * 스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 
 * 이 게임은 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 몇 몇 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.
 *
 * 나머지 빈 칸을 채우는 방식은 다음과 같다.
 *  1. 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
 *  2. 굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
 *
 * 게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.
 *
 * 아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 
 * 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.
 *
 * 모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.
 * 스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.
 *
 */
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

int map[9][9];
int blanks;
bool flag = true;
vector <pair<int, int>> blank;
void backtrack(int idx);
bool canPos(int idx);
void print();


int main() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0) {
				blank.push_back(make_pair(i, j));
				blanks++;
			}
		}
	}
	
	//printf("\nblank(%d): ", blanks);
	//for(int i=0; i<blanks; i++)
	//	printf("%d,%d ", blank[i].first, blank[i].second);
	//printf("\n");
	
	backtrack(0);
}
void print() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++)
			printf("%d ", map[i][j]);
		printf("\n");
	}
}
bool canPos(int idx) {
	int r = blank[idx].first;
	int c = blank[idx].second;
	pair <int, int> leftCorner = make_pair((r/3)*3, (c/3)*3);
	//printf("== idx:%d r:%d c:%d lc:(%d,%d) try:%d ==\n", idx, r, c, leftCorner.first, leftCorner.second, map[r][c]);
	
	for(int i=0; i<9; i++) {
		if(i == r)
			continue;
		if(map[i][c] == map[r][c])
			return false;
	}
	for(int i=0; i<9; i++) {
		if(i == c)
			continue;
		if(map[r][i] == map[r][c])
			return false;
	}
	for(int i=leftCorner.first; i<leftCorner.first+3; i++) {
		for(int j=leftCorner.second; j<leftCorner.second+3; j++) {
			if(i==r && j==c)
				continue;
			if(map[i][j] == map[r][c])
				return false;
		}
	}
	return true;
}
void backtrack(int idx) {
	if(idx >= blanks) {
		//printf("END\n");
		print(); // 이 시점에서 출력을 안하면 0으로 되돌아감
		//flag = false;
		return;
	}
	for(int i=1; i<=9 && flag; i++) {
		map[blank[idx].first][blank[idx].second] = i;
		if(canPos(idx))
			backtrack(idx+1);
		map[blank[idx].first][blank[idx].second] = 0;
	}
}
