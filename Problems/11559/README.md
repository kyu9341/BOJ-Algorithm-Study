# Problem 11559

## Puyo Puyo

### 문제
뿌요뿌요의 룰은 다음과 같다.

>필드에 여러 가지 색깔의 뿌요를 놓는다. 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.
>뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다.
>뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례대로 아래로 떨어지게 된다.
>아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데, 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.
>터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.

남규는 최근 뿌요뿌요 게임에 푹 빠졌다. 이 게임은 1:1로 붙는 대전게임이라 잘 쌓는 것도 중요하지만, 상대방이 터뜨린다면 연쇄가 몇 번이 될지 바로 파악할 수 있는 능력도 필요하다. 하지만 아직 실력이 부족하여 남규는 자기 필드에만 신경 쓰기 바쁘다. 상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산하여 남규를 도와주자!

### 입력
12*6의 문자가 주어진다.

이때 .은 빈공간이고 .이 아닌것은 각각의 색깔의 뿌요를 나타낸다.

R은 빨강, G는 초록, B는 파랑, P는 보라, Y는 노랑이다.(모두 대문자로 주어진다.)

입력으로 주어지는 필드는 뿌요들이 전부 아래로 떨어진 뒤의 상태(즉 뿌요 아래에 빈 칸이 있는 경우는 없음) 이다.
### 출력
현재 주어진 상황에서 몇연쇄가 되는지 출력하라. (하나도 터지지 않는다면 0을 출력하면 된다.)

### 문제 링크
<https://www.acmicpc.net/problem/11559>

### 예제 입력 1
......
......
......
......
......
......
......
......
.Y....
.YG...
RRYG..
RRYGG.

### 예제 출력 1
3

### solve
- 가장 왼쪽 아래칸부터 dfs를 수행하여 같은 색깔의 뿌요인 경우에만 방문을 하며 이어진 같은 색의 뿌요의 개수를 카운트한다.
- 4개 이상 이어진 뿌요가 있다면 이어진 뿌요들을 제거하고 다음 칸을 확인한다.
- 한 라운드에 4개 이상 이어진 뿌요가 없는 경우 while문을 빠져나가고 아니라면 연쇄 횟수를 1증가시키고 제거된 뿌요의 자리에 중력을 적용시킨 후 반복한다.
	- fall함수는 각 열에서 가장 아래의 행부터 시작하여 현재 행이 빈칸이고 위에 뿌요가 있는 경우 현재 행의 칸에 위의 뿌요를 이동시키고 위 뿌요의 자리에 빈칸을 넣어준다.
	- 이 과정을 더이상 빈 칸 위에 뿌요가 없을 때까지 반복한다.
---

- dfs함수 내에서 모여있는 뿌요를 제거하려 했는데 4개가 넘는 뿌요가 모여있는 경우가 제대로 처리가 안돼서 애를 좀 먹었다.
- 제거하는 함수를 따로 작성하여 이번 dfs에서 체크된 부분만 제거하도록 하여 해결하였다.
- 질문게시판에 좋은 반례가 있어 남겨놓는다.
```
Y...YR
B.RGGY
R.GGYY
G.RYGR
YGYGRR
YBRYGY
RRYYGY
YYRBRB
YRBGBB
GBRBGR
GBRBGR
GBRBGR

answer: 14
```


### 코드 설명
```C++
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<iostream>

using namespace std;
const int n = 12;
const int m = 6;
int idx = 1;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

vector<string> a(n);
bool check[n][m];

void fall() { // 뿌요를 떨어뜨리는 함수
	for (int j = 0; j < m; j++) {
		while (true) {
			bool ok = false;
			// 각 열별로 현재 행이 비었고 위의 행에 뿌요가 있는 경우
			// 뿌요를 한 칸 내린다.
			for (int i = n - 1; i >= 1; i--) {
				if (a[i][j] == '.' && a[i - 1][j] != '.') {
					a[i][j] = a[i - 1][j];
					a[i - 1][j] = '.';
					ok = true;
				}
			}
			if (!ok) break; // 더이상 내릴 뿌요가 없을때 종료
		}
	}

}


void dfs(int x, int y, char pre) {
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// 범위 내에서 이전 뿌요와 같은 색이고 방문하지 않은 경우
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (!check[nx][ny] && pre == a[nx][ny]) {
				idx++;
				dfs(nx, ny, a[x][y]);
			}
		}
	}

}

void print() { // 확인용 출력함수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}


// dfs로 4개 이상의 뿌요가 뭉친 경우 뿌요를 삭제하는 함수
void remove() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j]) {
				a[i][j] = '.';
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	for (int i = 0; i < n; i++) {
		getline(cin, a[i]);
	}
	int ans = 0;
	while (true) {
		bool ok = false;
		// 가장 왼쪽 아래부터 확인
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				idx = 1;
				memset(check, false, sizeof(check)); // check초기화
				if (a[i][j] != '.') { // 뿌요가 있는경우만 dfs수행
					dfs(i, j, a[i][j]);
					if(idx >= 4){
						ok = true;
						remove(); // 4개 이상 모인 뿌요 제거
					}
				}
			}
		}
		if (!ok) break; // 더 이상 4개 이상 모인것이 없으면 종료
		fall(); // 떨어뜨린다.
		ans++; // 한 라운드가 끝나면 연쇄 횟수 카운트
	}

	cout << ans << '\n';


}
```
