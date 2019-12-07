#include <stdio.h>
#include <string>
using namespace std;
// queue simple implement (array)

class queue {
	private:
		int size;
		int arr[100010];
		int front;
		int back;
	public:
		queue();
		void push(int);
		void pop();
		void empty();
		bool isEmpty();
		void printSize();
		void printFront();
		void printBack();
};

int main() {
	int n, cmdn;
	char tmp[6];
	string cmd;
	queue* q = new queue();
	scanf("%d", &n);
	
	for(int i=0; i<n; i++) {
		scanf("%s", tmp);
		cmd = tmp;
		if(cmd.compare("push") == 0) {
			scanf("%d", &cmdn);
			q->push(cmdn);
		}
		else if(cmd.compare("pop") == 0) {
			q->pop();
		}
		else if(cmd.compare("size") == 0) {
			q->printSize();
		}
		else if(cmd.compare("empty") == 0) {
			q->empty();
		}
		else if(cmd.compare("front") == 0) {
			q->printFront();
		}
		else if(cmd.compare("back") == 0) {
			q->printBack();
		}
	}
}

queue::queue(){
	this->size = 0;
	this->front = 0;
	this->back = -1;
}
void queue::push(int n) {
	this->back++;
	this->arr[this->back] = n;
	this->size++;
}
void queue::pop() {
	if(this->isEmpty()) {
		printf("-1\n");
		return;
	}
	printf("%d\n", this->arr[this->front]);
	this->front++;
	this->size--;
}
bool queue::isEmpty() {
	return this->size == 0;
}
void queue::empty() {
	printf("%d\n", this->size == 0);
}
void queue::printSize() {
	printf("%d\n", this->size);
}
void queue::printFront() {
	if(!this->isEmpty())
		printf("%d\n", this->arr[this->front]);
	else
		printf("-1\n");
}
void queue::printBack() {
	if(!this->isEmpty())
		printf("%d\n", this->arr[this->back]);
	else
		printf("-1\n");
}