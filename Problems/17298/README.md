# Problem 17298

## 오큰수

### 문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오큰수 NGE(i)를 구하려고 한다. Ai의 오큰수는 오른쪽에 있으면서 Ai보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오큰수는 -1이다.

예를 들어, A = [3, 5, 2, 7]인 경우 NGE(1) = 5, NGE(2) = 7, NGE(3) = 7, NGE(4) = -1이다. A = [9, 5, 4, 8]인 경우에는 NGE(1) = -1, NGE(2) = 8, NGE(3) = 8, NGE(4) = -1이다.

### 입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

### 출력
총 N개의 수 NGE(1), NGE(2), ..., NGE(N)을 공백으로 구분해 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/17298>

### 예제 입력 1
4
3 5 2 7

### 예제 출력 1
5 7 7 -1

### 예제 입력 2
4
9 5 4 8

### 예제 출력 2
-1 8 8 -1

### solve
- vector a에 입력받은 수열을 넣고 vector res에는 a의 각 값에 대한 오큰수를 넣는다.
- stack s에는 vector a에서 다음 원소와 비교하여 아직 오큰수를 찾지 못한 수의 인덱스가 쌓인다.
- 스택이 비어있다면 현재 인덱스를 먼저 push한다
- 이후 비어있지 않고 현재 a의 원소a[i]가 스택의 가장 위에 있는 인덱스를 가지는 원소(a[s.top()])와 비교하여 더 크다면 a[i] 는 a[s.top()]의 오큰수이므로 res[s.top()]에 저장한다. 이후 pop을 수행한다.(반복문 내에서 조건하에 계속 반복)
-  오큰수를 아직 확인하지 못한 수(=현재 수열의 원소 because 다음번에 확인 가능하므로)의 인덱스를 push
- 위의 과정의 반복이 끝나고 스택에 남아있는 수들은 오큰수를 구하지 못한 수 이므로 -1로 처리

### 코드 설명
```C++
#include<iostream>
#include<stack>
#include<vector>

using namespace std;
/*
	현재 수 보다 큰 수면서 오른쪽으로 가장 가까운 수 = 오큰수
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	stack<int> s; // 다음 수가 오큰수가 아닌 수의 인덱스를 담을 스택

	cin >> n;
	vector<int> a(n);
	vector<int> res(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	s.push(0); // 첫번째 원소 0으로 초기화
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
		{
			s.push(i); // 스택이 비어있다면 현재 인덱스를 push
		}
		while (!s.empty() && a[i] > a[s.top()]) // 스택이 비어있지 않고 현재 수열의 원소가 아직 오큰수를 구하지 못한 수보다 크면
		{
			res[s.top()] = a[i]; // a[s.top()]의 오큰수는 a[i]
			s.pop();
		}
		s.push(i); // 오큰수를 아직 확인하지 못한 수(=현재 수열의 원소 because 다음번에 확인 가능하므로)의 인덱스를 push
	}
	while (!s.empty()) // 위의 과정이 끝나고 오큰수를 구하지 못한 수들은 -1
	{
		res[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
	{
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}

```
