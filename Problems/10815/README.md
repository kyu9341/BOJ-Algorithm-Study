# Problem 10815

## 숫자 카드

### 문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있는지 아닌지를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이가 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다. 두 숫자 카드에 같은 수가 적혀있는 경우는 없다.

셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 가지고 있는 숫자 카드인지 아닌지를 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다

### 출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 가지고 있으면 1을, 아니면 0을 공백으로 구분해 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/10815>

### 예제 입력 1
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10

### 예제 출력 1
1 0 0 1 1 0 0 1

### solve
- 배열에 어떤 값이 존재하는지 찾는 문제이다.
- 이분 탐색을 이용하여 값의 유무만 파악하여 리턴하였다.


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

bool find(int num) // 이분 탐색으로 원소가 존재하는지 판단
{
	int left = 0;
	int right = n - 1;

	while (left <= right) // left > right 가 되면 종료
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			return true;
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

	return false;
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
		if (find(num))
			cout << '1';
		else
			cout << '0';
		if(i != m - 1)
			cout << ' ';
	}
	cout << '\n';
}

```
