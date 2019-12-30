#include <stdio.h>

void readNCalc(char str[]);

int main() {
	int n;
	char str[5];
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s", str);
		readNCalc(str);
	}
	return 0;
}

void readNCalc(char str[]) {
	int a = str[0] - '0';
	int b = str[2] - '0';
	printf("%d\n", a+b);
}
