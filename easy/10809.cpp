#include <stdio.h>

int len(char* str);
void calc_word(char* str);

int main() {
	char word[102];
	scanf("%s", word);
	calc_word(word);	
	return 0;
}

int len(char* str) {
	int len=0;
	char c = str[len];
	while(c != '\0') {
		len++;
		c = str[len];
	}
	return len;
}

void calc_word(char* str) {
	int alphabet[26];
	for(int i=0; i<26; i++)
		alphabet[i] = -1;
	for(int i=0; i<len(str); i++) {
		if(alphabet[str[i]-'a'] == -1)
			alphabet[str[i]-'a'] = i;
	}
	for(int i=0; i<26; i++)
		printf("%d ", alphabet[i]);
	printf("\n");
}
