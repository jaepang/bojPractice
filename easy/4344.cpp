#include <stdio.h>

int main() {
	int n, p, over;
	float avg;
	int score[1001];
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		avg=0;
		over=0;
		scanf("%d", &p);
		for(int j=0; j<p; j++){
			scanf("%d", score+j);
			avg+=score[j];
		}
		avg /= p;
		for(int j=0; j<p; j++){
			if(avg < score[j])
				over++;
		}
		printf("%.3lf%\n", (double)over/(double)p * 100);
	}
	return 0;
}
