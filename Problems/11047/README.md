# Problem 11047

## 동전

### 문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.

동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)

둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

### 출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/11047>

### 예제 입력 1
10 4200
1
5
10
50
100
500
1000
5000
10000
50000

### 예제 출력 1
6

### solve
- 동전 A(i)가 A(i+1)의 배수이므로 그리디 알고리즘으로 해결이 가능하다.
- 가장 큰 가치의 동전으로 나눈 몫만큼 개수를 증가시키고, 목표 금액을 가장 큰 가치의 동전으로 나눈 나머지로 변경하며 반복한다.

### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	reverse(a.begin(), a.end());

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (k / a[i] > 0)
		{
			cnt += k / a[i]; // 가장 큰 가치의 동전으로 나눈 몫만큼 증가
			k %= a[i];  // 나눈 나머지를 저장
		}
	}

	cout << cnt << '\n';
}
```
