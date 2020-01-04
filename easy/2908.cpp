#include <stdio.h>

int reverse(int a) {
	int pos[3];
	for(int i=0; i<3; i++) {
		pos[i] = a%10;
		a/=10;
	}
	return pos[0]*100 + pos[1]*10 + pos[2];
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	a = reverse(a);
	b = reverse(b);
	printf("%d\n", a>b ? a:b);
	return 0;
}
