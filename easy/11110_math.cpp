#include <stdio.h>

int main() {
	int num, cur, tmp, steps=0;
	scanf("%d", &num);
	
	tmp = num;
	while(true) {
		cur = (tmp%10 * 10) + (tmp/10 + tmp%10)%10;
		steps++;
		
		if(num==cur)
			break;
		tmp = cur;
	}
	printf("%d\n", steps);
}
