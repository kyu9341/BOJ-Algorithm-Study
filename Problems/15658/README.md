# Problem 15658

## 연산자 끼워넣기 (2)

### 문제
N개의 수로 이루어진 수열 A1, A2, ..., AN이 주어진다. 또, 수와 수 사이에 끼워넣을 수 있는 연산자가 주어진다. 연산자는 덧셈(+), 뺄셈(-), 곱셈(×), 나눗셈(÷)으로만 이루어져 있다. 연산자의 개수는 N-1보다 많을 수도 있다. 모든 수의 사이에는 연산자를 한 개 끼워넣어야 하며, 주어진 연산자를 모두 사용하지 않고 모든 수의 사이에 연산자를 끼워넣을 수도 있다.

우리는 수와 수 사이에 연산자를 하나씩 넣어서, 수식을 하나 만들 수 있다. 이때, 주어진 수의 순서를 바꾸면 안 된다.

예를 들어, 6개의 수로 이루어진 수열이 1, 2, 3, 4, 5, 6이고, 주어진 연산자가 덧셈(+) 3개, 뺄셈(-) 2개, 곱셈(×) 1개, 나눗셈(÷) 1개인 경우에는 총 250가지의 식을 만들 수 있다. 예를 들어, 아래와 같은 식을 만들 수 있다.

- 1+2+3-4×5÷6
- 1÷2+3+4-5×6
- 1+2÷3×4-5+6
- 1÷2×3-4+5+6
- 1+2+3+4-5-6
- 1+2+3-4-5×6

식의 계산은 연산자 우선 순위를 무시하고 앞에서부터 진행해야 한다. 또, 나눗셈은 정수 나눗셈으로 몫만 취한다. 음수를 양수로 나눌 때는 C++14의 기준을 따른다. 즉, 양수로 바꾼 뒤 몫을 취하고, 그 몫을 음수로 바꾼 것과 같다. 이에 따라서, 위의 식 4개의 결과를 계산해보면 아래와 같다.

- 1+2+3-4×5÷6 = 1
- 1÷2+3+4-5×6 = 12
- 1+2÷3×4-5+6 = 5
- 1÷2×3-4+5+6 = 7
- 1+2+3+4-5-6 = -1
- 1+2+3-4-5×6 = -18

N개의 수와 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 수의 개수 N(2 ≤ N ≤ 11)가 주어진다. 둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 100) 셋째 줄에는 합이 N-1보다 크거나 같고, 4N보다 작거나 같은 4개의 정수가 주어지는데, 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)의 개수이다.

### 출력
첫째 줄에 만들 수 있는 식의 결과의 최댓값을, 둘째 줄에는 최솟값을 출력한다. 최댓값과 최솟값이 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과가 나오는 입력만 주어진다. 또한, 앞에서부터 계산했을 때, 중간에 계산되는 식의 결과도 항상 -10억보다 크거나 같고, 10억보다 작거나 같다.

### 문제 링크
<https://www.acmicpc.net/problem/15658>

### 예제 입력 1
2
5 6
1 1 1 1

### 예제 출력 1
30
-1

### 예제 입력 2
3
3 4 5
2 1 2 1

### 예제 출력 2
60
-5

### 예제 입력 3
6
1 2 3 4 5 6
3 2 1 1

### 예제 출력 3
72
-48

### solve
- 처음엔 순열을 이용하여 모든 연산자의 개수에서 n - 1개를 뽑아 모든 경우를 확인하였더니 시간초과가 난다. 최대 O(44C11 * 11)가 걸리니 당연한 결과였다.
- 방법을 바꾸어 4개의 연산자 중 1개를 뽑은 경우이니 최대 O(4^10)으로 해결이 가능하다. 각 연산자의 개수가 0보다 큰 경우 재귀를 수행한다.


### 코드 설명
- 처음 작성한 코드, 최대 O(44C11 * 11)로 시간 초과.
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
int op[4];
vector<int> oper;
vector<int> selected;
bool check[11];
int n;
int max_ans = 0;
int min_ans = INT_MAX;

int calc(vector<int>& a) // 현재 연산자 순서로 결과를 구하는 함수
{
	int res = a[0];
	for (int i = 1; i < n; i++)
	{
		if (selected[i - 1] == 0)
			res += a[i];
		if (selected[i - 1] == 1)
			res -= a[i];
		if (selected[i - 1] == 2)
			res * = a[i];
		if (selected[i - 1] == 3)
			res /= a[i];
	}
	return res;
}

void go(vector<int>& a, int index)
{
	if (index == n - 1) // 필요한 연산자의 개수가 구해지면
	{
		int res = calc(a);
		cout << res << ' ';
		if (max_ans < res) max_ans = res; // 최대
		if (min_ans > res) min_ans = res; // 최소
		return;
	}

	for (int i = 0; i < oper.size(); i++)
	{
		if (check[i]) continue; // 중복 제거
		check[i] = true;
		selected.push_back(oper[i]); // 연산자 추가
		go(a, index + 1);
		selected.pop_back();
		check[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
	{
		cin >> op[i];
		for (int j = 0; j < op[i]; j++) // 각 연산자를 개수대로 삽입
			oper.push_back(i);
	}
	go(a, 0);

	cout << max_ans << '\n';
	cout << min_ans << '\n';

}
```

- 정답 코드, 최대 O(4^10)
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
int op[4];
bool check[11];
int n;
int max_ans = -INT_MAX + 1; // 최댓값이 음수일수도 있음
int min_ans = INT_MAX;

void go(vector<int>& a, int index, int plus, int minus, int multi, int div, int res)
{
	if (index == n) // 필요한 연산자의 개수가 구해지면
	{
		if (max_ans < res) max_ans = res; // 최대
		if (min_ans > res) min_ans = res; // 최소
		return;
	}

	// 각 연산자의 수가 0보다 클 때, 재귀
	if (plus > 0) go(a, index + 1, plus - 1, minus, multi, div, res + a[index]);
	if (minus > 0) go(a, index + 1, plus, minus - 1, multi, div, res - a[index]);
	if (multi > 0) go(a, index + 1, plus, minus, multi - 1, div, res * a[index]);
	if (div > 0) go(a, index + 1, plus, minus, multi, div - 1, res / a[index]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];

	go(a, 1, op[0], op[1], op[2], op[3], a[0]);

	cout << max_ans << '\n';
	cout << min_ans << '\n';

}
```
