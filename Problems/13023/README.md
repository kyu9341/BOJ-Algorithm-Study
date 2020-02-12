# Problem 13023

## ABCDE

### 문제
BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.

오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.

- A는 B와 친구다.
- B는 C와 친구다.
- C는 D와 친구다.
- D는 E와 친구다.

위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.

둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

### 출력
문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/13023>

### 예제 입력 1
5 4
0 1
1 2
2 3
3 4

### 예제 출력 1
1

### 예제 입력 2
5 5
0 1
1 2
2 3
3 0
1 4

### 예제 출력 2
1

### 예제 입력 3
6 5
0 1
0 2
0 3
0 4
0 5

### 예제 출력 3
0

### 예제 입력 4
8 8
1 7
3 7
4 7
3 4
4 6
3 5
0 4
2 7

### 예제 출력 4
1

### solve
- 문제를 보면 결국 A-B-C-D-E 와 같은 그래프가 존재하는지 확인하면 된다.
- DFS를 이용하여 재귀 호출이 발생할 때마다 count를 1씩 증가하여 5가 되면 리턴하면 된다.



### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring> // memset

using namespace std;
vector<int> a[2001]; // 인접 리스트
bool check[2001];
bool ans = false;

void dfs(int node, int count)
{
	if (count == 5) // 5명이 연속으로 친구인 경우
	{
		ans = true;
		return;
	}
	check[node] = true; // 현재 노드 방문 처리
	for (int i = 0; i < a[node].size(); i++) // 현재 노드와 연결된 노드 확인
	{
		int next = a[node][i]; // 다음 확인할 노드
		if (!check[next]) // 방문하지 않았다면
		{
			dfs(next, count + 1);
		}
		if (ans) return;
	}
	check[node] = false;
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 0; i <= n; i++)
	{
		ans = false;
		memset(check, false, sizeof(check)); // check배열 초기화
		dfs(i, 1); // count = 1 부터 시작
		if (ans) // count가 5인 경우
		{
			cout << 1 << '\n';
			break;
		}
	}
	if (!ans)
		cout << 0 << '\n';

}

```
