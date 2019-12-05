#include <stdio.h>

int main() {
	int arr[3];
	int tmp;
	scanf("%d%d%d", arr, arr+1, arr+2);
	if(arr[0] < arr[1]) {
		tmp = arr[0];
		arr[0] = arr[1];
		arr[1] = tmp;
	}
	if(arr[1] < arr[2]) {
		tmp = arr[1];
		arr[1] = arr[2];
		arr[2] = tmp;
	}
	if(arr[0] < arr[1]) {
		tmp = arr[0];
		arr[0] = arr[1];
		arr[1] = tmp;
	}
	printf("%d\n", arr[1]);
}