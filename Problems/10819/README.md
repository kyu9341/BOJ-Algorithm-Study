# Problem 10819

## 차이를 최대로

### 문제
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

	|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

### 입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

### 출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/10819>

### 예제 입력 1
6
20 1 15 8 4 10

### 예제 출력 1
62

### solve
- |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 를 구해주는 함수를 작성한다.
- next_permutation함수를 이용해 모든 경우를 탐색하며 최댓값을 구한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int calculation(vector<int>& a, int n);

int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	do
	{
		int temp = calculation(a, n); // 모든 경우를 탐색해 최댓값을 구한다.
		if (ans < temp)
			ans = temp;
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << '\n';
}

int calculation(vector<int>& a, int n) // |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| 를 구해주는 함수
{
	int result = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int temp = a[i] - a[i + 1];
		if (temp < 0) temp = -temp;
		result += temp;
	}
	return result;
}

```
