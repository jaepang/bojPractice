#include <stdio.h>
#include <stdlib.h>

class node {
	private:
		int key;
		node *next;
	public:
		node();
		node(int);
		friend class stack;
};
class stack {
	private:
		node *top;
	public:
		stack();
		stack(node*);
		void push(node*);
		int pop();
};

int main() {
	// log
	// 0:push 1:pop -1:x
	int n, i, tmp=0, logidx=0;
	int *arr, *log;
	stack stk;
	scanf("%d", &n);
	arr = (int*)malloc(n*sizeof(int));
	log = (int*)malloc(2*n*sizeof(int));
	for(i=0; i<n; i++) {
		scanf("%d", arr+i);
	}
	i=0;
	while(i<n) {
		//printf("i:%d tmp:%d\n", i, tmp);
		if(arr[i] > tmp) {
			for(int j=0; j<arr[i]-tmp; j++) {
				log[logidx+j] = 0;
				stk.push(new node(tmp+j+1));
			}
			logidx += arr[i]-tmp;
			log[logidx++] = 1;
			if(stk.pop() != arr[i]) {
				printf("NO\n");
				return 0;
			}
			tmp = arr[i]>tmp ? arr[i]:tmp;
		}
		else {
			while(i<n && arr[i]<tmp) {
				log[logidx++] = 1;
				if(stk.pop() != arr[i]) {
					printf("NO\n");
					return 0;
				}
				i++;
			}
			i--;
		}
		i++;
	}
	for(i=0; i<n*2; i++) {
		if(log[i] == 0)
			printf("%c\n", '+');
		else if(log[i] == 1)
			printf("%c\n", '-');
	}
	return 0;
}

node::node(){}
node::node(int k) {
	this->key = k;
}

stack::stack() {
	this->top = nullptr;
}
stack::stack(node *n) {
	this->top = n;
}
void stack::push(node *n) {
	n->next = this->top;
	this->top = n;
}
int stack::pop() {
	int key = -1;
	if(this->top) {
		key = this->top->key;
		this->top = this->top->next;
	}
	//printf("pop %d\n", key);
	return key;
}
