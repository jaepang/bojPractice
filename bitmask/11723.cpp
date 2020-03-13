/*
 * 11723. 집합
 * 비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.
 * add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
 * remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
 * check x: S에 x가 있으면 1을, 없으면 0을 출력한다.
 * toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
 * all: S를 {1, 2, ..., 20} 으로 바꾼다.
 * empty: S를 공집합으로 바꾼다.
 *
 * 첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
 * 둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.
 *
 * check 연산이 주어질때마다, 결과를 출력한다.
 *
 */
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int set;
void add(int x);
void remove(int x);
void check(int x);
void toggle(int x);
void all();
void empty();

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m, val;
    string cmd;
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> cmd;
        if(cmd.compare("all")==0 || cmd.compare("empty")==0) {
            if(cmd.compare("all")==0)
                all();
            else
                empty();
        }
        else {
            cin >> val;
            if(cmd.compare("add")==0)
                add(val);
            else if(cmd.compare("remove")==0)
                remove(val);
            else if(cmd.compare("check")==0)
                check(val);
            else if(cmd.compare("toggle")==0)
                toggle(val);
        }
        //cout << bitset<8>(set) << "\n";
    }
    return 0;
}

void add(int x) {
    set |= 1 << x;
}
void remove(int x) {
    set &= ~(1<<x);
}
void check(int x) {
    cout << ((set >> x) & 1) << "\n";
}
void toggle(int x) {
    if(set & (1<<x))
        remove(x);
    else
        add(x);
}
void all() {
    for(int i=1; i<=20; i++)
        set |= 1 << i;
}
void empty() {
    set = 0;
}
