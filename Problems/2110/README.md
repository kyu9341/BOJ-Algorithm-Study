# Problem 2110

## 공유기 설치

### 문제
도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.

도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.

C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

### 입력
첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (1 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

### 출력
첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2110>

### 예제 입력 1
5 3
1
2
8
4
9

### 예제 출력 1
3

### solve
- 이분 탐색을 이용하여 인접한 두 공유기 사이의 거리를 탐색한다.
- 집의 좌표를 저장한 벡터에서 인접한 공유기 사이의 거리가 현재 간격(dist)이상인 경우가 c이상인지 판별한다.
  - 참이라면 현재 지정된 고유기의 간격을 ans에 저장하고 더 큰 값이 있는지 반복한다.
  - 아니라면 간격을 줄여 다시 탐색한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<int>& a, int c, int dist) // 인접한 공유기 사이의 거리가 현재 간격(dist)이상인 경우가 c이상인지 판별하는 함수
{
	int cnt = 1; // 가능한 간격 + 1개가 공유기의 개수
	int last = a[0];
	for(int house : a)
	{
		if (house - last >= dist) // 직전에 공유기를 배치했던 집과 거리 비교
		{
			cnt++;
			last = house; // 공유기를 배치한 이전 집을 저장
		}
	}
	return cnt >= c; // 현재 인접한 공유기 사이의 거리가 dist이상인 경우가 c개 이상이면 참
}

int main(void)
{
	int n, c;
	cin >> n >> c;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end()); // 오른차순 정렬

	int right = a[n - 1] - a[0]; // 가장 멀리 떨어진 두 집의 차이
	int left = 1;
	int ans = 1;

	while (left <= right)
	{
		int mid = (left + right) / 2; // 인접한 두 공유기의 거리
		if (check(a, c, mid))
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
