/*
 * 1929. 소수 구하기
 * M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1 ≤ M ≤ N ≤ 1,000,000)
 *
 * 한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
 *
 */
#include <stdio.h>
#include <math.h>

bool isPrimeNum(int tar);

int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	for(int i=m; i<=n; i++) {
		if(isPrimeNum(i))
			printf("%d\n", i);
	}
	return 0;
}

bool isPrimeNum(int tar) {
	if(tar == 1)
		return false;
	for(int i=2; i<=sqrt(tar); i++) {
		if(tar % i == 0)
			return false;
	}
	return true;
}
