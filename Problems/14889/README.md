# Problem 1939

## 중량제한

### 문제
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이고 신기하게도 N은 짝수이다. 이제 N/2명으로 이루어진 스타트 팀과 링크 팀으로 사람들을 나눠야 한다.

BOJ를 운영하는 회사 답게 사람에게 번호를 1부터 N까지로 배정했고, 아래와 같은 능력치를 조사했다. 능력치 Sij는 i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치이다. 팀의 능력치는 팀에 속한 모든 쌍의 능력치 Sij의 합이다. Sij는 Sji와 다를 수도 있으며, i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치는 Sij와 Sji이다.

N=4이고, S가 아래와 같은 경우를 살펴보자.

i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5	 

예를 들어, 1, 2번이 스타트 팀, 3, 4번이 링크 팀에 속한 경우에 두 팀의 능력치는 아래와 같다.

- 스타트 팀: S12 + S21 = 1 + 4 = 5
- 링크 팀: S34 + S43 = 2 + 5 = 7
1, 3번이 스타트 팀, 2, 4번이 링크 팀에 속하면, 두 팀의 능력치는 아래와 같다.

- 스타트 팀: S13 + S31 = 2 + 7 = 9
- 링크 팀: S24 + S42 = 6 + 4 = 10

축구를 재미있게 하기 위해서 스타트 팀의 능력치와 링크 팀의 능력치의 차이를 최소로 하려고 한다. 위의 예제와 같은 경우에는 1, 4번이 스타트 팀, 2, 3번 팀이 링크 팀에 속하면 스타트 팀의 능력치는 6, 링크 팀의 능력치는 6이 되어서 차이가 0이 되고 이 값이 최소이다.

### 입력
첫째 줄에 N(4 ≤ N ≤ 20, N은 짝수)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.


### 출력
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이의 최솟값을 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/14889>

### 예제 입력 1
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0

### 예제 출력 1
0

### 예제 입력 2
6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0

### 예제 출력 2
2

### 예제 입력 3
8
0 5 4 5 4 5 4 5
4 0 5 1 2 3 4 5
9 8 0 1 2 3 1 2
9 9 9 0 9 9 9 9
1 1 1 1 0 1 1 1
8 7 6 5 4 0 3 2
9 1 9 1 9 1 0 9
6 5 4 3 2 1 9 0

### 예제 출력 3
1

### solve
- 재귀를 통해 index번째 사람이 스타트 팀에 가는 경우, 링크 팀에 가는 경우를 나누어 브루트 포스로 해결하였다.
- index가 n과 같아지면 답을 구한 경우이므로 현재 팀별 인원이 저장된 벡터에서 각 팀의 능력치의 차를 구해 리턴한다.
	- 이 때, 각 팀원의 수가 n / 2가 아니라면 잘못된 경우이므로 -1을 리턴시킨다.
- index번째 사람을 첫 번째 팀에 들어가는 경우와 두 번째 팀에 들어가는 경우를 나누어 재귀를 수행한다.

```C++
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int s[21][21]; // 인원 별 능력치
int n; // 전체 인원 수
int go(int index, vector<int>& first, vector<int>& second) // index : 현재 인덱스, first : 첫번째 팀, second : 두번째 팀
{
	if (index == n) // 답을 구한 경우
	{
		if (first.size() != n / 2) return -1; // 잘못된 경우라면 -1 리턴
		if (second.size() != n / 2) return -1;
		int t1 = 0; // 팀 별 능력치 합계
		int t2 = 0;
		for(int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++)
			{
				if (i == j) continue;
				t1 += s[first[i]][first[j]]; // 첫번째 팀의 s[i][j], s[j][i]를 모두 더함
				t2 += s[second[i]][second[j]];
			}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;

		return diff;
	}
	int ans = -1;
	first.push_back(index); // index번째 사람을 첫 번째 팀에 들어가는 경우
	int t1 = go(index + 1, first, second);
	if (ans == -1 || (t1 != -1 && t1 < ans))
	{
		ans = t1;
	}
	first.pop_back();
	second.push_back(index); // 두 번째 팀에 들어가는 경우
	int t2 = go(index + 1, first, second);
	if (ans == -1 || (t2 != -1 && t2 < ans))
	{
		ans = t2;
	}
	second.pop_back();
	return ans;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	vector<int> first, second;
	cout << go(0, first, second) << '\n';
}
```
