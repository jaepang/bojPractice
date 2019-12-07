#include <stdio.h>

int main() {
	char input[102];
	while(fgets(input, 102, stdin)) {
		printf("%s", input);
	}
	return 0;
}