# Problem 11055

## 가장 큰 증가하는 부분 수열(BIS)

### 문제
수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 경우에 합이 가장 큰 증가 부분 수열은 A = {**1**, 100, **2**, **50**, **60**, 3, 5, 6, 7, 8} 이고, 합은 113이다.

### 입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

### 출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/11055>

### 예제 입력 1
10
1 100 2 50 60 3 5 6 7 8

### 예제 출력 1
113

### solve
- d[i] = a[1], ... a[i] 까지 있을 때, a[i]를 가장 마지막으로 하는 BIS의 합
	- = d[n] = a[1]...a[n] 까지의 a[n]이 마지막 수인 증가 부분 수열의 합
- i보다 작은 BIS합 중에서 가장 큰 BIS합에 a[i]을 더하면 d[i] = d[j] + a[i]
- 모든 d[i] 중 최댓값을 구한다.

### 코드 설명
```C++
#include<iostream>
#include<algorithm>
using namespace std;
int a[1001];
int d[1001]; // d[n] = a[1]...a[n] 까지의 a[n]이 마지막 수인 증가 부분 수열의 합
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int i = 1; i <= n; i++)
	{
		d[i] = a[i]; // 각 값의 초기값은 a[i]
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j] && d[i] < d[j] + a[i]) // 증가하는 경우이면서 현재 인덱스의 값보다 크다면
			{
				d[i] = d[j] + a[i]; // d[i]에 이어지는 이전의 증가 수열에 현재 값을 더해 저장(가장 긴 BIS에 현재 값을 더함)
			}
		}
	}
	int maxSum = 0;
	for (int i = 1; i <= n; i++)
		maxSum = max(maxSum, d[i]);
	cout << maxSum << '\n';
}
```
