#include <stdio.h>

class node {
	private:
		char key;
		node *next;
		node *prev;
	public:
		node();
		node(char);
		friend class list;
		
};
class list {
	private:
		node *head;
		node *cursor;
	public:
		list();
		list(node *);
		void left();
		void right();
		void backspace();
		void paste(node *);
		void print();
		char getCursor();
};
int str_len(char* str) {
	char c = str[0];
	int len=0;
	while(c != '\0') {
		len++;
		c = str[len];
	}
	return len;
}

int main() {
	char str[100002];
	int i, n, size;
	char cmd[2];
	list *l = new list();
	scanf("%s", str);
	size = str_len(str);
	for(i=0; i<size; i++)
		l->paste(new node(str[i]));
	scanf("%d", &n);
	for(i=0; i<n; i++) {
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
		l->print();
		printf("current cursor: %c\n", l->getCursor());
	}
	l->print();
	return 0;
}

node::node(){}
node::node(char k) {
	this->key = k;
	this->next = nullptr;
	this->prev = nullptr;
}

list::list(){}
list::list(node *h) {
	this->head = h;
	this->cursor = this->head;
}
void list::left() {
	if(this->cursor)
		this->cursor = this->cursor->prev;
}
void list::right() {
	if(this->cursor && this->cursor->next)
		this->cursor = this->cursor->next;
	else if(this->cursor == nullptr)
		this->cursor = this->head;
}
void list::backspace() {
	if(this->cursor) {
		if(this->cursor->prev)
			this->cursor->prev->next = this->cursor->next;
		if(this->cursor->next)
			this->cursor->next->prev = this->cursor->prev;
		if(this->cursor == this->head)
			this->head = this->cursor->next;
		this->cursor = this->cursor->prev;
	}
}
void list::paste(node *n) {
	n->prev = this->cursor;
	if(this->cursor) {
		n->next = this->cursor->next;
		this->cursor->next = n;
		this->cursor = n;
	}
	else { // cursor가 head 왼쪽에 있음
		if(this->head) {
			this->head->prev = n;
			n->next = this->head;
		}
		this->head = n;
		this->cursor = n;
	}
}
void list::print() {
	node *cur = this->head;
	while(cur != nullptr) {
		printf("%c", cur->key);
		cur = cur->next;
	}
	printf("\n");
}
char list::getCursor() {
	if(this->cursor)
		return this->cursor->key;
	else
		return '*';
}

