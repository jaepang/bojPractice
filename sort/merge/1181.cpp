#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LEN 52
#define MAX_LEN 20000

char sorted[MAX_LEN][MAX_STR_LEN];
int compare(char* a, char* b);
int str_len(char* str);
void merge(char** arr, int left, int mid, int right);
void str_merge_sort(char** arr, int left, int right);

int main() {
	int n;
	char** str_arr;
	
	scanf("%d", &n);
	str_arr = (char**)malloc(n*sizeof(char*));
	for(int i=0; i<n; i++)
		str_arr[i] = (char*)malloc(52*sizeof(char));
	
	for(int i=0; i<n; i++) {
		scanf("%s", str_arr[i]);
	}
	
	str_merge_sort(str_arr, 0, n-1);
	
	printf("%s\n", str_arr[0]);
	for(int i=1; i<n; i++) {
		if(strcmp(str_arr[i], str_arr[i-1]))
			printf("%s\n", str_arr[i]);
	}
	
	for(int i=0; i<n; i++)
		free(str_arr[i]);
	free(str_arr);
	return 0;
}

void str_merge_sort(char** arr, int left, int right) {
	if(left<right) {
		int mid = (left+right) / 2;
		str_merge_sort(arr, left, mid);
		str_merge_sort(arr, mid+1, right);
		merge(arr, left, mid, right);
	}
}

void merge(char** arr, int left, int mid, int right) {
	int i=left;
	int j=mid+1;
	int idx = left;
	
	while(i<=mid && j<=right) {
		if(compare(arr[i], arr[j]) < 0)
			strcpy(sorted[idx++], arr[i++]);
		else
			strcpy(sorted[idx++], arr[j++]);
	}
	while(i<=mid)
		strcpy(sorted[idx++], arr[i++]);
	while(j<=right)
		strcpy(sorted[idx++], arr[j++]);
	
	for(i=left; i<=right; i++)
		strcpy(arr[i], sorted[i]);
}

int str_len(char* str) {
	char c = str[0];
	int len=0;
	while(c != '\0') {
		len++;
		c = str[len];
	}
	return len;
}

int compare(char* a, char* b) {
	int len_a, len_b;
	len_a = str_len(a);
	len_b = str_len(b);
	
	if(len_b < len_a)
		return 1;
	else if(len_a < len_b)
		return -1;
	else 
		return strcmp(a, b);
}
