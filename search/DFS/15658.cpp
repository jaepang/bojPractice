/*
 * 15658. 연산자 끼워넣기 (2)
 * N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 연산자가 주어진다. 
 * 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다. 연산자의 개수는 N-1보다 많을 수도 있다. 
 * 모든 수의 사이에는 연산자를 한 개 끼워넣어야 하며, 주어진 연산자를 모두 사용하지 않고 모든 수의 사이에 연산자를 끼워넣을 수도 있다.
 * 우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.
 * 예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 3개, 뺄셈(-) 2개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 250가지의 식을 만들 수 있다. 예를 들어, 아래와 같은 식을 만들 수 있다.
 * 1+2+3-4×5÷6
 * 1÷2+3+4-5×6
 * 1+2÷3×4-5+6
 * 1÷2×3-4+5+6
 * 1+2+3+4-5-6
 * 1+2+3-4-5×6
 * 식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 
 * 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.
 * 1+2+3-4×5÷6 = 1
 * 1÷2+3+4-5×6 = 12
 * 1+2÷3×4-5+6 = 5
 * 1÷2×3-4+5+6 = 7
 * 1+2+3+4-5-6 = -1
 * 1+2+3-4-5×6 = -18
 * N개의 수와 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.
 *
 * 첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 
 * 셋째 줄에는 합이 N-1보다 크거나 같고, 4N보다 작거나 같은 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다. 
 *
 * 첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 
 * 최댓값과 최솟값이 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 
 * 또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.
 *
 */
#include <stdio.h>
#include <vector>
using namespace std;

int n;
vector <int> nums;
vector <int> set;
int maximum;
int minimum;
bool first=true;
int opr[4]; // 0:+ 1:- 2:* 3:/
void DFS(int depth);
int calc();

int main() {
    scanf("%d", &n);
    nums.resize(n);
    set.resize(n-1);
    for(int i=0; i<n; i++)
        scanf("%d", &nums[i]);
    for(int i=0; i<4; i++)
        scanf("%d", opr+i);
    DFS(0);
    printf("%d\n%d\n", maximum, minimum);
    return 0;
}

int calc() {
    int result=nums[0];
    for(int i=0; i<n-1; i++) {
        if(set[i] == 0)
            result += nums[i+1];
        else if(set[i] == 1)
            result -= nums[i+1];
        else if(set[i] == 2)
            result *= nums[i+1];
        else if(set[i] == 3)
            result /= nums[i+1];
    }
    return result;
}

void DFS(int depth) {
    if(depth==n-1) {
        int result = calc();
        if(first) {
            maximum = result;
            minimum = result;
            first = false;
        }
        else {
            maximum = maximum<result ? result:maximum;
            minimum = minimum>result ? result:minimum;
        }
        return;
    }
    for(int i=0; i<4; i++) {
        if(opr[i] > 0) {
            set[depth] = i;
            opr[i]--;
            DFS(depth+1);
            opr[i]++;
        }
    }
}
