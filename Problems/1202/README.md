# Problem 1202

## 보석 도둑

### 문제
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.

상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.

상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)

다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)

다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)

모든 숫자는 양의 정수이다.

### 출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1202>

### 예제 입력 1
3 2
1 65
5 23
2 99
10
2

### 예제 출력 1
164

### solve
- 그리디 알고리즘으로 무게 제한이 작은 가방에 비싼 보석을 먼저 담아야 최대로 보석을 가져갈 수 있다.
- 보석을 가격이 비싼 순으로 정렬하고, 가방을 무게 제한이 낮은 순으로 정렬한다.
	- 이후 가격이 비싸고 가방에 담을 수 있는 순으로 모든 경우를 확인하며 계산하니 시간 초과가 발생한다.
	- O(nk)라는 시간 복잡도를 갖는데, 이것은 300000*300000 이므로 1억을 넘는다.

- 그래서 우선순위 큐를 사용하였다.
	- 보석과 가방 모두 무게를 기준으로 오름차순으로 정렬을 하고
	- 가방을 하나씩 확인하며 i번째 가방의 무게보다 작거나 같은 보석을 모두 우선순위 큐에 push한다.
	- 현재 우선순위 큐의 top()값(가장 비싼 보석의 가격)을 누적하고 pop()을한다.
- 이렇게 진행하면 매번 모든 보석을 확인하지 않고, 한번 큐에 넣은 보석은 다시 확인하지 않아도 된다.
- 따라서, 보석을 한 번씩만 확인하고 현재 가장 가벼운 가방에 들어갈 수 있는 가방 비싼 보석을 찾을 수 있다.

### 코드 설명
- 처음 작성한 코드이다. 시간복잡도 O(nk)로 시간 초과가 발생했다.
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<climits>

using namespace std;
const int MAX = 300000;

struct gem
{
	int weight, price;
};
bool compare(gem u, gem v)
{
	if (u.price == v.price) return u.weight < v.weight; // 가격이 같다면 무게가 작은 순서로
	else return u.price > v.price; // 가격에 대해 내림차순
}

int main(void)
{
	int n, k; // 보석의 개수, 가방의 개수
	cin >> n >> k;
	vector<gem> a(n);
	vector<int> c(k); // 가방의 최대 무게
	for (int i = 0; i < n; i++)
		cin >> a[i].weight >> a[i].price;

	for (int i = 0; i < k; i++)
		cin >> c[i];

	sort(a.begin(), a.end(), compare); // 가격이 비싼 순, 같다면 무게가 낮은 순
	sort(c.begin(), c.end()); // 가벼운 가방 순

	long long ans = 0;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[j].weight <= c[i])
			{
				ans += a[j].price;
				a[j].weight = INT_MAX;
				break;
			}
		}

	}
	cout << ans << '\n';
}

```
