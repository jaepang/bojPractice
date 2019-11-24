#include <stdio.h>
#include <string>
using namespace std;
/**
  * In this problem, tree should be reversed order
  * so this tree is reverse order!!
 **/
class BSTNode {
	private:
		string name;
		BSTNode* left;
		BSTNode* right;
		BSTNode* parent;
	public:
		BSTNode();
		BSTNode(string n);
		string getName();
		BSTNode* getChild(bool isLeft);
		BSTNode* getParent();
		void setName(string n);
		void setChild(BSTNode* child, bool isLeft);
		void setParent(BSTNode* parent);
};
class BST {
	private:
		BSTNode *root;
	public:
		BST();
		BST(BSTNode* r);
		BSTNode* getRoot();
		BSTNode* search(string name);
		BSTNode* searchNearest(string name);
		void add(string name);
		void deleteNode(string name);
		BSTNode* print(BSTNode* node);
};

// bst로 구현합시다
int main() {
	BSTNode *root = new BSTNode("G");
	BST *tree = new BST(root);
	printf("TREE Built success\n");
	
	tree->add("H");
	tree->add("C");
	tree->add("E");
	tree->add("A");
	tree->add("T");
	tree->add("D");
	tree->add("K");
	tree->add("B");
	tree->add("U");
	
	printf("--------print-------\n");
	tree->print(tree->getRoot());
	printf("--------------------\n");
}

BSTNode::BSTNode(){}
BSTNode::BSTNode(string n) {
	this->name = n;
	this->left = NULL;
	this->right = NULL;
	this->parent = NULL;
}
string BSTNode::getName() {
	return this->name;
}
BSTNode* BSTNode::getChild(bool isLeft) {
	if(isLeft) {
		return this->left;	
	}
	else {
		return this->right;
	}
}
BSTNode* BSTNode::getParent() {
	return this->parent;
}
void BSTNode::setName(string n) {
	this->name = n;
}
void BSTNode::setChild(BSTNode* child, bool isLeft) {
	if(isLeft) {
		this->left = child;
	}
	else {
		this->right = child;
	}
}
void BSTNode::setParent(BSTNode* parent) {
	this->parent = parent;
}


BST::BST(){}
BST::BST(BSTNode* r) {
	this->root = r;
}
BSTNode* BST::getRoot() {
	return this->root;
}
BSTNode* BST::search(string name) {
	BSTNode *cur = this->root;
	int cmp;
	while(cur != NULL) {
		cmp = name.compare(cur->getName());
		if(cmp == 0) {
			return cur;
		}
		else {
			cur = cur->getChild(cmp>0);
		}
	}
	return NULL;
}
BSTNode* BST::searchNearest(string name) {
	BSTNode *cur = this->root;
	int cmp;
	while(cur != NULL) {
		cmp = name.compare(cur->getName());
		if(cmp == 0) {
			return cur;
		}
		else {
			if(cur->getChild(cmp>0) == NULL) {
				return cur;
			}
			cur = cur->getChild(cmp>0);
		}
	}
	return NULL;
}
void BST::add(string name) {
	BSTNode* parent = this->searchNearest(name);
	BSTNode* node = new BSTNode(name);
	int cmp = node->getName().compare(parent->getName());
	if(cmp == 0) {
		printf("ERR!! This Node Already Exists: %s\n", parent->getName().c_str());
		return;
	}
	else {
		parent->setChild(node, cmp>0);
		node->setParent(parent);
	}
}
// TODO: care condition when the target is root
void BST::deleteNode(string name) {
	BSTNode *tar = this->search(name);
	BSTNode *parent;
	if(tar) {
		// case 1: no children at all
		if(tar->getChild(true) == NULL && tar->getChild(false) == NULL) {
			parent = tar->parent;
			if(parent->getChild(true) == tar) {
				parent->setChild(NULL, true);
			}
			else {
				parent->setChild(NULL, false);
			}
			tar->setParent(NULL);
		}
		// case 3: 2 children
		else if(tar->getChild(true) != NULL && tar->getChild(false) != NULL) {
			
		}
		// case 2: 1 child
		else {
			
		}
	}
	else {
		printf("ERR!! This Node Doesn't Exist: %s\n", name.c_str());
		return;
	}
}
// order: inorder(left->root->right)
BSTNode* BST::print(BSTNode* node) {
	if(node) {
		print(node->getChild(true));
		printf("%s\n", node->getName().c_str());
		print(node->getChild(false));
	}
}