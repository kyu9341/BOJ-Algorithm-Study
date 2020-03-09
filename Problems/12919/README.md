# Problem 12919

## A와 B 2

### 문제
수빈이는 A와 B로만 이루어진 영어 단어 존재한다는 사실에 놀랐다. 대표적인 예로 AB (Abdominal의 약자), BAA (양의 울음 소리), AA (용암의 종류), ABBA (스웨덴 팝 그룹)이 있다.

이런 사실에 놀란 수빈이는 간단한 게임을 만들기로 했다. 두 문자열 S와 T가 주어졌을 때, S를 T로 바꾸는 게임이다. 문자열을 바꿀 때는 다음과 같은 두 가지 연산만 가능하다.

- 문자열의 뒤에 A를 추가한다.
- 문자열의 뒤에 B를 추가하고 문자열을 뒤집는다.
주어진 조건을 이용해서 S를 T로 만들 수 있는지 없는지 알아내는 프로그램을 작성하시오.

### 입력
첫째 줄에 S가 둘째 줄에 T가 주어진다. (1 ≤ S의 길이 ≤ 49, 2 ≤ T의 길이 ≤ 50, S의 길이 < T의 길이)

### 출력
S를 T로 바꿀 수 있으면 1을 없으면 0을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/12919>

### 예제 입력 1
B
ABBA

### 예제 출력 1
1

### 예제 입력 2
BAAAAABAA
BAABAAAAAB

### 예제 출력 2
1

### 예제 입력 2
A
ABBA

### 예제 출력 2
0

### solve
- 구할 문자열 t에서 다음의 두 경우를 역으로 확인하며 모든 경우를 확인한다.

	1. 마지막 문자가 A인 경우 맨 뒤의 A를 제거한다.
	2. 문자열의 뒤에 B를 추가하고 문자열을 뒤집는다.

- 하지만 조건 없이 모든 경우를 본다면 2^50으로 시간 초과가 날 것이다.
- 1번에 대해 맨 뒤의 문자가 A라면 A를 지우고 다음 경우를 확인한다.
- 2번에 대해 맨 앞의 문자가 B라면 B를 지우고 문자열을 뒤집어 다음 경우를 확인한다.
- 맨 앞의 문자가 A이고 맨 뒤의 문자가 B인 경우는 더 이상 확인이 불가능하므로 모조건 잘못된 경우이므로 제외시킨다.
- 이를 bfs로 구현하였는데 채점 도중 틀렸다고 나와 재귀로 백트래킹을 구현하여 해결하였는데 bfs가 잘못된 이유는 아직 잘 모르겠다.


### 코드 설명
- first code (fail)
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;

string eraseB(string t) // 맨 앞 자리의 B를 지우고 문자열을 뒤집는 함수
{
	t.erase(t.begin(), t.begin() + 1);
	reverse(t.begin(), t.end());
	return t;
}
string eraseA(string t) // 마지막 자리의 A를 지우는 함수
{
	t.erase(t.end() - 1, t.end());
	return t;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	cin >> s >> t;
	int size_S = s.size();

	vector<string> ans;
	queue<string> q;
	q.push(t);

	while (!q.empty())
	{
		string now = q.front();
		q.pop();
		int last_now = now.size() - 1;

		if (now[0] == 'A' && now[last_now] == 'B') continue;
		if (last_now + 1 == size_S)	ans.push_back(now);
		if (last_now + 1 < size_S) break;

		if (now[last_now] == 'A') // t의 마지막 문자가 A라면 A를 지움
		{
			string next = eraseA(now);
			q.push(next);
		}
		if (now[0] == 'B') // 맨 앞 문자가 B라면 B를 지우고 뒤집음
		{
			string next = eraseB(now);
			q.push(next);
		}
	}


	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] == s)
		{
			cout << 1 << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';

}

```

- 정답 코드
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
string s, t;

string eraseB(string t) // 맨 앞 자리의 B를 지우고 문자열을 뒤집는 함수
{
	t.erase(t.begin(), t.begin() + 1);
	reverse(t.begin(), t.end());
	return t;
}
string eraseA(string t) // 마지막 자리의 A를 지우는 함수
{
	t.erase(t.end() - 1, t.end());
	return t;
}

void go(string str)
{
	int size_str = str.size();
	if (s.size() == size_str) // 두 문자열의 크기가 같다면
	{
		if (s == str) // 문자열을 비교
		{
			cout << 1 << '\n'; // 같으면 1 출력 후 종료
			exit(0);
		}
		return;
	}

	if (str[0] == 'A' && str[size_str - 1] == 'B')
		return; // 맨 앞이 A이면서 맨 뒤가 B라면 무조건 잘못된 경우

	if (str[0] == 'B') // 맨 앞 문자가 B인 경우
		go(eraseB(str)); // B를 지우고 뒤집는다

	if (str[size_str - 1] == 'A') // 맨 뒤 문자가 A인 경우
		go(eraseA(str)); // A를 지운다.
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;

	go(t);

	cout << 0 << '\n';

}
```
