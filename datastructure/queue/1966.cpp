#include <stdio.h>

class node {
	private:
		int key;
		int idx;
		node *next;
	public:
		friend class list;
		node();
		node(int, int);
		node *getNext();
		int *getKey();
		int *getIdx();
};
class list {
	private:
		node *head;
		int size;
	public:
		list();
		node *getHead();
		void add(node*);
		void backward(node*);
		void print();
};

int main() {
	list *l;
	node *cur, *test;
	int n, m, tar, input, cnt;
	bool flag;
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		cnt = 1;
		scanf("%d%d", &m, &tar);
		l = new list();
		for(int j=0; j<m; j++) {
			scanf("%d", &input);
			l->add(new node(input, j));
		}
		cur = l->getHead();
		while(cur != nullptr) {
			if(flag)
				cur = l->getHead();
			test = cur->getNext();
			flag = false;
			while(!flag && test != nullptr) {
				flag = *cur->getKey() < *test->getKey();
				test = test->getNext();
			}
			if(flag) {
				l->backward(cur);
			}
			else
				cur = cur->getNext();
		}
		cur = l->getHead();
		while(cur != nullptr) {
			if(*cur->getIdx() == tar)
				break;
			cur = cur->getNext();
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
node::node(){}
node::node(int k, int i) {
	this->key = k;
	this->idx = i;
	this->next = nullptr;
}
node* node::getNext() {
	return this->next;
}
int* node::getKey() {
	return &this->key;
}
int* node::getIdx() {
	return &this->idx;
}

list::list(){
	this->head = nullptr;
	this->size = 0;
}
node* list::getHead() {
	return this->head;
}
void list::add(node *n) {
	if(this->head) {
		node *cur = this->head;
		while(cur->next != nullptr)
			cur = cur->next;
		cur->next = n;
	}
	else
		this->head = n;
	this->size++;
}
void list::backward(node *tar) {
	node *tail = this->head;
	node *bf_tar = this->head;
	while(tail->next != nullptr)
		tail = tail->next;
	if(tar == this->head)
		this->head = tar->next;
	else {
		while(bf_tar->next != tar)
			bf_tar = bf_tar->next;
		bf_tar->next = tar->next;
	}
	tail->next = tar;
	tar->next = nullptr;
}
void list::print() {
	node *cur = this->head;
	while(cur != nullptr) {
		printf("%d %d, ", cur->key, cur->idx);
		cur = cur->next;
	}
	printf("\n");
}
