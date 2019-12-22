#include <stdio.h>
#include <stdlib.h>
#include <hash_map>
using namespace __gnu_cxx;

int main() {
	int n, val;
	int *arr;
	hash_map <int,int> hMap;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &val);
		if(hMap.find(val) != hMap.end()) {
			hMap[val]++;
		}
		else {
			hMap[val] = 1;
		}
	}
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++) {
		scanf("%d", &val);
		if(hMap.find(val) != hMap.end()) {
			arr[i] = hMap[val];
		}
		else 
			arr[i] = 0;
	}
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
