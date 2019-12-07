#include <stdio.h>
#include <set>
#include <iostream>
#include <string>
using namespace std;
set <string> s;
set <string>::reverse_iterator iter;

int main() {
	int n;
	string name, cmd;
	char tmpn[6], tmpcmd[6];
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s%s", tmpn, tmpcmd);
		name = tmpn;
		cmd = tmpcmd;
		if(cmd.compare("enter") == 0) {
			s.insert(name);
		}
		else {
			s.erase(name);
		}
	}
	for(iter=s.rbegin(); iter != s.rend(); iter++) {
		cout << *iter << "\n";
	}
}
