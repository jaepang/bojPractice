#include <stdio.h>
#include <stdlib.h>

int n;
int tmp;
void swap(int* a, int* b);
void qSort(int* arr, int left, int right);
int partition(int* arr, int left, int right);

int main() {
	int *arr;
	scanf("%d", &n);
	
	arr = (int *)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	
	qSort(arr, 0, n-1);
	for(int i=0; i<n; i++) {
		printf("%d\n", arr[i]);
	}
	
	return 0;
}

void swap(int* a, int* b) {
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void qSort(int* arr, int left, int right) {
	int pivot;
	if(left<right) {
		pivot = partition(arr, left, right);
		//printf("%d AT %d\n", arr[pivot], pivot);
		qSort(arr, left, pivot-1);
		qSort(arr, pivot+1, right);
	}
}
int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int low = left+1;
	int high = right;
	while(low <= high) {
		while(arr[low] < pivot)
			low++;
		while(arr[high] > pivot)
			high--;
		if(low < high)
			swap(arr+low, arr+high);
	}
	swap(arr+left, arr+high);
	
	return high;
}
