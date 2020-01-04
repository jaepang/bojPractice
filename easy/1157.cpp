#include <stdio.h>
#include <string.h>

int getMax(int *arr) {
	int max=0, maxVal=arr[0];
	int cnt=0;
	for(int i=0; i<26; i++) {
		if(maxVal < arr[i]) {
			max = i;
			maxVal = arr[i];
		}
		// printf("%c: %d // max: %c/%d\n", i+'A', arr[i], max+'A', maxVal);
	}
	for(int i=0; i<26; i++) {
		if(arr[i]==maxVal)
			cnt++;
		if(cnt>1)
			break;
	}
	if(cnt>1)
		return -1;
	return max;
}

int main() {
	int alphabet[26] = {0,};
	int size, result;
	char str[1000001];
	scanf("%s", str);
	size = strlen(str);
	for(int i=0; i<size; i++) {
		if('a'<=str[i] && str[i]<='z')
			str[i] -= 32;
		alphabet[str[i]-'A']++;
	}
	result = getMax(alphabet);
	if(result == -1)
		printf("?\n");
	else
		printf("%c\n", result+'A');
	return 0;
}
