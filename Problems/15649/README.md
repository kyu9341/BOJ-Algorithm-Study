# Problem 15649

## N과 M (1)

### 문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

### 입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

### 출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

### 문제 링크
<https://www.acmicpc.net/problem/15649>

### 예제 입력 1
3 1

### 예제 출력 1
1
2
3

### 예제 입력 1
4 2

### 예제 출력 1
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3

### solve
- 1부터 N까지 자연수 중 중복 없이 M개를 뽑는 경우이므로 nPm과 같다.
- 반복문을 이용하여 푼다면 m중 for문이 필요할 것이다.
- 따라서 재귀를 이용하여 푼다.




### 코드 설명
```C++
#include<iostream>

using namespace std;
bool check[10]; // 사용한 수인지 체크
int a[10]; // 결과를 저장할 배열

void go(int index, int n, int m) // index : 0, 1, 2, .. , m - 1 까지 일때 현재 인덱스
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i]; // 출력
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i]) continue; // 중복 제거
		check[i] = true; // 이미 뽑은 것은 true
		a[index] = i;
		go(index + 1, n, m); // 인덱스를 1증가시키고 재귀
		check[i] = false;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	go(0, n, m);
}
```
