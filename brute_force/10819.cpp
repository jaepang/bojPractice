/*
 * 10819. 차이를 최대로
 * N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.
 * |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|
 *
 * 첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.
 *
 * 첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.
 *
 */
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int largest;
vector <int> set;
void swap(int, int);
bool isLargest(int);
int smallestInLarger(int);
bool nxtset();
void calculate();

int main() {
    bool worked = true;
    scanf("%d", &n);
    set.resize(n);
    for(int i=0; i<n; i++)
        scanf("%d", &set[i]);
    sort(set.begin(), set.end());
    while(worked) {
        if(!worked)
            break;
        worked = nxtset();
        calculate();
    }
    printf("%d\n", largest);
    return 0;
}
void swap(int a, int b) {
    int tmp = set[a];
    set[a] = set[b];
    set[b] = tmp;
}
bool isLargest(int pos) {
    int prev = set[pos];
    for(int i=pos+1; i<n; i++) {
        if(set[i] > prev)
            return false;
        prev = set[i];
    }
    return true;
}
int smallestInLarger(int tar) {
    for(int i=n-1; i>=0; i--) {
        if(set[i] > tar)
            return i;
    }
    return -1;
}
bool nxtset() {
    bool isFirst = true;
    int pos;
    for(pos=0; pos<n-1; pos++) {
        if(isLargest(pos))
            break;
        isFirst = false;
    }
    if(isFirst)
        return false;
    swap(pos-1, smallestInLarger(set[pos-1]));
    sort(set.begin()+pos, set.end());
    return true;
}
void calculate() {
    int sum = abs(set[0] - set[1]);
    for(int i=2; i<n; i++)
        sum += abs(set[i-1] - set[i]);
    largest = sum>largest ? sum:largest;
}
