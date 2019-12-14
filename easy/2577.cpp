#include <stdio.h>

void calc(int num);

int main() {
	int arr[3];
	int ans;
	scanf("%d%d%d", arr, arr+1, arr+2);
	ans = arr[0]*arr[1]*arr[2];
	//printf("ans: %d\n", ans);
	calc(ans);
	return 0;
}

void calc(int num) {
	int dict[10] = {0,};
	while(num > 0) {
		dict[num%10]++;
		//printf("added: %d\n", num%10);
		num /= 10;
	}
	for(int i=0; i<10; i++) {
		printf("%d\n", dict[i]);
	}
}
