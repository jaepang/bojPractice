#include <stdio.h>
// star8

int main() {
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n-1; i++) {
		for(int j=0; j<i; j++)
			printf("*");
		for(int j=0; j< 2*(n-i); j++)
			printf(" ");
		for(int j=0; j<i; j++)
			printf("*");
		printf("\n");
	}
	for(int i=0; i<2*n; i++) {
		printf("*");
	}
	printf("\n");
	for(int i=n-1; i>=1; i--) {
		for(int j=0; j<i; j++)
			printf("*");
		for(int j=0; j< 2*(n-i); j++)
			printf(" ");
		for(int j=0; j<i; j++)
			printf("*");
		printf("\n");
	}
}