/*
 * 1927. 최소 힙
 * 널리 잘 알려진 자료구조 중 최소 힙이라는 것이 있다. 최소 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.
 *  1. 배열에 자연수 x를 넣는다.
 *  2. 배열에서 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
 * 프로그램은 처음에 비어있는 배열에서 시작하게 된다.
 *
 * 첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 
 * 만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 
 * 입력되는 자연수는 2^31보다 작다.
 *
 * 입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class minHeap {
    /*
     * heap index rule
     * leftChildIdx = parentIdx * 2
     * rightChildIdx = parentIdx * 2 + 1
     * => parentIdx = anyChildIdx / 2
     */
    private:
        int *tree;
        int size;
    public:
        minHeap();
        minHeap(int);
        void swap(int, int);
        void push(int);
        int pop();
};


int main() {
    int n, input;
    scanf("%d", &n);
    minHeap *heap = new minHeap(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &input);
        if(input == 0) {
            printf("%d\n", heap->pop());
            // pop-minimum
        }
        else {
            heap->push(input);
            // push to heap
        }
    }
    return 0;
}

minHeap::minHeap(){}
minHeap::minHeap(int capacity){
    this->tree = (int*)malloc(sizeof(int) * capacity);
    this->size = 0;
}
void minHeap::swap(int idx1, int idx2) {
    int tmp = this->tree[idx2];
    this->tree[idx2] = this->tree[idx1];
    this->tree[idx1] = tmp;
}
void minHeap::push(int val) {
    this->size++;
    int cur = this->size;
    this->tree[this->size] = val;
    while(cur > 0) {
        if(tree[cur] < tree[cur/2])
            this->swap(cur, cur/2);
        else
            break;
        cur /= 2;
    }
}
int minHeap::pop() {
    if(this->size == 0)
        return 0;
    
    int cur=1, left=2, right=3, swapTar;
    int min = this->tree[1];
    this->tree[1] = this->tree[size];
    tree[size] = 0;
    this->size--;
    while(left <= size) {
        if(right > this->size)
            swapTar = left;
        else
            swapTar = this->tree[left]<this->tree[right] ? left:right;
        
        if(this->tree[swapTar] < this->tree[cur])
            this->swap(swapTar, cur);
        else
            break;

        cur = swapTar;
        left = cur*2;
        right = cur*2+1;
    }
    return min;
}
