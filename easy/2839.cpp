#include <stdio.h>

// *3 *6 *9 *12 15 18 21 24 27 30 33 36 39 42

int main() {
	int n, thr=0, fiv=0, result;
	bool flag=true;
	scanf("%d", &n);
	while(n>0) {
		if(n==1 || n==2 || n==4) {
			flag = false;
			break;
		}
		if(n%3==0 && n<=12) { // 끝
			thr += n/3;
			break;
		}
		fiv += 1;
		n -= 5;
	}
	if(flag)
		result = thr+fiv;
	else
		result = -1;
	printf("%d\n", result);
	return 0;
}