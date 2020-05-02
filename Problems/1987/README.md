# Problem 1987

## 알파벳

### 문제
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.

말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.

좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

### 입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

### 출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다.

### 문제 링크
<https://www.acmicpc.net/problem/1987>

### 예제 입력 1
2 4
CAAB
ADCB

### 예제 출력 1
3

### solve
- map에 모든 알파벳 대문자를 키로, 벨류를 false로 초기화한다.
- dfs를 수행하며 현재까지 어떤 칸을 지나왔는지 체크하고, 아직 한 번도 지나오지 않은 알파벳인 경우에만 이동한다.
- cnt로 현재까지 이동한 횟수를 카운트하여 최대로 지나온 칸 수를 저장한다.


### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<climits>

using namespace std;
const int MAX = 20;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int r, c;
vector<string> a;
map<char, bool> m;

int ans = 0;
void dfs(int x, int y, int cnt) {

	ans = max(ans, cnt); // 이동한 최댓값을 구함

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
			if (!m[a[nx][ny]]) { // 아직 한번도 밟지 않은 알파벳인 경우
				m[a[nx][ny]] = true; //  방문 처리
				dfs(nx, ny, cnt + 1);
			}
		}
	}
	m[a[x][y]] = false; // 방문 처리 해제

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c;
	cin.ignore();
	a.resize(r);

	// map에 모든 알파벳 대문자를 키로, 벨류를 false로 초기화
	for (int i = 0; i < 26; i++) {
		m.insert(make_pair('A' + i, false));
	}

	for (int i = 0; i < r; i++)
		cin >> a[i];

	m[a[0][0]] = true;
	dfs(0, 0, 1);

	cout << ans << '\n';
}
```
