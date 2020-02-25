# Problem 1931

## 회의실 배정

### 문제
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의들에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 최대수의 회의를 찾아라. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

### 입력
첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

### 출력
첫째 줄에 최대 사용할 수 있는 회의 수를 출력하여라.

### 문제 링크
<https://www.acmicpc.net/problem/1931>

### 예제 입력 1
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

### 예제 출력 1
4

### solve
- 회의실에서 회의를 최대한 많이 하도록 만드는 문제이다.
- 이 문제는 그리디로 해결할 수 있는데, 기준을 회의가 끝나는 시간이 가장 빠른 순서대로 회의를 배치하면 된다.
- 회의가 끝나는 시간 순으로 정렬을 수행하여
	- 이전 회의가 끝난 시간과 다음 회의 시작을 시간 비교하여 시간이 맞다면
	- 현재 now에 저장된 회의가 끝난 시간을 갱신하고 회의의 수를 +1한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
struct Meeting
{
	int begin, end;
};
bool compare(Meeting u, Meeting v) // 비교 함수
{
	if (u.end == v.end) return u.begin < v.begin; // 끝나는 시간이 같다면 시작 시간순
	else return u.end < v.end; // 끝나는 시간이 빠른 순으로 정렬
}

int main(void)
{
	int n;
	cin >> n;
	vector<Meeting> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].begin >> a[i].end;
	}
	sort(a.begin(), a.end(), compare); // 회의가 끝나는 시간이 빠른 순으로 정렬

	int now = 0; // 회의가 끝난 시간
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (now <= a[i].begin) // 이전 회의가 끝난 시간과 다음 회의 시작 시간 비교
		{
			now = a[i].end; // 회의 끝난 시간 갱신
			ans++;
		}
	}
	cout << ans << '\n';
}

```
