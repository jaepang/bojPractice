#include <stdio.h>

int main() {
	int result=0;
	int score;
	for(int i=0; i<5; i++) {
		scanf("%d", &score);
		if(score < 40)
			score = 40;
		result += score;
	}
	printf("%d\n", result/5);
}