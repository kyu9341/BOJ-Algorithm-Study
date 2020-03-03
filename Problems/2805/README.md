# Problem 2805

## 나무 자르기

### 문제
상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기을 이용해서 나무를 구할것이다.

목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다)

상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M을 넘기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.

### 출력
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/2805>

### 예제 입력 1
4 7
20 15 10 17

### 예제 출력 1
15

### solve
- 절단기의 높이 h로 나무를 잘라서 m이상을 만들 수 있는지 확인하는 함수를 만들고
- 이분 탐색을 통해 현재 절단기의 높이로 나무의 길이 m을 만들 수 있는지 확인한다.
  - 가능하다면 현재 절단기 높이 저장하고 최댓값을 구해야하므로 더 높이 올릴 수 있는지 확인
  - 불가능하다면 절단기의 높이를 낮춘다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<long long>& a, long long m, long long h) // 절단기의 높이 h로 나무를 잘라서 m이상을 만들 수 있는지 확인하는 함수
{
	long long cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] - h > 0) // h 가 나무의 높이보다 높으면 잘리지 않음
		{
			cnt += a[i] - h;
		}
	}
	return cnt >= m; // 자른 나무의 길이의 합이 m이상이면 참
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;

	vector<long long> a(n);
	long long maxlen = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (maxlen < a[i])	maxlen = a[i];
	}

	long long left = 0;
	long long right = maxlen; // 나무 길이의 최댓값
	long long ans = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (check(a, m, mid)) // 현재 높이로 나무의 길이 m을 만들 수 있는지 확인
		{
			if (ans < mid)
				ans = mid; // 가능하다면 현재 절단기 높이 저장
			left = mid + 1; // 최댓값을 구해야하므로 더 높이 올릴 수 있는지 확인
		}
		else
		{
			right = mid - 1; // 불가능하다면 절단기 높이를 낮춤
		}
	}
	cout << ans << '\n';
}

```
