#include <stdio.h>
// 문제의 자연수 범위가 작으므로(<=10000), counting sort로 메모리를 절약한다.
int main() {
	int n, input;
	int counter[10001]={0,}; // 1~10000
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &input);
		counter[input]++;
	}
	for(int i=1; i<=10000; i++) {
		for(int j=0; j<counter[i]; j++)
			printf("%d\n", i);
	}
	return 0;
}
