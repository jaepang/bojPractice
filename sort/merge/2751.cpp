#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

int sorted[MAX];
int n;
void merge(int* arr, int left, int mid, int right) {
	int idx = left;
	int i = left;
	int j = mid+1;
	
	while(i <= mid && j <= right) {
		if(arr[i] < arr[j])
			sorted[idx++] = arr[i++];
		else
			sorted[idx++] = arr[j++];
	}
	
	while(i <= mid)
		sorted[idx++] = arr[i++];	
	while(j <= right)
		sorted[idx++] = arr[j++];
		
	for(int i=left; i<=right; i++) {
		arr[i] = sorted[i];
	}
}
void mergeSort(int* arr, int left, int right) {
	if(left < right) {
		int mid = (left+right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

int main() {
	int *arr;
	scanf("%d", &n);
	
	arr = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	
	mergeSort(arr, 0, n-1);
	for(int i=0; i<n; i++) {
		printf("%d\n", arr[i]);
	}
	
	return 0;
}
