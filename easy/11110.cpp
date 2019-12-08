#include <stdio.h>

int main() {
	int num, cur, tmp, arr[2], steps=0;
	bool flag;
	scanf("%d", &num);
	
	cur = num;
	while(true) {
		// printf("cur: %d\n", cur);
		if(cur/10 == 0) {
			flag = false;
			arr[0] = cur;
			arr[1] = 0;
		}
		else {
			flag = true;
			arr[0] = cur/10;
			arr[1] = cur%10;
		}
		tmp = arr[0]+arr[1];
		if(flag)
			arr[0] = arr[1];
		arr[1] = tmp%10;
		
		cur = arr[0]*10 + arr[1];
		steps++;
		if(num==cur)
			break;
	}
	printf("%d\n", steps);
	return 0;
}
