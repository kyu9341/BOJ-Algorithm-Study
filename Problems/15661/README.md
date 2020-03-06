# Problem 15661

## 링크와 스타트

### 문제
오늘은 스타트링크에 다니는 사람들이 모여서 축구를 해보려고 한다. 축구는 평일 오후에 하고 의무 참석도 아니다. 축구를 하기 위해 모인 사람은 총 N명이다. 이제 스타트 팀과 링크 팀으로 사람들을 나눠야 한다. 두 팀의 인원수는 같지 않아도 되지만, 한 명 이상이어야 한다.

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
첫째 줄에 N(4 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에 S가 주어진다. 각 줄은 N개의 수로 이루어져 있고, i번 줄의 j번째 수는 Sij 이다. Sii는 항상 0이고, 나머지 Sij는 1보다 크거나 같고, 100보다 작거나 같은 정수이다.

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
- 스타트와 링크 문제와 거의 똑같지만 인원을 똑같이 나누지 않는 점이 다르다.
- index가 n과 같아지면 답을 구한 경우이므로 현재 팀별 인원이 저장된 벡터에서 각 팀의 능력치의 차를 구해 리턴한다.
	- 이 때, 한팀의 인원 수가 0이라면 잘못된 경우이므로 -1을 리턴시킨다.
- index번째 사람을 첫 번째 팀에 들어가는 경우와 두 번째 팀에 들어가는 경우를 나누어 재귀를 수행한다.

```C++
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
const int MAX = 20;
int s[MAX + 1][MAX + 1];

int select(int n, int index, vector<int> &a, vector<int> &b)
{

	if (index == n) // 정답을 구한 경우
	{
		if (a.size() == 0 || b.size() == 0) // 팀에는 최소 한 명이상 있어야 함.
			return -1;

		int diff = -1;
		int teamA = 0;
		int teamB = 0;
		if (a.size() == 1)  teamA = a[0]; // 팀원이 한명인 경우
		else
		{
			for (int i = 0; i < a.size(); i++)
				for(int j = 0; j < a.size(); j++)
				teamA += s[a[i]][a[j]]; // 같은 팀에 속했을 때의 더해지는 능력치 누적
		}
		if (b.size() == 1)  teamB = b[0]; // 팀원이 한명인 경우
		else
		{
			for (int i = 0; i < b.size(); i++)
				for(int j = 0; j < b.size(); j++)
				teamB += s[b[i]][b[j]]; // 같은 팀에 속했을 때의 더해지는 능력치 누적
		}
		diff = teamA - teamB;
		if (diff < 0) diff = -diff;

		return diff;
	}

	int ans = -1;
	a.push_back(index); // index번째 사람을 a팀에 넣는 경우
	int resA = select(n, index + 1, a, b);
	if (ans == -1 || (resA != -1 && resA < ans)) // 잘못된 경우가 아닐때, 최솟값을 구한다.
		ans = resA;
	a.pop_back(); // 한 명을 뺀다

	b.push_back(index); // index번째 사람을 b팀에 넣는 경우
	int resB = select(n, index + 1, a, b);
	if (ans == -1 || (resB != -1 && resB < ans))
		ans = resB;
	b.pop_back();

	return ans;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	vector<int> a;
	vector<int> b;

	int ans = select(n, 0, a, b);
	cout << ans << '\n';
}

```
