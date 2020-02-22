# Problem 13913

## 숨바꼭질 4

### 문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

### 입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

### 출력
첫째 줄에 수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

둘째 줄에 어떻게 이동해야 하는지 공백으로 구분해 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/13913>

### 예제 입력 1
5 17

### 예제 출력 1
4
5 10 9 18 17

### 예제 입력 2
5 17

### 예제 출력 2
4
5 4 8 16 17

### solve
- 1초 단위로만 이동이 가능하기 때문에 간선의 가중치는 모두 1이고, 최소 비용 문제이기 때문에 bfs를 이용하여 구할 수 있다.
- 처음 수빈이의 위치를 시작 노드로 하여 큐에 넣어준다.
- 수빈이가 이동 가능한 경우는 x + 1, x - 1, x * 2 이므로 각각의 경우를 모두 큐에 넣고
  - n부터 현재 위치까지 몇 초가 걸리는지 저장할 sec배열의 다음 위치에 현재 위치 +1의 값을 넣어준다.
  - 이때, sec[n] = 0으로 초기화 한다. ()수빈이의 시작 위치)
- 수빈이의 위치 n에서부터 이동 가능한 모든 위치의 시간을 구한 뒤 sec[k]를 출력한다.
- 숨바꼭질 문제와는 다르게 어떻게 이동했는지를 출력해야 한다.
  - 이동했던 기록을 record라는 배열에 기록한다.
  - 다음 위치의 인덱스에 이전 위치를 기록하여 재귀함수를 통해 스택에 이동한 기록을 넣어 뒤집어 출력한다.

### 코드 설명
- 잘못된 코드
  - 원래 이동 가능한 경우는 x + 1, x - 1, x * 2 뿐인데,
  - 아래와 같이 짠다면 x / 2로도 이동이 가능하다.
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1];
int sec[MAX + 1];
int record[MAX + 1]; // 어디를 거쳐갔는지 기록할 배열
stack<int> s;
int n, k;

void print_record(int k)
{
	if (record[k] == -1) // 처음 위치를 찾으면
	{
		s.push(n); // 수빈이의 위치
		while (!s.empty())
		{
			cout << s.top() << ' '; // 스택을 비우며 모두 출력
			s.pop();
		}
		cout << '\n';
		return;
	}
	s.push(k); // 스택에 넣어 뒤집이 출력
	print_record(record[k]);
}

int main(void)
{
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	sec[n] = 0; // 수빈이의 위치에서 시작
	record[n] = -1; // 초기 위치 설정 0으로하면 0부터 시작하는 경우에 예외발생

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (node - 1 >= 0)
		{
			if (check[node - 1] == false) // x - 1의 경우
			{
				q.push(node - 1);
				check[node - 1] = true;
				sec[node - 1] = sec[node] + 1;
				record[node - 1] = node; // 이전 위치를 기록한다.
			}
		}
		if (node + 1 <= MAX)
		{
			if (check[node + 1] == false) // x + 1의 경우
			{
				q.push(node + 1);
				check[node + 1] = true;
				sec[node + 1] = sec[node] + 1;
				record[node + 1] = node;
			}
		}
		if (node * 2 <= MAX)
		{
			if (check[node * 2] == false) // x * 2의 경우
			{
				q.push(node * 2);
				check[node * 2] = true;
				sec[node * 2] = sec[node] + 1;
				record[node * 2] = node;
			}
		}

	}

	cout << sec[k] << '\n';
	print_record(k);
}

```
