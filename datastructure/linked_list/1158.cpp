#include <stdio.h>
#include <stdlib.h>

// circular linked-list!
class node {
	private:
		int key;
		node *next;
		node *prev;
	public:
		friend class list;
		node();
		node(int);
		node *getNext();
};
class list {
	private:
		node *head;
		int size;
	public:
		list();
		node *getHead();
		void add(node*);
		int remove(node*);
		void revise();
		void print();
};

int main() {
	int n, k;
	int *arr;
	list l;
	node *cur;
	scanf("%d%d", &n, &k);
	arr = (int *)malloc(n*sizeof(int));
	
	for(int i=1; i<=n; i++)
		l.add(new node(i));
	l.revise();
	// l.print();
	for(int i=0; i<n; i++) {
		cur = l.getHead();
		for(int j=0; j<k; j++)
			cur = cur->getNext();
		arr[i] = l.remove(cur);
		// l.print();
	}
	printf("<");
	for(int i=0; i<n-1; i++)
		printf("%d, ", arr[i]);
	printf("%d>\n", arr[n-1]);
	return 0;
}

node::node(){}
node::node(int k) {
	this->key = k;
	this->next = nullptr;
	this->prev = nullptr;
}
node* node::getNext() {
	return this->next;
}

list::list(){
	this->head = nullptr;
	this->size = 0;
}
node* list::getHead() {
	return this->head;
}
int list::remove(node *n) {
	if(this->size > 1) {
		n->prev->next = n->next;
		n->next->prev = n->prev;
		this->head = n->prev;
	}
	this->size--;
	return n->key;
}
void list::add(node *n) {
	if(this->head) {
		n->next = this->head;
		n->prev = this->head->prev;
		this->head->prev->next = n;
		this->head->prev = n;
	}
	else {
		this->head = n;
		n->next = n;
		n->prev = n;
	}
	this->size++;
}
void list::revise() {
	this->head = this->head->prev;
}
void list::print() {
	node *cur = this->head;
	printf("%d ", cur->key);
	cur = cur->next;
	while(cur != this->head) {
		printf("%d ", cur->key);
		cur = cur->next;
	}
	printf("\n");
}
