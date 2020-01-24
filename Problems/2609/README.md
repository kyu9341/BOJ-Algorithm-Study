# Problem 2609

## 최대공약수와 최소공배수

### 문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.


### 입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

### 출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를,둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2609>

### 예제 입력 1
24 18

### 예제 출력 1
6
72

### solve

#### 최대공약수(GCD)
- GCD를 구하는 가장  쉬운 방법 : 2부터 min(A, B)까지 모든 정수로 나누어 보는 방법
- 최대공약수가 1인 두 수를 서로소(Coprime)라고 한다.

##### 유클리드 호제법
- a를 b로 나눈 나머지를 r이라고 했을 때
- GCD(a, b) = GCD(b, r) 과 같다.
- r이 0이면 그 때 b가 최대 공약수이다.
- GCD(24, 16) = GCD(16, 8) = GCD(8, 0) = 8
- 재귀함수로 구현 가능

#### 최소공배수(LCM)
- 최소공배수는 GCD를 응용하여 구할 수 있다.
- 두 수 a, b의 최대공약수를 g라고 했을 때
- 최소공배수 l = g*(a/g) \* (b/g)이다.
	- G = GCD(A, B)
	- A*B = GCD * LCM
	- LCM = (A*B)/G


### 코드 설명
```C++
#include<iostream>

using namespace std;

int GCD(int, int);

int main(void)
{
	int a, b;
	cin >> a >> b;
	int gcd = GCD(a, b);
	int lcm = (a * b) / gcd; // a*b = gcd * lcm 에서 유도
	cout << gcd << '\n';
	cout << lcm << '\n';

}

int GCD(int a, int b) // 최대 공약수 구하는 함수
{
	if (b == 0) // 유클리드 호제법 - GCD(a, b) -> a%b = r
		return a; // GCD(b, r) -> r = 0 일때, b가 최대공약수
	else return GCD(b, a % b);
}

```
