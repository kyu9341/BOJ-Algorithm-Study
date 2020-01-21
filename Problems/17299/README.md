# Problem 17299

## 우등큰수

### 문제
크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오등큰수 NGF(i)를 구하려고 한다.

Ai가 수열 A에서 등장한 횟수를 F(Ai)라고 했을 때, Ai의 오등큰수는 오른쪽에 있으면서 수열 A에서 등장한 횟수가 F(Ai)보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다. 그러한 수가 없는 경우에 오등큰수는 -1이다.

예를 들어, A = [1, 1, 2, 3, 4, 2, 1]인 경우 F(1) = 3, F(2) = 2, F(3) = 1, F(4) = 1이다. A1의 오른쪽에 있으면서 등장한 횟수가 3보다 큰 수는 없기 때문에, NGF(1) = -1이다. A3의 경우에는 A7이 오른쪽에 있으면서 F(A3=2) < F(A7=1) 이기 때문에, NGF(3) = 1이다. NGF(4) = 2, NGF(5) = 2, NGF(6) = 1 이다.

### 입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

### 출력
총 N개의 수 NGF(1), NGF(2), ..., NGF(N)을 공백으로 구분해 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/17299>

### 예제 입력 1
7
1 1 2 3 4 2 1

### 예제 출력 1
-1 -1 1 2 2 1 -1

### solve
- 우큰수 문제와 완전히 비슷하게 가지만 비교하는 기준만 원소의 크기에서 수열 내의 원소의 총 개수로 변경하여 해결

### 코드 설명
```C++
#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	int n; // 수열의 크기
	int count[1000001] = {0}; // 각 수열의 원소의 개수를 카운트할 배열

	cin >> n;

	vector<int> a(n);
	vector<int> res(n);
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		count[a[i]]++;
	}

	s.push(0); // 스택
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
			s.push(i);
		while (!s.empty() && count[a[i]] > count[a[s.top()]]) // 원소의 개수로 비교 - 스택의 top원소의 인덱스 보다 크면
		{
			res[s.top()] = a[i]; // 우등큰수이므로 저장
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty())
	{
		res[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << '\n';

	return 0;
}

```
