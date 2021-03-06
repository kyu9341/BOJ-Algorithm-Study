# Problem 2529

## 부등호

### 문제
두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열  A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자.

A =>  < < < > < < > < >

부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다.

3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0

이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다.

5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4

여러분은 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다. 앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다.

### 입력
첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다. 그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k의 범위는 2 ≤ k ≤ 9 이다.

### 출력
여러분은 제시된 부등호 관계를 만족하는 k+1 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다.

### 문제 링크
<https://www.acmicpc.net/problem/2529>

### 예제 입력 1
2
< >

### 예제 출력 1
897
021

### solve
- 0부터 9까지의 숫자를 부등호에 맞게 넣은 최대, 최솟값을 구하는 문제이다.
- 완전 탐색을 하여도 O(n*n!)의 시간복잡도가 걸리므로 가능하다.
- 백트래킹을 이용하여 부등호의 관계가 맞는 경우만을 탐색한다면 더 빠르게 수행이 가능하다.

### 코드 설명
- 완전탐색
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
vector<string> ans; // 정답 후보들을 저장할 벡터
bool check[10];
int n;
char a[20]; // 부등호를 입력받을 배열

bool ok(string num) // 완성된 문자열이 부등호를 만족하는지 판별
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '<')
		{
			if (num[i] > num[i + 1]) return false;
		}
		else if (a[i] == '>')
		{
			if (num[i] < num[i + 1]) return false;
		}
	}
	return true;
}

void go(int index, string num)
{
	if (index == n + 1)
	{
		if(ok(num))
			ans.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (check[i]) continue; // 중복 제거
		check[i] = true;
		go(index + 1, num + to_string(i)); // 문자열에 누적
		check[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, "");

	auto minmax = minmax_element(ans.begin(), ans.end());

	cout << * minmax.second << '\n'; // 최댓값
	cout << * minmax.first << '\n'; // 최솟값

}
```

- 백트래킹
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
vector<string> ans;
bool check[10];
int n;
char a[20]; // 부등호를 입력받을 배열

bool ok(int x, int y, char op)  // 부등호 관계가 맞는지 판별하는 함수
{
	if (op == '<' && x > y)
		return false;
	if (op == '>' && x < y)
		return false;
	return true;

}

void go(int index, string num)
{
	if (index == n + 1) // 부등호 개수 + 1개까지 확인했다면
	{
		ans.push_back(num); // 정답 후보에 추가
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (check[i]) continue; // 중복 제거
		if (index == 0 || ok(num[index - 1] - '0', i, a[index - 1]))
		{ // 첫 번째 수는 그냥 넣고, 다음에 올 수가 부등호 관계를 만족하는지 확인
			check[i] = true; // 사용한 수는 체크
			go(index + 1, num + to_string(i));
			check[i] = false;
		}

	}

}

int main(void)
{
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, "");

	auto p = minmax_element(ans.begin(), ans.end()); // 최대 최소 원소 추출

	cout << * p.second << '\n';
	cout << * p.first << '\n';

}
```
