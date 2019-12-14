#include <stdio.h>
#include <string>
using namespace std;
// deque: double-ended deque => front, back 모두 삽입, 삭제가 가능
class node {
	private:
		int key;
		node* next;
	public:
		friend class deque;
		node();
		node(int);
};

class deque {
	private:
		int size;
		node* front;
		node* back;
	public:
		deque();
		void push_front(node*);
		void push_back(node*);
		void pop_front();
		void pop_back();
		void empty();
		bool isEmpty();
		void printSize();
		bool printFront();
		bool printBack();
};

int main() {
	deque* deq = new deque();
	int n;
	int push;
	char tmp[15];
	string cmd;
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%s", tmp);
		cmd = tmp;
		if(cmd.compare("push_front") == 0) {
			scanf("%d", &push);
			deq->push_front(new node(push));
		}
		else if(cmd.compare("push_back") == 0) {
			scanf("%d", &push);
			deq->push_back(new node(push));
		}
		else if(cmd.compare("pop_front") == 0)
			deq->pop_front();
		else if(cmd.compare("pop_back") == 0)
			deq->pop_back();
		else if(cmd.compare("size") == 0)
			deq->printSize();
		else if(cmd.compare("empty") == 0)
			deq->empty();
		else if(cmd.compare("front") == 0)
			deq->printFront();
		else if(cmd.compare("back") == 0)
			deq->printBack();
	}
	return 0;
}

node::node(){}
node::node(int k) {
	this->key = k;
	this->next = nullptr;
}

deque::deque() {
	this->size = 0;
	this->front = nullptr;
	this->back = nullptr;
}
void deque::push_front(node* n) {
	if(this->isEmpty())
		this->back = n;
	
	n->next = this->front;
	this->front = n;
	this->size++;
}
void deque::push_back(node* n) {
	if(this->isEmpty())
		this->front = n;
	else
		this->back->next = n;
	this->back = n;
	this->size++;
}
void deque::pop_front() {
	if (!this->printFront()) {
		this->front = this->front->next;
		this->size--;
	}
}
void deque::pop_back() {
	if (!this->printBack()) {
		node* bf_back = this->front;
		while(bf_back->next != nullptr && bf_back->next != this->back)
			bf_back = bf_back->next;
		bf_back->next = nullptr;
		this->back = bf_back;
		this->size--;
	}
}
bool deque::isEmpty() {
	return this->size == 0;
}
void deque::empty() {
	printf("%d\n", this->size == 0);
}
void deque::printSize() {
	printf("%d\n", this->size);
}
bool deque::printFront() {
	if(!this->isEmpty())
		printf("%d\n", this->front->key);
	else
		printf("-1\n");
	return this->isEmpty();
}
bool deque::printBack() {
	if(!this->isEmpty())
		printf("%d\n", this->back->key);
	else
		printf("-1\n");
	return this->isEmpty();
}
