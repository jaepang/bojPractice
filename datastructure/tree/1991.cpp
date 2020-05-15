/* 
 * 1991. 트리 순회
 * 이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 
 * 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.
 * 
 * 첫째 줄에는 이진 트리의 노드의 개수 N(1≤N≤26)이 주어진다. 
 * 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 
 * 노드의 이름은 A부터 차례대로 영문자 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 
 * 자식 노드가 없는 경우에는 .으로 표현된다.
 * 
 * 첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 
 * 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
 * 
 * Silver 1
 */
#include <stdio.h>

class node {
    private:
        char key;
        node *left;
        node *right;
    public:
        friend class tree;
        node() {
            this->left = NULL;
            this->right = NULL;
        }
        node(char k) {
            this->key = k;
            this->left = NULL;
            this->right = NULL;
        }
        void setLeft(char k);
        void setRight(char k);
};
class tree {
    private:
        node *root;
    public:
        tree() {
            this->root = NULL;
        }
        void setRoot(char k);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        node *search(node *, char);
        node *getRoot();
};

int main() {
    tree *t = new tree();
    int n;
    char nd, lft, rght;
    char str[6];
    node *tar;
    scanf("%d", &n);
    getchar();
    for(int i=0; i<n; i++) {
        //scanf("%c %c %c", &nd, &lft, &rght);
        fgets(str, 6, stdin);
        getchar();
        nd = str[0];
        lft = str[2];
        rght = str[4];
        
        tar = t->search(t->getRoot(), nd);
        if(tar == NULL) {
            t->setRoot(nd);
            tar = t->getRoot();
        }
        if(lft != '.' && lft != '\n')
            tar->setLeft(lft);
        if(rght != '.' && rght != '\n')
            tar->setRight(rght);
        //t->inorder(t->getRoot());
        //printf("\n");
    }
    t->preorder(t->getRoot());
    printf("\n");
    t->inorder(t->getRoot());
    printf("\n");
    t->postorder(t->getRoot());
    printf("\n");
}

void node::setLeft(char k) {
    node *lft = new node(k);
    this->left = lft;
}
void node::setRight(char k) {
    node *rght = new node(k);
    this->right = rght;
}
void tree::setRoot(char k) {
    node *rt = new node(k);
    this->root = rt;
}
node * tree::getRoot() {
    return this->root;
}
node * tree::search(node *cur, char k) {
    node *tar = NULL;
    if(cur != NULL) {
        if(cur->key == k)
            return cur;
        tar = search(cur->left, k);
        tar = tar!=NULL ? tar:search(cur->right, k);
    }
    return tar;
}

void tree::preorder(node *cur) {
    if(cur != NULL) {
        printf("%c", cur->key);
        preorder(cur->left);
        preorder(cur->right);
    }
}
void tree::inorder(node *cur) {
    if(cur != NULL) {
        inorder(cur->left);
        printf("%c", cur->key);
        inorder(cur->right);
    }
}
void tree::postorder(node *cur) {
    if(cur != NULL) {
        postorder(cur->left);
        postorder(cur->right);
        printf("%c", cur->key);
    }
}
