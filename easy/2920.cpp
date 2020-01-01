#include <stdio.h>

int main() {
	int notes[8];
	bool ascending = true, mixed = false, tmp;
	for(int i=0; i<8; i++)
		scanf("%d", notes+i);
	tmp = notes[0] < notes[1];
	for(int i=2; i<8; i++) {
		ascending = notes[i] > notes[i-1];
		if((tmp || ascending) && !(tmp && ascending)) {
			mixed = true;
			break;
		}
		tmp = ascending;
	}
	if(mixed)
		printf("mixed\n");
	else {
		if(ascending)
			printf("ascending\n");
		else
			printf("descending\n");
	}
	return 0;
}
