#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 1000000

int sorted[MAX_LEN];
void merge(int* arr, int left, int mid, int right);
void merge_sort(int* arr, int left, int right);

int main() {
	int n;
	int* arr;
	
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	merge_sort(arr, 0, n-1);
	
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

void merge_sort(int* arr, int left, int right) {
	if(left<right) {
		int mid = (left+right) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

void merge(int* arr, int left, int mid, int right) {
	int i=left;
	int j=mid+1;
	int idx = left;
	
	while(i<=mid && j<=right) {
		if(arr[i] < arr[j])
			sorted[idx++] = arr[i++];
		else
			sorted[idx++] = arr[j++];
	}
	while(i<=mid)
		sorted[idx++] = arr[i++];
	while(j<=right)
		sorted[idx++] = arr[j++];
	
	for(i=left; i<=right; i++)
		arr[i] = sorted[i];
}
