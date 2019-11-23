#include <stdio.h>

int main() {
	int cows[505] = {0,};
	int numOfCows, cmds;
	int cmd[3];
	int cnt;
	scanf("%d%d ", &numOfCows, &cmds);
	for(int i=0; i<cmds; i++) {
		scanf("%d%d%d", cmd, cmd+1, cmd+2);
		// toggle switch between cmd[1] and [2]
		if(!cmd[0]) {
			for(int i=cmd[1]; i<=cmd[2]; i++) {
				cows[i] = !cows[i];
			}
		}
		// count & print light turned on
		else {
			cnt = 0;
			for(int i=cmd[1]; i<=cmd[2]; i++) {
				cnt = cows[i] ? cnt+1:cnt;
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}