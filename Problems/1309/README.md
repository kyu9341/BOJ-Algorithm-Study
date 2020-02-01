# Problem 1309

## 동물원

### 문제
어떤 동물원에 가로로 두칸 세로로 N칸인 아래와 같은 우리가 있다.

이 동물원에는 사자들이 살고 있는데 사자들을 우리에 가둘 때, 가로로도 세로로도 붙어 있게 배치할 수는 없다. 이 동물원 조련사는 사자들의 배치 문제 때문에 골머리를 앓고 있다.

동물원 조련사의 머리가 아프지 않도록 우리가 2*N 배열에 사자를 배치하는 경우의 수가 몇 가지인지를 알아내는 프로그램을 작성해 주도록 하자. 사자를 한 마리도 배치하지 않는 경우도 하나의 경우의 수로 친다고 가정한다.

### 입력
첫째 줄에 우리의 크기 N(1≤N≤100,000)이 주어진다.

### 출력
첫째 줄에 사자를 배치하는 경우의 수를 9901로 나눈 나머지를 출력하여라.

### 문제 링크
<https://www.acmicpc.net/problem/1309>

### 예제 입력 1
4

### 예제 출력 1
41

### solve
- 점화식 d[i][j] = 2xi 배열에 사자를 배치하는 경우의 수, j는 이전 행의 사자 위치(없으면 인덱스 0)
	- 이전 행에 사자의 위치를 기억하여 다음에 사자를 어디에 배치할지 결정
	- 사자가 없는 경우도 배치를 하는 것으로 치기 때문에 없는 경우를 항상 더해주어야 함.
- d[i][0] = d[i - 1][1] + d[i - 1][2] + d[i - 1][0]; // 사자가 없는 경우에는 사자가 1열에 있거나 2열에 있거나 없는 경우 모두 가능
-	d[i][1] = d[i - 1][2] + d[i - 1][0]; // 이전 행의 1열에 사자가 있다면 2열에 사자를 놓거나 놓지 않는 경우 가능
-	d[i][2] = d[i - 1][1] + d[i - 1][0]; // 이전 행의 2열에 사자가 있다면 1열에 사자를 놓거나 놓지 않는 경우 가능


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
using namespace std;
const int mod = 9901;
long long d[100001][3]; // d[i][j] = 2xi 배열에 사자를 배치하는 경우의 수, j는 이전 행의 사자 위치(없으면 인덱스 0)
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; //  N(1≤N≤100,000)
	cin >> n;
	d[1][0] = 1; // 세로 1칸에 사자가 없는 경우
	d[1][1] = 1; // 세로 1칸에 사자가 첫째 열에 있는 경우
	d[1][2] = 1; // 세로 1칸에 사자가 둘째 열에 있는 경우

	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][1] + d[i - 1][2] + d[i - 1][0]; // 사자가 없는 경우에는 사자가 1열에 있거나 2열에 있거나 없는 경우 모두 가능
		d[i][1] = d[i - 1][2] + d[i - 1][0]; // 이전 행의 1열에 사자가 있다면 2열에 사자를 놓거나 놓지 않는 경우 가능
		d[i][2] = d[i - 1][1] + d[i - 1][0]; // 이전 행의 2열에 사자가 있다면 1열에 사자를 놓거나 놓지 않는 경우 가능

		d[i][0] %= mod;
		d[i][1] %= mod;
		d[i][2] %= mod;
	}

	cout << (d[n][0] + d[n][1] + d[n][2]) % mod << '\n';

}
```