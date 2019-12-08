#include <stdio.h>
// this code also works on 11719

int main() {
	char input[102];
	while(fgets(input, 102, stdin)) {
		printf("%s", input);
	}
	return 0;
}