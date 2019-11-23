#include <stdio.h>

int main() {
	int year, flag;
	scanf("%d", &year);
	flag = (year%4==0 && year%100!=0) || year%400==0;
	printf("%d\n", flag);
	return 0;
}