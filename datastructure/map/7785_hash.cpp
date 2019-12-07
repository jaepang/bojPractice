#include <stdio.h>
#include <string>
#include <functional>
#include <algorithm>
#define MAX_VAL 1000000
using namespace std;

/**
  * BST solution made runtime error
  * because of worst case of BST
  * this time, we'll implement hashmap
 **/

class node {
	private:
		string name;
		node* next;
	public:
		node();
		node(string name);
		string getName();
		node* getNext();
		void setName(string n);
		void setNext(node* n);
};
class hashmap {
	private:
		node *nodes[MAX_VAL];
	public:
		hashmap();
		node** getNodes();
		int hash(string n);
		void add(string n);
		void remove(string n);
		void print();
};

int main() {
	hashmap* map = new hashmap();
	int n;
	string name, cmd;
	char tmpn[6], tmpcmd[6];
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s%s", tmpn, tmpcmd);
		name = tmpn;
		cmd = tmpcmd;
		if(cmd.compare("enter") == 0) {
			map->add(name);
		}
		else {
			map->remove(name);
		}
	}
	map->print();
}

node::node(){}
node::node(string n) {
	this->name = n;
	this->next = NULL;
}
string node::getName() {
	return this->name;
}
node* node::getNext() {
	return this->next;
}
void node::setName(string n) {
	this->name = n;
}
void node::setNext(node* n) {
	this->next = n;
}

hashmap::hashmap() {
	for(int i=0; i<MAX_VAL; i++) {
		this->nodes[i] = NULL;
	}
}
int hashmap::hash(string n) {
	const char *cstr = n.c_str();
	int hash = 401; // 임의 값, 소수일 때 충돌이 덜 난다고 함 why?
	
	while(*cstr != '\0') {
		hash = ((hash << 4) + (int) *cstr) % MAX_VAL; // shift 연산도 충돌을 방지한다 함 why?
		cstr++;
	}
	return hash;
}
void hashmap::add(string n){
	int idx = this->hash(n);
	if(!this->nodes[idx]) {
		nodes[idx] = new node(n);
	}
	else {
		node *cur = this->nodes[idx];
		while(cur->getNext() != NULL) {
			cur = cur->getNext();
		}
		cur->setNext(new node(n));
	}
}
void hashmap::remove(string n) {
	int idx = this->hash(n);
	node *cur = this->nodes[idx];
	if(cur->getName().compare(n) == 0) {
		this->nodes[idx] = NULL;
		return;
	}
	while(cur->getNext() != NULL && cur->getNext()->getName().compare(n) != 0) {
		cur = cur->getNext();
	}
	if(cur->getNext()){
		cur->getNext()->setNext(cur->getNext()->getNext());
	}
}
void hashmap::print() {
	node* n;
	string list[MAX_VAL];
	int idx = 0;
	
	for(int i=0; i<MAX_VAL; i++) {
		if(this->nodes[i] != NULL) {
			n = this->nodes[i];
			while(n) {
				list[idx++] = n->getName();
				n = n->getNext();
			}
		}
	}
	sort(list, list+idx, greater<string>());
	for(int i=0; i<idx; i++) {
		printf("%s\n", list[i].c_str());
	}
}
