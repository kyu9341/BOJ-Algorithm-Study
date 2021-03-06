# Problem 15650

## N과 M (2)

### 문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
- 고른 수열은 오름차순이어야 한다.

### 입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

### 출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.

### 문제 링크
<https://www.acmicpc.net/problem/15650>

### 예제 입력 1
3 1

### 예제 출력 1
1
2
3

### 예제 입력 2
4 2

### 예제 출력 2
1 2
1 3
1 4
2 3
2 4
3 4

### 예제 입력 3
4 4

### 예제 출력 3
1 2 3 4

### solve
- N과 M(1)문제와 비슷하지만 오름차순으로 한 번씩만 출력하는 문제이다.
- 재귀 함수에 인자를 하나 추가하여 다음 반복을 시작할 수를 지정한다.
- 여기서는 check배열이 필요 없는데, 어떤 수를 채우고 다음 수를 이전 수 + 1부터 시작을 하기 때문에 이전에 사용한 수는 다시 사용하지 않는다.

### 코드 설명
```C++
#include<iostream>

using namespace std;
int a[10];
void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		go(index + 1, i + 1, n, m); // 다음 반복을 시작할 수를 지정
	}				// 항상 더 큰 수가 뒤에 옴
}

void go2(int index, int selected, int n, int m) // go2 : index라는 수를 결과에 포함할건지 말지를 결정
//  index : 실제 자연수 // selected : , 지금까지 선택한 수의 개수
{		
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > n) return; // index가 n보다 커지는 경우 리턴
	a[selected] = index;		// index를 결과에 추가하는 경우
	go2(index + 1, selected + 1, n, m);
	a[selected] = 0;			// index를 결과에 추가하지 않는 경우
	go2(index + 1, selected, n, m);
}


int main(void)
{
	int n, m;
	cin >> n >> m;

	go2(1, 0, n, m);
	// go(0, 1, n, m);
}```
