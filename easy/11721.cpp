#include <stdio.h>

int strlength(char* str) {
	char c=str[0];
	int len=0;
	while(c != '\0') {
		c = str[len++];
	}
	return len-1;
}

int main() {
	char str[102];
	char tmp[12];
	int len, idx;
	scanf("%s", str);
	len = strlength(str);
	
	idx = 0;
	while(len > 0) {
		if(len < 10) {
			for(int i=0; i<len; i++)
				tmp[i] = str[idx+i];
			tmp[len] = '\0';
			idx += len;
		}
		else {
			for(int i=0; i<10; i++)
				tmp[i] = str[idx+i];
			tmp[10] = '\0';
			idx += 10;
		}
		printf("%s\n", tmp);
		len -= 10;
	}
	return 0;
}
