/*
 * 10973. 이전 순열
 * 1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 바로 이전에 오는 순열을 구하는 프로그램을 작성하시오.
 * 사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.
 * N = 3인 경우에 사전순으로 순열을 나열하면 다음과 같다.
 *  1, 2, 3
 *  1, 3, 2
 *  2, 1, 3
 *  2, 3, 1
 *  3, 1, 2
 *  3, 2, 1
 *
 * 첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄에 순열이 주어진다.
 *
 * 첫째 줄에 입력으로 주어진 순열의 이전에 오는 순열을 출력한다. 만약, 사전순으로 처음에 오는 순열인 경우에는 -1을 출력한다.
 *
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int n;
vector <int> subset;
vector <int> nxt;
void swap(int, int);
bool isSmallest(int);
int largestInSmaller(int);
bool prevSubset();

int main() {
    scanf("%d", &n);
    subset.resize(n);
    nxt.resize(n);
    for(int i=0; i<n; i++)
        scanf("%d", &subset[i]);
    bool worked = prevSubset();
    if(!worked)
        printf("-1\n");
    else {
        for(int i=0; i<n; i++)
            printf("%d ", subset[i]);
        printf("\n");
    }
    return 0;
}
void swap(int a, int b) {
    int tmp = subset[a];
    subset[a] = subset[b];
    subset[b] = tmp;
}
bool isSmallest(int pos) {
    int prev = subset[pos];
    for(int i=pos+1; i<n; i++) {
        if(subset[i] < prev)
            return false;
        prev = subset[i];
    }
    return true;
}
int largestInSmaller(int tar) {
    for(int i=n-1; i>=0; i--) {
        if(subset[i] < tar)
            return i;
    }
    return -1;
}
bool prevSubset() {
    bool isFirst = true;
    int pos;
    for(pos=0; pos<n-1; pos++) {
        if(isSmallest(pos))
            break;
        isFirst = false;
    }
    if(isFirst)
        return false;
    swap(pos-1, largestInSmaller(subset[pos-1]));
    sort(subset.begin()+pos, subset.end(), greater<int>());
    return true;
}