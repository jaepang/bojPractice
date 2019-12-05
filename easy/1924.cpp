#include <stdio.h>
#include <string>
using namespace std;
// 1, 3, 5, 7, 8, 10, 12 : 31
// 4, 6, 9, 11	 		 : 30
// 2			 		 : 28
// 31 28 31 30 31 30 31 31 30 31 30 31
// 1.1: MON
string days[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int mDays[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	int m, d, idx, diff=0;
	scanf("%d%d", &m, &d);
	for(int i=m-1; i>0; i--) {
		diff += mDays[i];
		// printf("i: %d   diff: %d\n", i, diff);
	}
	diff += d;
	diff -= 1;
	// printf("diff: %d\n", diff);
	printf("%s\n", days[diff%7].c_str());
}
