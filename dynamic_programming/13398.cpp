/*
 * 13398. 연속합 2
 * n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
 * 단, 수는 한 개 이상 선택해야 한다. 또, 수열에서 수를 하나 제거할 수 있다. (제거하지 않아도 된다)
 * 예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 수를 제거하지 않았을 때의 정답은 12+21인 33이 정답이 된다.
 * 만약, -35를 제거한다면, 수열은 10, -4, 3, 1, 5, 6, 12, 21, -1이 되고, 여기서 정답은 10-4+3+1+5+6+12+21인 54가 된다.
 *
 * 첫째 줄에 정수 n(1≤n≤100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
 *
 * 첫째 줄에 답을 출력한다.
 *
 * Gold 5
 */
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n;
bool erased;
vector <int> arr;
vector <int> dp;
int minimal();
int maximum();
bool minus();

int main() {
    scanf("%d", &n);
    int idx=n;
    int maxIdx;
    arr.resize(n);
    dp.resize(n);
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);
    int minIdx = minimal();
    erased = arr[minIdx] < 0;
    if(erased) {
        arr.erase(arr.begin()+minIdx);
        idx = n-1;
    }
    if(minus()) {
        printf("%d\n", maximum());
        return 0;
    }
    dp[0] = arr[0];
    for(int i=1; i<idx; i++) {
        dp[i] = max(arr[i], dp[i-1]+arr[i]);
        printf("dp[%d] = %d\n", i, dp[i]);
    }
    if(dp[idx-1] < dp[idx-2])
        dp[idx-1] = dp[idx-2];
    printf("%d\n", dp[idx-1]);
    return 0;
}
int minimal() {
    int m=0, mVal=arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i]<mVal) {
            m = i;
            mVal = arr[i];
        }
    }
    return m;
}
int maximum() {
    int m=0, mVal=arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i]>mVal) {
            m = i;
            mVal = arr[i];
        }
    }
    return mVal;
}
bool minus() {
    int idx = erased ? n-1:n;
    bool m=true;
    for(int i=0; i<idx; i++) {
        if(arr[i] >= 0)
            return false;
    }
    return true;
}