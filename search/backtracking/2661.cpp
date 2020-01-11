/*
 * 2661. 좋은 수열
 * 
 * 숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면, 그 수열을 나쁜 수열이라고 부른다. 그렇지 않은 수열은 좋은 수열이다.
 * 다음은 나쁜 수열의 예이다.
 *  33
 *  32121323
 *  123123213
 *
 * 다음은 좋은 수열의 예이다.
 *  2
 *  32
 *  32123
 *  1232123
 *
 * 길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램을 작성하라. 
 * 예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수열은 1213121이다.
 *
 * 입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다.
 *
 * 첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내는 수열만 출력한다. 수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다.
 *
 */
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

bool isGood(vector <int> arr, int pos, vector <pair<int, bool>> checker);

int main() {
	int n, i=0;
	bool goBack;
	scanf("%d", &n);
	vector <int> ans(n, 1);
	vector <pair<int, bool>> checker(n, make_pair(1, true));
	while(i<n) {
		goBack = false;
		while(!isGood(ans, i, checker)) {
			ans[i]++;
	
			if(ans[i] == 4) {
				goBack = true;
				ans[i] = 1;
				checker[i-1].first = ans[i-1];
				checker[i-1].second = false;
				ans[i-1] = 1;
				break;
			}
		}
		if(goBack)
			i--;
		else
			i++;
	}
	for(int i=0; i<n; i++)
		printf("%d", ans[i]);
	printf("\n");
}
bool isGood(vector <int> arr, int pos, vector <pair<int, bool>> checker) {
	int checkPos = pos;
	int dist, len, former, latter;
	bool isSame;
	if(checker[pos].first == arr[pos] && !checker[pos].second)
		return false;
	len = pos%2==0 ? pos:pos+1;
	for(int i=1; i<=len/2; i++) { // subArr length
		isSame = true;
		latter = pos-i+1;
		former = latter-i;
		for(int j=0; j<i; j++) {
			if(arr[former] != arr[latter]) {
				isSame = false;
				break;
			}
			former++;
			latter++;
		}
		if(isSame)
			return false;
	}
	return true;
}
