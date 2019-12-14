#include <stdio.h>
#include <string>
using namespace std;
// deque: double-ended deque => front, back 모두 삽입, 삭제가 가능

class dedeque {
	private:
		int size;
		int arr[100010];
		int front;
		int back;
	public:
		deque();
		void push_front(int);
		void push_back(int);
		void pop_front();
		void pop_back();
		void empty();
		bool isEmpty();
		void printSize();
		void printFront();
		void printBack();
};

int main(){}

deque::deque(){
	this->size = 0;
	this->front = 0;
	this->back = -1;
}
void deque::push_front(int n) {
	this->back++;
	this->arr[this->back] = n;
	this->size++;
}
void deque::push_back(int n) {
	this->back++;
	this->arr[this->back] = n;
	this->size++;
}
void deque::pop() {
	if(this->isEmpty()) {
		printf("-1\n");
		return;
	}
	printf("%d\n", this->arr[this->front]);
	this->front++;
	this->size--;
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
void deque::printFront() {
	if(!this->isEmpty())
		printf("%d\n", this->arr[this->front]);
	else
		printf("-1\n");
}
void deque::printBack() {
	if(!this->isEmpty())
		printf("%d\n", this->arr[this->back]);
	else
		printf("-1\n");
}