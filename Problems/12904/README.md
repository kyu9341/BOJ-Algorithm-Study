# Problem 12904

## A와 B

### 문제
수빈이는 A와 B로만 이루어진 영어 단어가 존재한다는 사실에 놀랐다. 대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다. 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다. 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

- 문자열의 뒤에 A를 추가한다.
- 문자열을 뒤집고 뒤에 B를 추가한다.
주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오.

### 입력
첫째 줄에 수열의 크기 N이 주어진다. N은 10보다 작거나 같은 자연수이다. 둘째 줄에는 N(N+1)/2 길이의 문자열이 주어진다. 처음 N개의 문자는 부호 배열의 첫 번째 줄에 해당하고, 다음 N-1개의 문자는 두 번째 줄에 해당한다. 마찬가지로 마지막 문자는 N번째 줄에 해당하는 문자다.

### 출력
첫째 줄에 S가 둘째 줄에 T가 주어진다. (1 ≤ S의 길이 ≤ 999, 2 ≤ T의 길이 ≤ 1000, S의 길이 < T의 길이)

### 문제 링크
<https://www.acmicpc.net/problem/12904>

### 예제 입력 1
B
ABBA

### 예제 출력 1
1

### 예제 입력 2
AB
ABB

### 예제 출력 2
0

### solve
- 항상 s의 맨 뒤에 A 또는 B를 추가하여 t를 만들어야 한다.
- 그 말은 t의 맨 뒤에는 A와 B가 있을 것이다. 따라서, t에서 맨 뒤에 있는 문자를 하나씩 제거하며 s와 같은 크기가 되었을 때, t와 s가 같다면 s를 1, 2번 조건에 따라 t로 만들 수 있다는 뜻이다.

	1. 마지막 문자가 A인 경우 맨 뒤의 A를 제거한다.
	2. 마지막 문자가 B인 경우 B를 제거하고 문자를 뒤집는다.
	
- 위의 두 조건을 t에 적용하여 s와 크기가 같아지면 두 문자열을 비교하여 같다면 1, 다르면 0을 출력한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

string eraseB(string t) // 마지막 자리의 B를 지우고 문자열을 뒤집는 함수
{
	reverse(t.begin(), t.end());
	t.erase(t.begin(), t.begin() + 1);
	return t;
}
string eraseA(string t) // 마지막 자리의 A를 지우는 함수
{
	t.erase(t.end() - 1, t.end());
	return t;
}

int main(void)
{
	string s, t;
	cin >> s >> t;
	int size_S = s.size();

	while (t.size() > size_S) // t와 s의 크기가 같아질 때까지 반복
	{
		int last_T = t.size() - 1;
		if (t[last_T] == 'A') // t의 마지막 문자가 A라면 A를 지움
			t = eraseA(t);
		else if (t[last_T] == 'B') // B라면 B를 지우고 뒤집음
			t = eraseB(t);

	}

	if (t == s) cout << 1 << '\n'; // 크기가 같아졌을 때, 문자열이 같다면 s를 t로 바꿀 수 있음
	else cout << 0 << '\n';

}
```
