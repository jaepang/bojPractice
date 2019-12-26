#include <stdio.h>
#include <string.h>

int main() {
	int n, score, tmp, len, j;
	char result[81];
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		score = 0;
		scanf("%s", result);
		len = strlen(result);
		j = 0;
		while(j<len) {
			if(result[j] == 'O') {
				tmp = 1;
				score += tmp;
				j++;
				while(result[j] == 'O') {
					tmp++;
					score += tmp;
					j++;
				}
			}
			else
				j++;
		}
		printf("%d\n", score);
	}
}
