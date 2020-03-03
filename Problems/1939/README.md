# Problem 1939

## 중량제한

### 문제
N(2≤N≤10,000)개의 섬으로 이루어진 나라가 있다. 이들 중 몇 개의 섬 사이에는 다리가 설치되어 있어서 차들이 다닐 수 있다.

영식 중공업에서는 두 개의 섬에 공장을 세워 두고 물품을 생산하는 일을 하고 있다. 물품을 생산하다 보면 공장에서 다른 공장으로 생산 중이던 물품을 수송해야 할 일이 생기곤 한다. 그런데 각각의 다리마다 중량제한이 있기 때문에 무턱대고 물품을 옮길 순 없다. 만약 중량제한을 초과하는 양의 물품이 다리를 지나게 되면 다리가 무너지게 된다.

한 번의 이동에서 옮길 수 있는 물품들의 중량의 최댓값을 구하는 프로그램을 작성하시오

### 입력
첫째 줄에 N, M(1≤M≤100,000)이 주어진다. 다음 M개의 줄에는 다리에 대한 정보를 나타내는 세 정수 A, B(1≤A, B≤N), C(1≤C≤1,000,000,000)가 주어진다. 이는 A번 섬과 B번 섬 사이에 중량제한이 C인 다리가 존재한다는 의미이다. 서로 같은 두 도시 사이에 여러 개의 다리가 있을 수도 있으며, 모든 다리는 양방향이다. 마지막 줄에는 공장이 위치해 있는 섬의 번호를 나타내는 서로 다른 두 정수가 주어진다. 공장이 있는 두 섬을 연결하는 경로는 항상 존재하는 데이터만 입력으로 주어진다.

### 출력
첫째 줄에 답을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1939>

### 예제 입력 1
3 3
1 2 2
3 1 3
2 3 2
1 3

### 예제 출력 1
3

### solve
- 제한되는 중량에 대해 이분 탐색을 수행하며 현재 중량을 만족하는 길이 있는지 확인한다.
- dfs를 통해 만족하는 길이 있는지 탐색하여 만족하는 길이 있다면 중량을 증가시키고 없다면 감소시켜 재탐색한다.


## 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;
const int MAX = 10000;
vector<pair<int, int>> a[MAX + 1];
bool check[MAX + 1]; // 방문 여부

bool dfs(int node, int weight, int target) // dfs를 통해 현재 중량 제한을 만족하는 길이 있는지 확인
{
	check[node] = true; // 방문 처리
	if (check[target]) return true;

	for (int i = 0; i < a[node].size(); i++) // 연결된 섬 모두 확인
	{
		int next = a[node][i].first;
		int w = a[node][i].second;
		if (!check[next] && w >= weight) // 중량 제한을 만족하고 방문하지 않은 경우
		{
			if (dfs(next, weight, target)) return true; // 목표 공장을 찾았다면 true리턴
		}
	}
	return false; // 모두 방문했지만 목표 공장을 찾지 못한 경우 false
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	int maxWeight = 0;
	for (int i = 0; i < m; i++) // 섬과 다리 입력
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
		if (maxWeight < w) // 중량 제한의 최댓값 저장
			maxWeight = w;
	}
	int start, end; // 출발 공장, 도착 공장
	cin >> start >> end;

	int left = 1;
	int right = maxWeight;
	int ans = 0;

	while (left <= right) // 이분 탐색
	{
		memset(check, false, sizeof(check)); // check배열 초기화
		int mid = (left + right) / 2; // 중량 제한
		if (dfs(start, mid, end)) // 현재 중량 제한을 만족하는 길이 있는 경우
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans << '\n';

}

```
