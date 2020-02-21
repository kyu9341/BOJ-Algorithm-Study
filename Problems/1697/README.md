# Problem 1697

## 숨바꼭질

### 문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.

수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

### 입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

### 출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1697>

### 예제 입력 1
5 17

### 예제 출력 1
4


### solve
- 1초 단위로만 이동이 가능하기 때문에 간선의 가중치는 모두 1이고, 최소 비용 문제이기 때문에 bfs를 이용하여 구할 수 있다.
- 처음 수빈이의 위치를 시작 노드로 하여 큐에 넣어준다.
- 수빈이가 이동 가능한 경우는 x + 1, x - 1, x * 2 이므로 각각의 경우를 모두 큐에 넣고
  - n부터 현재 위치까지 몇 초가 걸리는지 저장할 sec배열의 다음 위치에 현재 위치 +1의 값을 넣어준다.
  - 이때, sec[n] = 0으로 초기화 한다. ()수빈이의 시작 위치)
- 수빈이의 위치 n에서부터 이동 가능한 모든 위치의 시간을 구한 뒤 sec[k]를 출력한다.


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

using namespace std;
const int MAX = 100000;
bool check[MAX + 1];
vector<int> a[MAX + 1];
int sec[MAX + 1];

int main(void)
{
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= MAX; i++)
	{
		if (i + 1 <= MAX)
		{
			a[i] .push_back(i + 1);
			a[i + 1].push_back(i);
		}
		if (i * 2 <= MAX)
		{
			a[i].push_back(i * 2);
			a[2 * i].push_back(i);
		}
	}

	memset(sec, -1, sizeof(sec));

	queue<int> q;
	q.push(n);
	check[n] = true;
	sec[n] = 0;

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int i = 0; i < a[node].size(); i++)
		{
			int next = a[node][i];
			if (check[next] == false)
			{
				q.push(next);
				check[next] = true;
				if(sec[next] == -1 || sec[next] > sec[node] + 1)
					sec[next] = sec[node] + 1;
			}
		}
		if (check[k])
			break;
	}

	cout << sec[k] << '\n';
}

```

- 정답 코드
```cpp

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1]; // 방문 여부 판단
int sec[MAX + 1]; // n번째 노드까지의 시간

int main(void)
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	sec[n] = 0; // 수빈이의 위치에서 시작

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (node - 1 >= 0) // x - 1의 경우
		{
			if (check[node - 1] == false)
			{
				q.push(node - 1);
				check[node - 1] = true;
				sec[node - 1] = sec[node] + 1;
			}
		}
		if (node + 1 <= MAX) //  x + 1의 경우
		{
			if (check[node + 1] == false)
			{
				q.push(node + 1);
				check[node + 1] = true;
				sec[node + 1] = sec[node] + 1;
			}
		}
		if (node * 2 <= MAX) // x * 2의 경우
		{
			if (check[node * 2] == false)
			{
				q.push(node * 2);
				check[node * 2] = true;
				sec[node * 2] = sec[node] + 1;
			}
		}
	}

	cout << sec[k] << '\n';
}

```
