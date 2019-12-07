#include <stdio.h>
#include <iostream>
using namespace std;

class Node {
	private:
		int key;
		Node* left;
		Node* right;
	public:
		Node();
		Node(int);
		void add(Node*);
		void print();
};

int main() {
	int k;
	cin >> k;
	Node* root = new Node(k);
	while(cin >> k) {
		root->add(new Node(k));
	}
	root->print();
}

Node::Node(){}
Node::Node(int k) {
	this->key = k;
	this->left = nullptr;
	this->right = nullptr;
}
void Node::add(Node* n) {
	if(this->key < n->key) {
		if(this->right == nullptr)
			this->right = n;
		else
			this->right->add(n);
	}
	else {
		if(this->left == nullptr)
			this->left = n;
		else
			this->left->add(n);
	}
}
void Node::print() {
	if(this->left != nullptr)
		this->left->print();
	if(this->right != nullptr)
		this->right->print();
	printf("%d\n", this->key);
}