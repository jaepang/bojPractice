#include <stdio.h>
#include <map>
#include <string>
using namespace std;
map<int, string> intKeyMap;
map<string, int> stringKeyMap;

int isQNum(string str) {
	return '0' <= str[0] && str[0] <= '9';
}
int strToInt(string str) {
	int i=0, result=0;
	while(str[i] != '\0') {
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return result;
}

int main() {
	//  1 <= N, M <= 100000
	int numMonster, numQuestion, q;
	string poketmon, question;
	char tmp[20];
 	scanf("%d%d", &numMonster, &numQuestion);
	for(int i=1; i<=numMonster; i++) {
		scanf("%s", tmp);
		poketmon = tmp;
		intKeyMap[i] = poketmon;
		stringKeyMap[poketmon] = i;
	}
	
	for(int i=0; i<numQuestion; i++) {
		scanf("%s", tmp);
		question = tmp;
		if(isQNum(question)) {
			q = strToInt(question);
			printf("%s\n", intKeyMap[q].c_str());
		}
		else {
			printf("%d\n", stringKeyMap[question]);
		}
	}
	return 0;
}