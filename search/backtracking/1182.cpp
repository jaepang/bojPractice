/*
 * 1182. 부분수열의 합
 *
 * N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 
 * 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 
 * 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.
 *
 * 첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
 *
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n, rqSum, ans;
vector <int> set;
vector <int *> subset;
int getCurIdx(int *cur);
int getSum(int subsetSize);
bool canPos(int depth, int *cur, int subsetSize);
void backtrack(int depth, int subsetSize);

int main() {
	int inpt;
	scanf("%d%d", &n, &rqSum);
	for(int i=0; i<n; i++) {
		scanf("%d", &inpt);
		set.push_back(inpt);
	}
	subset = vector<int *>(n);
	sort(set.begin(), set.end());
	
	for(int i=1; i<=n; i++)
		backtrack(0, i);
	printf("%d\n", ans);
	return 0;
}

int getCurIdx(int *cur) {
	int idx = 0;
	int *tar = &set[idx];
	while(cur != tar) {
		idx++;
		tar = &set[idx];
	}
	return idx+1;
}
int getSum(int subsetSize) {
	int sum = 0;
	for(int i=0; i<subsetSize; i++)
		sum += *subset[i];
	return sum;
}
bool canPos(int depth, int *cur, int subsetSize) {
	int idx = getCurIdx(cur);
	int sum;
	if(depth != subsetSize-1)
		return n-idx >= subsetSize-depth-1;
	else {
		sum = getSum(subsetSize-1);
		//printf("TEST FINAL - %d to %d\n", *cur, sum);
		return sum+*cur == rqSum;
	}
}
void backtrack(int depth, int subsetSize) {
	int idx=0;
	//for(int i=0; i<subsetSize; i++) {
	//	printf("%d ", *subset[i]);
	//}
	if(depth > 0)
		idx = getCurIdx(subset[depth-1]);
	//printf("- subset, idx: %d\n", idx);
	if(depth == subsetSize) {
		if(getSum(subsetSize) == rqSum)
			ans++;
		subset.resize(n, 0);
		return;
	}
	for(int i=idx; i<n; i++) {
		subset[depth] = &set[i];
		if(canPos(depth, &set[i], subsetSize)) {
			//printf("ADD %d\n", set[i]);
			backtrack(depth+1, subsetSize);
		}
		else
			subset[depth] = 0;
	}
}
