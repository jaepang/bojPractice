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
	printf("%d ", arr[0]);
	for(int i=1; i<n; i++) {
		if(arr[i] != arr[i-1])
			printf("%d ", arr[i]);
	}
	printf("\n");
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
		qSort(arr, left, pivot-1);
		qSort(arr, pivot+1, right);
	}
}
int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int low = left+1;
	int high = right;
	while(low <= high) {
		// =을 둘 중에 하나는 달아줘야 pivot과 같은 크기가 나왔을때 교착상태에 빠지지 않음
		while(arr[low] <= pivot && low<=right)
			low++;
		while(arr[high] > pivot && high>=left)
			high--;
		if(low < high)
			swap(arr+low, arr+high);
	}
	swap(arr+left, arr+high);
	
	return high;
}
