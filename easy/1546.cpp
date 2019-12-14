#include <stdio.h>
#include <stdlib.h>

float max(float* arr, int size) {
	float max_val = arr[0];
	for(int i=1; i<size; i++) {
		if(max_val < arr[i])
			max_val = arr[i];
	}
	return max_val;
}

int main() {
	int n;
	float* score;
	float max_score;
	double avg=0;
	scanf("%d", &n);
	score = (float*)malloc(n*sizeof(float));
	
	for(int i=0; i<n; i++)
		scanf("%f", score+i);
	
	max_score = max(score, n);
	for(int i=0; i<n; i++) {
		score[i] = score[i] / max_score * 100;
		avg += score[i];
	}
	avg /= n;
	printf("%lf\n", avg);
	
	return 0;
}
