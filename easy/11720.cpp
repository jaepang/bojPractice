#include <stdio.h>
#include <stdlib.h>

int adder(int* arr, int size) {
	int sum=0;
	for(int i=0; i<size; i++)
		sum+=arr[i];
	return sum;
}

int main() {
	char* str;
	int* arr;
	int n;
	
	scanf("%d", &n);
	str = (char*)malloc(n*sizeof(char) + 2);
	arr = (int*)malloc(n*sizeof(int));
	
	scanf("%s", str);
	for(int i=0; i<n; i++)
		arr[i] = str[i] - '0';
	printf("%d\n", adder(arr, n));
	return 0;
}
