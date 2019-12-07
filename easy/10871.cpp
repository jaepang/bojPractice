#include <stdio.h>

int main() {
	int n, x;
	int* arr;
	scanf("%d%d", &n, &x);
	arr = (int *)malloc(n * sizeof(int));
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	//for(int i=0; i<n; i++) {
	//	if(arr[i] < x) {
		//	printf("%d ", arr[i]);
		//}
	//}
	//printf("\n");
	return 0;
}