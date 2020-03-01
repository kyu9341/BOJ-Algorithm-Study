# Problem 11728

## 배열 합치기

### 문제
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

### 입력
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)

둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

### 출력
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/11728>

### 예제 입력 1
2 2
3 5
2 9

### 예제 출력 1
2 3 5 9

### 예제 입력 2
2 1
4 7
1

### 예제 출력 2
1 4 7

### 예제 입력 3
4 3
2 3 5 9
1 4 7

### 예제 출력 3
1 2 3 4 5 7 9

### solve
- 정렬된 두 배열을 합치며 정렬하는 문제이다.
- merge sort의 merge 부분을 구현하면 된다.
- 이미 정렬된 두 배열이기 때문에 각 배열의 첫 원소부터 비교하여 더 작은 원소를 먼저 결과 배열에 삽입하고 인덱스를 증가시킨다.
- 하나의 배열이 먼저 마지막 원소까지 확인이 끝나므로 나머지 하나의 배열의 남은 원소를 결과 배열의 맨 뒤에 순서대로 삽입한다.

### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 1000000;
int a[MAX];
int b[MAX];
int res[MAX * 2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int idx_res = 0; // res의 인덱스
	int idx_a = 0, idx_b = 0; // a와 b의 인덱스

	while (idx_a < n && idx_b < m) // a와 b 중 하나가 모두 확인했다면 나온다.
	{
		if (a[idx_a] < b[idx_b]) // a와 b의 원소 중 작은 것을 먼저 res에 저장
			res[idx_res++] = a[idx_a++];
		else
			res[idx_res++] = b[idx_b++];
	}

	while (idx_a < n) // 아직 a와 b중 모든 원소를 확인하지 못한 배열은 나머지 원소를 그대로 res에 삽입
		res[idx_res++] = a[idx_a++]; // 이미 정렬된 a, b이므로
	while (idx_b < m)
		res[idx_res++] = b[idx_b++];

	for (int i = 0; i < idx_res; i++)
		cout << res[i] << ' ';
	cout << '\n';

}

```
