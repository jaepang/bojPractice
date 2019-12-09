#include <stdio.h>
#include <string>
using namespace std;

int main() {
	char tmp[1000002];
	string str;
	int idx=0, cnt=0;
	fgets(tmp, 1000000, stdin);
	str = tmp;
	
	while(idx < str.length()) {
		if(str[idx] != ' ' && str[idx] != '\n') {
			cnt++;
			idx++;
			while(idx < str.length() && str[idx] != ' ' && str[idx] != '\n')
				idx++;
		}
		else
			idx++;
	}
	printf("%d\n", cnt);
	return 0;
}
