# Problem 2138

## 전구와 스위치

### 문제
N개의 스위치와 N개의 전구가 있다. 각각의 전구는 켜져 있는(1) 상태와 꺼져 있는 (0) 상태 중 하나의 상태를 가진다. i(1<i<N)번 스위치를 누르면 i-1, i, i+1의 세 개의 전구의 상태가 바뀐다. 즉, 꺼져 있는 전구는 켜지고, 켜져 있는 전구는 꺼지게 된다. 1번 스위치를 눌렀을 경우에는 1, 2번 전구의 상태가 바뀌고, N번 스위치를 눌렀을 경우에는 N-1, N번 전구의 상태가 바뀐다.

N개의 전구들의 현재 상태와 우리가 만들고자 하는 상태가 주어졌을 때, 그 상태를 만들기 위해 스위치를 최소 몇 번 누르면 되는지 알아내는 프로그램을 작성하시오.

### 입력
첫째 줄에 자연수 N(2≤N≤100,000)이 주어진다. 다음 줄에는 전구들의 현재 상태를 나타내는 숫자 N개가 공백 없이 주어진다. 그 다음 줄에는 우리가 만들고자 하는 전구들의 상태를 나타내는 숫자 N개가 공백 없이 주어진다.

### 출력
첫째 줄에 답을 출력한다. 불가능한 경우에는 -1을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2138>

### 예제 입력 1
3
000
010

### 예제 출력 1
3

### solve
- 1080번 행렬 문제와 비슷하게 0과 1의 상태를 맞춰주는 문제이다.
- 하지만 행렬 문제와는 달리 a[0]의 상태를 바꾸는 방법이 2개이다.
	- 0번 전구 부터 5번 전구까지 각각의 전구의 상태를 바꿀 수 있는 방법의 수는 아래와 같다.
	- 2 3 3 3 3 2 와 같이 가장 적은 방법의 수가 1개가 아니기 때문에 행렬 문제의 방법으로는 해결할 수 없다.
	- 하지만 a[0] 전구의 상태를 먼저 결정하면, 각각의 칸을 바꿀 수 있는 방법을 하나로 만들 수 있다.
	- 1 2 3 3 3 2 와 같이 볼 수 있고, 이제 a[0]과 b[0]의 상태를 비교하여 다르다면 a[1]의 버튼을 눌러서 상태를 맞출 수 있다.
	- 이 과정을 반복하여 n - 1까지 확인 후 같다면 a와 b의 상태를 맞출 수 있다는 것이다.
- 따라서, 0번 전구의 버튼을 누르는 경우와 누르지 않는 경우를 모두 계산하여 가능한 경우를 찾고, 둘 다 가능하다면 최솟값을 출력한다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

void change(vector<int>& a, int now) // i-1, i, i+1을 뒤집는 함수
{
	for (int i = now - 1; i <= now + 1; i++)
	{
		if (i >= 0 && i < a.size()) // 범위 내에서
			a[i] = 1 - a[i]; // 0 -> 1, 1 -> 0
	}
}

pair<bool, int> go(vector<int> a, vector<int>& b) // a와 b가 같은지, 같다면 몇 번만에 가능한지 리턴(a를 변경하지 않음)
{
	int ans = 0;

	for (int i = 0; i < a.size() - 1; i++)
	{
		if (a[i] != b[i]) // 현재 인덱스가 다르면
		{
			change(a, i + 1); // i+1의 스위치를 누른다.(0번은 누르지 않음)
			ans++; // 누르는 횟수 count
		}
	}

	if (a == b) // 연산 후 두 벡터가 같다면
	{
		return { true, ans };
	}
	else
	{
		return { false, ans };
	}


}

int main(void)
{
	int n;
	cin >> n;
	string str;
	vector<int> a(n);
	vector<int> b(n);

	cin >> str;
	for (int i = 0; i < n; i++)
		a[i] = str[i] - '0';
	cin >> str;
	for (int i = 0; i < n; i++)
		b[i] = str[i] - '0';

	auto m1 = go(a, b); // 0번을 누르지 않는 경우
	change(a, 0); // 0번을 누른다
	auto m2 = go(a, b); // 0번을 누르는 경우

	if (m2.first) m2.second++; // 0번을 누르는 경우 포함시켜줌

	if (m1.first && m2.first) // 0번을 누르거나 누르지 않거나 모두 가능한 경우
	{
		cout << min(m1.second, m2.second) << '\n'; // 최솟값 출력
	}
	else if (m1.first)
	{
		cout << m1.second << '\n';
	}
	else if (m2.first)
	{
		cout << m2.second << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}

}

```
