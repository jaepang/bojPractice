/*
 * 1978. 소수 찾기
 * 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.
 *
 * 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.
 *
 * 주어진 수들 중 소수의 개수를 출력한다.
 *
 */
#include <stdio.h>
#include <math.h>

bool isPrimeNum(int tar);

int main() {
	int n, tar, cnt=0;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%d", &tar);
		if(isPrimeNum(tar))
			cnt++;
	}
	
	printf("%d\n", cnt);
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
