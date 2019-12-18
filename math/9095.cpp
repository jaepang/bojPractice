#include <stdio.h>

int main() {
	int n, input, arr[11] = {0,}; // 1 ~ 10
	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for(int i=4; i<=10; i++) {
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
	}
	for(int i=0; i<n; i++) {
		scanf("%d", &input);
		printf("%d\n", arr[input]);
	}
	return 0;
}
