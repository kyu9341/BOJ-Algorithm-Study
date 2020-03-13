# Problem 1981

## 배열에서 이동

### 문제
n×n짜리의 배열이 하나 있다. 이 배열의 (1, 1)에서 (n, n)까지 이동하려고 한다. 이동할 때는 상, 하, 좌, 우의 네 인접한 칸으로만 이동할 수 있다.

이와 같이 이동하다 보면, 배열에서 몇 개의 수를 거쳐서 이동하게 된다. 이동하기 위해 거쳐 간 수들 중 최댓값과 최솟값의 차이가 가장 작아지는 경우를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 n(2≤n≤100)이 주어진다. 다음 n개의 줄에는 배열이 주어진다. 배열의 각 수는 0보다 크거나 같고, 200보다 작거나 같은 정수이다.

### 출력
첫째 줄에 (최대 - 최소)가 가장 작아질 때의 그 값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1981>

### 예제 입력 1
5
1 1 3 6 8
1 2 2 5 5
4 4 0 3 3
8 0 2 3 4
4 3 0 2 1

### 예제 출력 1
2

### solve
- 이분 탐색을 이용하여 최대, 최소의 차이를 확인하며 현재 차이값으로 (0, 0)에서 (n-1, n-1)까지 이동이 가능한지 확인하면 된다.
- 이 때, 최대, 최소의 차이만으로는 모든 경우를 확인할 수 없다.
	- 따라서 현재 차이값에서 가능한 최대, 최솟값을 모두 확인하여 가능한 경우가 있는지를 판별한다.
	
### 코드 설명
```C++
#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<climits>

using namespace std;
const int MAX = 100;
int a[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int n;


bool bfs(int min, int max) // 현재 최대, 최솟값으로 (n-1,n-1)까지 이동 가능한지 확인하는 함수
{
	if (a[0][0] < min || a[0][0] > max) return false; // 범위를 벗어나면 false
	memset(check, false, sizeof(check));
	queue<pair<int, int>> q;
	check[0][0] = true;
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n)
			{
				if (!check[nx][ny])
				{
					if (a[nx][ny] <= max && a[nx][ny] >= min) // 최대 최소의 범위 내에서 이동
					{
						q.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}
		}
	}
	return check[n - 1][n - 1]; // (n-1,n-1)까지 이동 가능한지 판별
}

bool go(int mid)
{
	for (int i = 0; i + mid <= 200; i++) // 0부터 차이의 합이 200보다 작을 때까지
	{ // 차이가 mid인 모든 최대, 최소의 경우를 확인
		if (bfs(i, i + mid))
			return true;
	}
	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	int max = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (max < a[i][j]) max = a[i][j];
		}
	int right = max;
	int left = 0;
	int ans = max;

	while (left <= right) // 이분 탐색
	{
		int mid = (left + right) / 2;
		memset(check, false, sizeof(check));
		if (go(mid))
		{
			if (ans > mid)
				ans = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << ans << '\n';

}

```
