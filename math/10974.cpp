/*
 * 10974. 모든 순열
 * N이 주어졌을 때, 1부터 N까지의 수로 이루어진 순열을 사전순으로 출력하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다. 
 *
 * 첫째 줄부터 N!개의 줄에 걸쳐서 모든 순열을 사전순으로 출력한다.
 *
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector <int> subset;
vector <int> nxt;
void swap(int, int);
bool isLargest(int);
int smallestInLarger(int);
bool nxtSubset();

int main() {
    bool worked = true;
    scanf("%d", &n);
    subset.resize(n);
    nxt.resize(n);
    for(int i=0; i<n; i++)
        subset[i] = i+1;
    while(worked) {
        if(!worked)
            break;
        else {
            for(int i=0; i<n; i++)
                printf("%d ", subset[i]);
            printf("\n");
        }
        worked = nxtSubset();
    }
    
    return 0;
}
void swap(int a, int b) {
    int tmp = subset[a];
    subset[a] = subset[b];
    subset[b] = tmp;
}
bool isLargest(int pos) {
    int prev = subset[pos];
    for(int i=pos+1; i<n; i++) {
        if(subset[i] > prev)
            return false;
        prev = subset[i];
    }
    return true;
}
int smallestInLarger(int tar) {
    for(int i=n-1; i>=0; i--) {
        if(subset[i] > tar)
            return i;
    }
    return -1;
}
bool nxtSubset() {
    bool isFirst = true;
    int pos;
    for(pos=0; pos<n-1; pos++) {
        if(isLargest(pos))
            break;
        isFirst = false;
    }
    if(isFirst)
        return false;
    swap(pos-1, smallestInLarger(subset[pos-1]));
    sort(subset.begin()+pos, subset.end());
    return true;
}