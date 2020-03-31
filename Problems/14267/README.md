# Problem 14267

## 내리 갈굼

### 문제
영선회사에는 치명적인 악습이 있는데, 바로 상사가 직속 부하를 갈구면 그 부하가 부하의 직속 부하를 연쇄적으로 갈구는 내리 갈굼이 있다. 즉, 상사가 한 직속 부하를 갈구면 그 부하의 모든 부하들이 갈굼을 당한다.

갈굼에 대해 정도에 대한 수치가 주어지는데, 이 수치 또한 부하들에게 똑같이 갈궈진다.

직속 상사와 직속 부하관계에 대해 주어지고, 갈굼에 대한 정보가 주어질 때, 각자 얼마의 갈굼을 당했는지 출력하시오.

### 입력
첫째 줄에는 회사의 직원 수 n명, 최초의 갈굼 횟수 m이 주어진다. 직원은 1번부터 n번까지 번호가 매겨져 있다. (2 ≤ n, m ≤ 100,000)

둘째 줄에는 직원 n명의 직속 상사의 번호가 주어진다. 직속 상사의 번호는 자신의 번호보다 작으며, 최종적으로 1번이 사장이다. 1번의 경우, 상사가 없으므로 -1이 입력된다.

다음 m줄에는 직속 상사로부터 갈굼을 당한 직원 번호 i,갈굼의 수치 w가 주어진다.(2 ≤ i ≤ n, 1 ≤ w ≤ 1,000) 사장은 상사가 없으므로 갈굼을 당하지 않는다.

### 출력
1번부터 n번의 직원까지 갈굼을 당한 정도를 출력하시오.

### 문제 링크
<https://www.acmicpc.net/problem/14267>

### 예제 입력 1
5 3
-1 1 2 3 4
2 2
3 4
5 6

### 예제 출력 1
0 2 6 6 12

### solve
- dfs로 갈굼 정도를 누적하여 부하에게 물려주면 된다.
- n제한이 10만이기 때문에 갈굼의 정도를 모두 저장 후 한번만 순회하면서 모두 물려주도록 한다.
- 같은 부하에게 여러번 갈구는 경우를 생각하지 않아서 계속 틀렸던 거였다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 100000;
int n, m;
vector<int> v[MAX + 1];
int cost[MAX + 1]; // 갈굼 횟수

void go(int now)
{
	for (int i = 0; i < v[now].size(); i++)
	{
		int next = v[now][i];
		cost[next] += cost[now]; // 갈굼 수치 누적
		go(next);
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		if (i == 1) continue; // -1은 건너뜀
		v[k].push_back(i);
	}
	while (m--)
	{
		int u, v;
		cin >> u >> v;
		cost[u] += v;// 갈굼 정도 저장
	}
	go(1); // 1번부터 dfs
	for (int i = 1; i <= n; i++)
		cout << cost[i] << ' ';
	cout << '\n';

}
```
