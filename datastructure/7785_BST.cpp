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
		BSTNode* smallestOnRight();
};
class BST {
	private:
		BSTNode *root;
	public:
		BST();
		BST(BSTNode* r);
		BSTNode* getRoot();
		void setRoot(BSTNode* r);
		BSTNode* search(string name);
		BSTNode* searchNearest(string name);
		void add(string name);
		void deleteNode(string name);
		BSTNode* print(BSTNode* node);
};

// bst로 구현합시다
int main() {
	int n;
	string name, cmd;
	char tmpn[6], tmpcmd[6];
	BST* tree = new BST();
	
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%s%s", tmpn, tmpcmd);
		name = tmpn;
		cmd = tmpcmd;
		if(cmd.compare("enter") == 0) {
			tree->add(name);
		}
		else {
			tree->deleteNode(name);
		}
	}
	
	tree->print(tree->getRoot());
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
BSTNode* BSTNode::smallestOnRight() {
	BSTNode* cur = this->getChild(false);
	while(cur->getChild(true) != NULL) {
		cur = cur->getChild(true);
	}
	return cur;
}

BST::BST(){
	this->root = NULL;
}
BST::BST(BSTNode* r) {
	this->root = r;
}
BSTNode* BST::getRoot() {
	return this->root;
}
void BST::setRoot(BSTNode* r) {
	this->root = r;
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
	if(!parent) {
		this->setRoot(node);
		return;
	}
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
	BSTNode* replace;
	bool isLeft;
	if(tar) {
		parent = tar->getParent();
		// case 1: no children at all
		if(tar->getChild(true) == NULL && tar->getChild(false) == NULL) {
			if(tar == this->root) {
				this->setRoot(NULL);
				return;
			}
			isLeft = parent->getChild(true) == tar;
			parent->setChild(NULL, isLeft);
			tar->setParent(NULL);
		}
		// case 3: 2 children
		else if(tar->getChild(true) != NULL && tar->getChild(false) != NULL) {
			replace = tar->smallestOnRight();
			if(replace->getParent() != tar) {
				// set replace's right child to replace's prarent's left child
				replace->getParent()->setChild(replace->getChild(false), true);
				if(replace->getChild(false)) {
					replace->getChild(false)->setParent(replace->getParent());
				}
			}
			replace->setParent(parent);
			replace->setChild(tar->getChild(true), true);
			
			if(parent) {
				isLeft = tar == parent->getChild(true);
				parent->setChild(replace, isLeft);
			}
			else {
				this->setRoot(replace);
			}
		}
		// case 2: 1 child
		else {
			isLeft = tar->getChild(true) != NULL;
			replace = tar->getChild(isLeft);
			if(tar == this->getRoot()) {
				this->setRoot(tar->getChild(isLeft));
			}
			tar->getChild(isLeft)->setParent(parent);
			tar->setChild(NULL, isLeft);
			if(parent) {
				isLeft = parent->getChild(true) == tar;
				parent->setChild(replace, isLeft);
				replace->setParent(parent);	
			}
		}
		tar->setParent(NULL);
		tar->setChild(NULL, true);
		tar->setChild(NULL, false);
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
