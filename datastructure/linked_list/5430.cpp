#include <stdio.h>
#include <string.h>

class node {
	private:
		int key;
		node *prev;
		node *next;
	public:
		friend class list;
		node();
		node(int);
		void reverse();
};
class list {
	private:
		node *head;
		node *tail;
		bool reversed;
	public:
		list();
		void add(node*);
		bool deleteFront();
		void reverse();
		void print();
};
void operate(char func[], char arr[], int size);
void readArr(char arr[], int size, list *list);
int main() {
	int tests, arrSize, i;
	char func[100002], arr[400002];
	scanf("%d", &tests);
	for(i=0; i<tests; i++) {
		scanf("%s", func);
		scanf("%d", &arrSize);
		scanf("%s", arr);
		operate(func, arr, arrSize);
	}
	return 0;
}

void readArr(char arr[], int size, list *l) {
	int arrLen = strlen(arr);
	int i=0, tmp=0;
	while(i<arrLen) {
		while('0' <= arr[i] && arr[i] <= '9') {
			if(tmp == 0)
				tmp = arr[i] - '0';
			else {
				tmp *= 10;
				tmp += arr[i] - '0';
			}
			i++;
		}
		if(tmp > 0)
			l->add(new node(tmp));
		tmp = 0;
		i++;
	}
	//printf("READ STR COMPLETE\n");
	//l->print();
}
void operate(char func[], char arr[], int size) {
	list *l = new list();
	int funcLen = strlen(func);
	int i;
	readArr(arr, size, l);
	for(i=0; i<funcLen; i++) {
		if(func[i] == 'R') {
			//printf("run reverse > ");
			l->reverse();
		}
		else if(func[i] == 'D') {
			//printf("run delete  > ");
			if(!l->deleteFront()) {
				printf("error\n");
				return;
			}
		}
		//l->print();
	}
	l->print();
}

node::node() {
	this->prev = nullptr;
	this->next = nullptr;
	this->key = -100;
}
node::node(int k) {
	this->prev = nullptr;
	this->next = nullptr;
	this->key = k;
}
void node::reverse() {
	node *tmp = this->next;
	this->next = this->prev;
	this->prev = tmp;
}

list::list() {
	this->head = nullptr;
	this->tail = nullptr;
	this->reversed = false;
}
void list::add(node *n) {
	if(this->head == nullptr)
		this->head = n;
	else {
		this->tail->next = n;
		n->prev = this->tail;
	}
	this->tail = n;
}
bool list::deleteFront() {
	if(this->reversed) {
		if(this->tail) {
			this->tail = this->tail->prev;
			if(this->tail)
				this->tail->next = nullptr;
			return true;
		}
		else
			return false;
	}
	else {
		if(this->head) {
			if(this->head == this->tail)
				this->tail = nullptr;
			this->head = this->head->next;
			if(this->head)
				this->head->prev = nullptr;
			return true;
		}
		else
			return false;	
	}
}
void list::reverse() {
	this->reversed = !this->reversed;
}
void list::print() {
	printf("[");
	node *cur;
	if(this->reversed) {
		cur = this->tail;
		while(cur && cur != this->head) {
			printf("%d,", cur->key);
			cur = cur->prev;
		}
		if(this->head)
			printf("%d", this->head->key);
	}
	else {
		cur = this->head;
		while(cur && cur != this->tail) {
			printf("%d,", cur->key);
			cur = cur->next;
		}
		if(this->tail)
			printf("%d", this->tail->key);
	}
	printf("]\n");
}
