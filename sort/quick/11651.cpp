#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate {
	int x;
	int y;
}coor;
bool a_bigger_than_b(coor a, coor b);
void swap(coor *a, coor *b);
void quickSort(coor *arr, int low, int high);
int partition(coor *arr, int left, int right);

int main() {
	coor *arr;
	int n, x, y;
	
	scanf("%d", &n);
	arr = (coor *)malloc(n*sizeof(coor));
	
	for(int i=0; i<n; i++) {
		scanf("%d%d", &x, &y);
		arr[i].x = x;
		arr[i].y = y;
	}
	
	quickSort(arr, 0, n-1);
	
	for(int i=0; i<n; i++) {
		printf("%d %d\n", (arr+i)->x, (arr+i)->y);
	}
	return 0;
}

bool a_bigger_than_b(coor a, coor b) {
	return a.y!=b.y ? a.y>b.y : a.x>b.x;
}
void swap(coor *a, coor *b) {
	coor tmp = *a;
	*a = *b;
	*b = tmp;
}

void quickSort(coor *arr, int low, int high) {
	if(low<high) {
		int pivot = partition(arr, low, high);
		quickSort(arr, low, pivot-1);
		quickSort(arr, pivot+1, high);
	}
}
int partition(coor *arr, int left, int right) {
	coor pivot = arr[left];
	int low = left+1;
	int high = right;
	//printf("pivot: (%d,%d)\n", pivot.x, pivot.y);
	while(low<=high) {
		while(a_bigger_than_b(pivot, arr[low]) && low<=right)
			low++;
		while(a_bigger_than_b(arr[high], pivot) && high>=left)
			high--;
		if(low<high)
			swap(arr+low, arr+high);
	}
	swap(arr+left, arr+high);
	return high;
}
