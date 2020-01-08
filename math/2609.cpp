/*
 * 2609. 최대공약수와 최소공배수
 * 두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.
 *
 * 첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.
 *
 * 첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
 *
 */
#include <stdio.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n%d\n", gcd(a, b), lcm(a, b));
	return 0;
}

int gcd(int a, int b) {
	int tmp;
	while(b > 0) {
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}
int lcm(int a, int b) {
	return a*b / gcd(a, b);	
}
