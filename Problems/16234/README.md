# Problem 16234

## 인구 이동

### 문제
N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다. 인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.

오늘부터 인구 이동이 시작되는 날이다.

인구 이동은 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

- 국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 연다.
- 위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
- 국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
- 연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
- 연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 몇 번 발생하는지 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)

둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)

인구 이동이 발생하는 횟수가 2,000번 보다 작거나 같은 입력만 주어진다.

### 출력
인구 이동이 몇 번 발생하는지 첫째 줄에 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/16234>

### 예제 입력 1
2 20 50
50 30
20 40
### 예제 출력 1
1

### 예제 입력 2
2 40 50
50 30
20 40
### 예제 출력 2
0

### 예제 입력 3
2 20 50
50 30
30 40
### 예제 출력 3
1

### 예제 입력 4
3 5 10
10 15 20
20 30 25
40 22 10
### 예제 출력 4
2

### 예제 입력 5
4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
### 예제 출력 5
3

### solve
- dfs를 통해 현재 국경을 공유하는 나라를 하나의 그룹으로 연합의 그룹번호를 매긴다.
- 이후 각 그룹에 속하는 나라의 수를 cnt에 카운트하고, 각 그룹의 속하는 나라의 인구수의 합을 sum에 저장한다.
- 또한 벡터v에 같은 그룹에 해당하는 나라끼리 좌표를 저장한다.
- cnt[k]가 2이상이라면 k그룹에 속한 나라끼리 국경을 공유했다는 뜻이 된다.
	- 따라서, cnt[k]가 2이상인 경우 v[k]에 저장된 각 나라의 좌표에 접근하여 (sum[k] / cnt[k])를 통해 인구 이동을 계산한다.
	- 이때, 계산 후에 벡터를 초기화한다.
- 반복문이 1회 반복될 때마다 인구 이동 횟수를 카운트한다.
- 국경을 공유하는 나라가 더 이상 없다면 반복문을 빠져나가고 종료한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;
const int MAX = 10000;
int a[51][51];
int group[51][51];
int cnt[MAX + 1]; // 각 그룹에 속하는 나라의 수
int sum[MAX + 1]; // 각 그룹의 속하는 나라의 인구수의 합
int n, l, r;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0 , 0 };
vector<pair<int, int>> v[MAX + 1];
void dfs(int x, int y, int num) // dfs를 통해 연합의 그룹번호를 매긴다.
{
	if (group[x][y] != 0) return;
	group[x][y] = num;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < n)
		{
			int gap = a[x][y] - a[nx][ny];
			if (gap < 0) gap = -gap;
			if (gap >= l && gap <= r) //  나라의 인구 차이가 L명 이상, R명 이하라면
			{
				dfs(nx, ny, num); // 같은 그룹으로 묶는다.
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int ans = 0;
	while (true)
	{
		memset(group, 0, sizeof(group)); // 그룹 번호 초기화
		int num = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (group[i][j] == 0) // 그룹에 속하지 않는 나라인 경우
				{
					dfs(i, j, ++num);
				}
			}

		memset(cnt, 0, sizeof(cnt)); // 각 그룹에 속하는 나라의 수 초기화
		memset(sum, 0, sizeof(sum)); // 각 그룹의 속하는 나라의 인구수의 합 초기화
		for(int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cnt[group[i][j]]++;
				sum[group[i][j]] += a[i][j];
				v[group[i][j]].push_back(make_pair(i, j)); // 같은 그룹에 해당하는 나라의 좌표를 저장
			}

		bool check = true; // 국경선을 공유하는 나라가 있는지 판별
		for (int k = 1; k <= MAX; k++) // 경우는 1부터 10000까지
		{
			if (cnt[k] >= 2) // 그룹에 속한 나라의 수가 2이상이면 국경을 공유한 것.
			{
				for (int i = 0; i < v[k].size(); i++)
				{
					int x = v[k][i].first;
					int y = v[k][i].second;

					a[x][y] = sum[k] / cnt[k]; // 인구 이동 계산

				}
				check = false;
			}
			v[k].clear(); // 벡터 초기화
		}

		if (check) break; // 국경을 공유하는 나라가 없다면 종료
		ans++; // 인구 이동 횟수 카운트

	}

	cout << ans << '\n';

}

```
