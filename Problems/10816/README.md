# Problem 10816

## 숫자 카드 2

### 문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이가 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

### 출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다.


### 문제 링크
<https://www.acmicpc.net/problem/10816>

### 예제 입력 1
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

### 예제 출력 1
3 0 0 1 2 0 0 2

### solve
- 배열에 어떤 값이 몇 개 존재하는지 찾는 문제이다.
- 이분 탐색으로 Lower Bound와 Upper Bound를 구현하여 Upper Bound - Lower Bound를 구하면 된다.
- Lower Bound는 어떤 수보다 크거나 같은 수 중 첫 번째 수의 인덱스를 리턴하고
	- binary_search에서 중앙 값이 찾는 값과 같아진 경우 찾았다고 true를 리턴하는 대신 lower bound에서는 left가 right보다 커질 때까지 right를 mid왼쪽으로 이동시켜 ans에 크거나 같은 첫 번째 수의 인덱스를 저장한다.
- Upper Bound는 어떤 수보다 큰 수 중 첫 번째 수의 인덱스를 리턴한다.
	- upper bound에서는 left가 right보다 커질 때까지 left를 mid오른쪽으로 이동시켜 ans에 num보다 큰 첫 번째 수의 인덱스를 저장한다.

### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 500000;
int a[MAX];
int n, m; // 가지고 있는 카드의 개수 n, 찾아야 할 카드의 개수 m

int lower_bound(int num) // 크거나 같은 수 중 첫 번째 수
{
	int ans = 0;
	int left = 0;
	int right = n - 1;

	while (left <= right) // left > right 가 되면 종료
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			ans = mid;
			right = mid - 1; // 크거나 같은 첫번째 수를 찾기 위해 왼쪽으로 이동
		}
		else if (a[mid] > num) // 중간 원소보다 작으면 오른쪽 절반을 날림
		{
			right = mid - 1;
		}
		else if (a[mid] < num) // 중간 원소보다 크면 왼쪽 절반을 날림
		{
			left = mid + 1;
		}
	}

	return ans;
}

int upper_bound(int num) // num보다 큰 수 중 첫번째 수
{
	int left = 0;
	int right = n - 1;
	int ans = 0;

	while (left <= right) // left > right 가 되면 종료
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			ans = mid + 1;
			left = mid + 1; // 큰 수 중 첫번째 수를 찾기 위해 오른쪽으로 이동
		}
		else if (a[mid] < num)
		{
			left = mid + 1;
		}
		else if (a[mid] > num)
		{
			right = mid - 1;
		}
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		cout << upper_bound(num) - lower_bound(num);
		if (i != m - 1)
			cout << ' ';
	}
	cout << '\n';
}

```
