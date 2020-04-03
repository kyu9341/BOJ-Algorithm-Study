# Problem 12970

## AB

### 문제
정수 N과 K가 주어졌을 때, 다음 두 조건을 만족하는 문자열 S를 찾는 프로그램을 작성하시오.

- 문자열 S의 길이는 N이고, 'A', 'B'로 이루어져 있다.
- 문자열 S에는 0 ≤ i < j < N 이면서 s[i] == 'A' && s[j] == 'B'를 만족하는 (i, j) 쌍이 K개가 있다.

### 입력
첫째 줄에 N과 K가 주어진다. (2 ≤ N ≤ 50, 0 ≤ K ≤ N(N-1)/2)

### 출력
첫째 줄에 문제의 조건을 만족하는 문자열 S를 출력한다. 가능한 S가 여러 가지라면, 아무거나 출력한다. 만약, 그러한 S가 존재하지 않는 경우에는 -1을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/12970>

### 예제 입력 1
3 2

### 예제 출력 1
ABB

### 예제 입력 2
2 0

### 예제 출력 2
BA

### 예제 입력 2
5 8

### 예제 출력 2
-1

### 예제 입력 3
10 12

### 예제 출력 3
BAABBABAAB

### solve
- A와 B의 개수를 각각 a, b라고 했을때, 만족하는 쌍의 개수는 0 ~ a * b개가 된다.
- 여기서 주어진 k개 만큼 쌍을 가지도록 문자열을 만들기 위해서는 먼저 주어진 문자열의 크기만큼 모두 B로 채우고,
- k가 a * b보다 작거나 같을 때까지 a, b를 조정한다.
- 작거나 같아진다면 앞에서부터 a - 1개까지 A로 채운다.
	- 예를 들어, 입력이 7 11 이라면 a = 3, b = 4 일때 만족하므로
	- AABBBBB와 같은 상태로 문자열을 만든다.
	- 여기서 맨 마지막 문자를 A로 바꾼다면 AABBBBA가 될 것이다.
	- 이 상태에서 쌍의 개수는 (a - 1) * b개가 되고 이 값을 k에서 빼면 남은 필요한 쌍의 개수가 된다.
		- (이 값을 r이라고 한다.)
	- AABBBBA에서 마지막 A를 한 칸씩 왼쪽으로 이동시킬 때마다 필요한 쌍의 개수가 1씩 증가한다.
	- 즉, 마지막 A를 왼쪽으로 r만큼 이동시키면 k개의 쌍을 구할 수 있다.
- 위와 같이 그리디 방식으로 문제를 해결하였다.
---
- 조건을 만족하는 문자열이 있으려면 최대 (n/2 * (n - n/2)) 보다 작아야 한다.
	- 가장 많은 쌍을 가지는 경우가 A와 B가 절반 씩 있는 경우이다.
- 먼저 주어진 문자열의 크기만큼 모두 B로 채운다.
- k가 0인 경우 예외처리를 해준다. (그냥 맨 마지막 문자를 A로 바꿔서 처리했다.)


### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

int countAB(string ab) // 디버깅용 AB개수 체크
{
	int ans = 0;
	for (int i = 0; i < ab.size(); i++)
	{
		if (ab[i] == 'A')
		{
			for (int j = i;j < ab.size(); j++)
			{
				if (ab[j] == 'B')
					ans++;
			}
		}
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int m = n / 2;

	if (k > m * (n - m))
	{
		cout << -1 << '\n';
		return 0;
	}

	string ab = "";
	for (int i = 0; i < n; i++) // B로 모두 채운다.
		ab += 'B';

	if (k == 0) // 0일 때 예외 처리
	{
		ab[n - 1] = 'A';
		cout << ab << '\n';
		return 0;
	}

	int b = n; // A, B의 개수 초기화
	int a = 0;
	while (true)
	{
		if (a * b >= k)
		{
			for (int i = 0; i < a - 1; i++) // 앞에서부터 A의 개수 - 1 개를 A로 채운다.
				ab[i] = 'A';

			int c = (a - 1) * b; // A의 개수 - 1 * B의 개수를 저장 (마지막에 들어갈 A를 제외한 개수)
			int r = k - c; // 마지막 A를 이용하여 채워야할 쌍의 개수
			ab[(n - 1) - r] = 'A'; // 마지막 인덱스에서 r개 앞에 A를 넣는다.

			break;
		}
		else
		{
			b--; // A, B의 개수 조정
			a++;
		}
	}

	cout << ab << '\n';

}
```
