#include <stdio.h>
#include <string.h>

class node {
	private:
		char key;
		node *prev;
		node *next;
	public:
		friend class list;
		node();
		node(char);
};
class list {
	private:
		node *head;
		node *tail;
		node *cursor;
	public:
		list();
		void paste(node*);
		void backspace();
		void left();
		void right();
		void print();
		void getCursor();
};

int main() {
	char str[100002], cmd[3];
	int n, size;
	list *l = new list();
	scanf("%s%d", str, &n);
	size = strlen(str);
	for(int i=0; i<size; i++)
		l->paste(new node(str[i]));
	for(int i=0; i<n; i++) {
		scanf("%s", cmd);
		if(cmd[0] == 'L')
			l->left();
		else if(cmd[0] == 'D')
			l->right();
		else if(cmd[0] == 'B')
			l->backspace();
		else if(cmd[0] == 'P') {
			scanf("%s", cmd);
			l->paste(new node(cmd[0]));
		}
		//l->print();
		//l->getCursor();
	}
	l->print();
	return 0;
}

node::node() {
	this->prev = nullptr;
	this->next = nullptr;
	this->key = '*';
}
node::node(char k) {
	this->prev = nullptr;
	this->next = nullptr;
	this->key = k;
}

list::list() {
	this->head = new node();
	this->tail = new node();
	this->head->next = this->tail;
	this->tail->prev = this->head;
	this->cursor = this->head;
}
// 0 1 3 4 5 6 7
//   ^
// 0 1 2 3 4 5 6 7
//     ^
void list::paste(node *n) {
	this->cursor->next->prev = n;
	n->next = this->cursor->next;
	n->prev = this->cursor;
	this->cursor->next = n;
	this->cursor = n;
}
// 0 1 2 3 4 5 6 7
//     ^
// 0 1 3 4 5 6 7
//   ^
void list::backspace() {
	if(this->cursor!=this->head) {
		this->cursor->prev->next = this->cursor->next;
		this->cursor->next->prev = this->cursor->prev;
		this->cursor = this->cursor->prev;
		if(this->head->next == this->tail)
			this->cursor = this->tail;
	}
}
void list::left() {
	if(this->cursor != this->head)
		this->cursor = this->cursor->prev;
}
void list::right() {
	if(this->cursor->next != this->tail)
		this->cursor = this->cursor->next;
}
void list::print() {
	node *cur = this->head->next;
	while(cur != this->tail) {
		printf("%c", cur->key);
		cur = cur->next;
	}
	printf("\n");
}
void list::getCursor() {
	printf("cursor: %c", this->cursor->key);
	if(this->cursor == this->head) {
		printf("(head)");
	}
	if(this->cursor == this->tail) {
		printf("(tail)");
	}
	printf("\n");
}
