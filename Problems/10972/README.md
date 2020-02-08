# Problem 10972

## 다음 순열

### 문제
1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 다음에 오는 순열을 구하는 프로그램을 작성하시오.

사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.

N = 3인 경우에 사전순으로 순열을 나열하면 다음과 같다.

- 1, 2, 3
- 1, 3, 2
- 2, 1, 3
- 2, 3, 1
- 3, 1, 2
- 3, 2, 1

### 입력
첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄에 순열이 주어진다.

### 출력
첫째 줄에 입력으로 주어진 순열의 다음에 오는 순열을 출력한다. 만약, 사전순으로 마지막에 오는 순열인 경우에는 -1을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/10972>

### 예제 입력 1
4
1 2 3 4

### 예제 출력 1
1 2 4 3

### 예제 입력 2
5
5 4 3 2 1

### 예제 출력 2
-1

### solve
- A[i - 1] < A[i]를 만족하는 가장 큰 i를 찾는다
- j ≥ i 이면서 A[j] > A[i - 1]를 만족하는 가장 큰 j를 찾는다
- A[i-1]과 A[j]를 swap한다
- A[i]부터 순열을 뒤집는다

### 코드 설명
```C++

#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
using namespace std;

void next_permutation(vector<int> &a, int n)
{
	int i = n - 1; // 배열의 마지막 인덱스
	while (i >  0 && a[i] <= a[i - 1]) i--; // 내림차순이 되기 직전의 인덱스가 i가 됨.
	if (i == 0)
	{
		cout << -1; // 마지막 순열인 경우 -1
		return;
	}
	int j = n - 1;
	while (a[j] <= a[i - 1]) j--; // a[i] 보다 큰 가장 뒤쪽의 a[j]를 찾는다
	swap(a[i - 1], a[j]);
	j = n - 1;
	while (i < j) // i 뒤를 오른차순으로 정렬
	{
		swap(a[i], a[j]);
		i += 1;
		j -= 1;
	}

	for (int k = 0; k < n; k++)
		cout << a[k] << ' ';
	cout << '\n';
}

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	next_permutation(a, n);
}
```
