# Problem 13397

## 구간 나누기 2

### 문제
N개의 수로 이루어진 1차원 배열이 있다. 이 배열을 M개 이하의 구간으로 나누어서 구간의 점수의 최댓값을 최소로 하려고 한다. 구간은 다음과 같은 조건을 만족해야 한다.

1. 하나의 구간은 하나 이상의 연속된 수들로 이루어져 있다.
2. 배열의 각 수는 모두 하나의 구간에 포함되어 있어야 한다.

구간의 점수란 구간에 속한 수의 최댓값과 최솟값의 차이이다.

예를 들어, 배열이 [1, 5, 4, 6, 2, 1, 3, 7] 이고, M = 3인 경우가 있다.

이때, [1, 5], [4, 6, 2], [1, 3, 7]로 구간을 나누면 각 구간의 점수는 4, 4, 6점이 된다. 이때, 최댓값은 6점이다.

만약, [1, 5, 4], [6, 2, 1], [3, 7]로 구간을 나누었다면, 각 구간의 점수는 4, 5, 4점이 되고, 이때 최댓값은 5점이 된다.

두 경우 중에서 최댓값이 최소인 것은 5점인 것이고, 5점보다 최댓값을 작게 만드는 방법은 없다.

배열과 M이 주어졌을 때, 구간의 점수의 최댓값의 최솟값을 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 배열의 크기 N과 M이 주어진다. (1 ≤ N ≤ 5,000, 1 ≤ M ≤ N)

둘째 줄에 배열에 들어있는 수가 순서대로 주어진다. 배열에 들어있는 수는 1보다 크거나 같고, 10,000보다 작거나 같은 자연수이다.

### 출력
첫째 줄에 구간의 점수의 최댓값의 최솟값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/13397>

### 예제 입력 1
8 3
1 5 4 6 2 1 3 7

### 예제 출력 1
5

### 예제 입력 2
4 2
1 1 1 1

### 예제 출력 2
0

### 예제 입력 3
7 4
1 2 3 1 2 3 1

### 예제 출력 3
2

### 예제 입력 4
5 1
1 100 99 2 3

### 예제 출력 4
99

### 예제 입력 5
5 2
1 100 99 2 3

### 예제 출력 5
98

### 예제 입력 6
5 3
1 100 99 2 3

### 예제 출력 6
1

### solve
- 현재 구간 점수를 인자로 넘겨받아 현재 구간 점수보다 크게 m개 이하의 구간으로 나눌 수 있는지 확인하는 함수를 만든다.
	- 그 점수 이상을 구간 점수를 가질 수 있도록 구간을 나눈다.
	- 나눈 구간의 수가 m개 이하라면 true, 아니면 false를 리턴한다.
- 구간 점수를 기준으로 이분 탐색을 하여 위 함수를 만족하는 최솟값을 구한다.


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
int n, m;

int gapMaxMin(vector<int>& k)
{
	auto p = minmax_element(k.begin(), k.end());
	return * p.second - * p.first;
}

bool calc(vector<int>& a, int mid)
{
	vector<int> tmp;
	int cnt = 1; // 구간의 개수(마지막 구간 + 1)
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(a[i]);
		int gap = gapMaxMin(tmp); // 구간 점수의 최댓값
		if (gap > mid) // 현재 구간 점수보다 큰 경우
		{
			cnt++; // 구간 수 + 1
			tmp.clear(); // 구간 초기화
			tmp.push_back(a[i]);
		}
	}
	return cnt <= m; // m개 이하의 구간으로 나눌 수 있는지
}

int main(void)
{
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int right = * max_element(a.begin(), a.end()); // 배열의 최댓값
	int left = 0;
	int ans = right;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (calc(a, mid)) // 가능한 경우
		{
			if(ans > mid)
				ans = mid;
			right = mid - 1; // 가능한 최솟값 확인
		}
		else
			left = mid + 1;

	}
	cout << ans << '\n';
}
```
