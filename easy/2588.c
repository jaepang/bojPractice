#include <stdio.h>

int main(int argc, char* argv[]) {
	int a, b, i, j, tmp, cnt, result;
	result = 0;
	scanf("%d%d", &a, &b);
	for(i=0; i<3; i++) {
		cnt = 1;
		tmp = b;
		for(j=0; j<i; j++) {
			cnt *= 10;
			tmp /= 10;
		}
		tmp %= 10;
		tmp *= a;
		printf("%d\n", tmp);
		result += tmp * cnt;
	}
	printf("%d\n", result);
	return 0;
}