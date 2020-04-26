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