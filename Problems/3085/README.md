# Problem 3085

## 사탕 게임

### 문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.

가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

### 입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)

다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.

사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

### 출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/3085>

### 예제 입력 1
5
YCPZY
CYZZP
CCPPP
YCYZC
CPPZZ

### 예제 출력 1
4

### solve
- n*n크기의 보드가 주어졌을때 인접한 사탕의 위치를 바꾸는 모든 경우는 (1, 1)부터 (n, n)까지
- 모든 사탕을 한번 씩 우측의 사탕과 한 번, 아래의 사탕과 한 번 바꾸어 확인하면 된다.
- 가장 긴 사탕의 연속 부분을 리턴시켜줄 check함수를 만든다.
	- 가로 부분과 세로 부분을 나누어 가로로, 세로로 가장 긴 같은 색깔의 사탕 개수의 모든 경우를 구하여 최댓값을 리턴한다.
- 메인 함수에서는 string형 벡터를 선언하여 입력을 받아 2차원 배열처럼 사용한다.
- 모든 사탕을 우측, 아래쪽으로 각각 한번씩 확인하며 모든 사탕을 확인하면 되기 때문에
- 우측과 swap함수를 이용하여 값을 바꾼 후 최대의 같은 색깔의 사탕 길이를 받고 현재 최댓값과 비교한다.
- 이후 다시 swap을 이용하여 원래 상태로 돌려 놓고 다음 단계를 반복한다.

### 코드 설명
```C++
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int check(vector<string>& v) // 가장 긴 사탕의 연속 부분을 리턴
{
	int n = v.size();
	int ans = 1;
	// 먼저 가로 부분을 체크
	for (int i = 0; i < n; i++)
	{
		int cnt = 1; // 초기값
		for (int j = 1; j < n; j++)
		{
			if (v[i][j] == v[i][j - 1])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt) // 비교를 반복문 안에서 수행해야 함
				ans = cnt;
		}
		cnt = 1;
		// 다음 세로 부분 체크
		for (int j = 1; j < n; j++)
		{
			if (v[j][i] == v[j - 1][i])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt)
				ans = cnt;
		}
	}
	return ans;
}

int main(void)
{
	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = check(v);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	// 가로로 바꾸어 보며 최댓값을 구한다.
			if (j + 1 < n) // 가로 범위를 넘지 않는 한에서
			{
				swap(v[i][j], v[i][j + 1]); // 우측에 있는 값과 교환
				int temp = check(v);
				swap(v[i][j], v[i][j + 1]); // 다시 되돌려 놓는다.
				if (ans < temp)
					ans = temp;
			}
			// 세로로 바꾸어 보며 최댓값을 구한다.
			if (i + 1 < n) // 세로 범위를 넘지 않는 한에서
			{
				swap(v[i][j], v[i + 1][j]);
				int temp = check(v);
				swap(v[i][j], v[i + 1][j]);
				if (ans < temp)
					ans = temp;
			}
		}

	}

	cout << ans << '\n';

}
```
