#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<climits>
#include<cmath>

using namespace std;
const int MAX = 50;
int a[MAX][MAX];
int tmp[MAX][MAX]; // 한번에 확산이 이루어지게 하기 위해 사용할 임시 배열

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int r, c, t;
vector<int> cleaner; // 공기청정기 위치

void print() { // 출력 함수
	cout << '\n';
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			cout << a[x][y] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}
void wind() {
	// 위칸 공기청정기 동작
	for (int i = cleaner[0] - 1; i > 0; i--) { // 0열 아래로 이동
		a[i][0] = a[i - 1][0];	
	}
	for (int i = 0; i < c - 1; i++) { // 0행 왼쪽으로 이동
		a[0][i] = a[0][i + 1];
	}
	for (int i = 0; i < cleaner[0]; i++) { // c - 1열 위로 이동
		a[i][c - 1] = a[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) { // 공기청정기 윗부분 행 오른쪽으로 이동
		a[cleaner[0]][i] = a[cleaner[0]][i - 1];
	}
	a[cleaner[0]][1] = 0;

	// 아래칸 공기청정기 동작
	for (int i = cleaner[1] + 1; i < r - 1; i++) { // 0열 위로 이동
		a[i][0] = a[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) { // r - 1행 왼쪽으로 이동
		a[r - 1][i] = a[r - 1][i + 1];
	}
	for (int i = r - 1; i > cleaner[1]; i--) { // c - 1열 아래로 이동
		a[i][c - 1] = a[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) { // 공기청정기 아랫부분 행 오른쪽으로 이동
		a[cleaner[1]][i] = a[cleaner[1]][i - 1];
	}
	a[cleaner[1]][1] = 0;
}

void spread() {
	// 미세먼지 확산
	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (a[x][y] > 0) {
				int sum = 0;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
					if (a[nx][ny] == -1) continue;

					tmp[nx][ny] += a[x][y] / 5;
					sum += a[x][y] / 5;

				}
				a[x][y] -= sum; // 확산된 양만큼 빼줌
			}
		}
	}

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			a[x][y] += tmp[x][y]; // 확산된 양을 한번에 더해줌
			tmp[x][y] = 0; // tmp 초기화
		}
	}

}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> r >> c >> t;

	for (int i = 0; i < r; i++) 
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) cleaner.push_back(i); // 공기 청정기 위치 저장
		}
	while (t--) {
		spread(); // 확산
		wind(); // 이동
	}

	int ans = 0;
	for(int i =0; i < r; i++)
		for (int j = 0; j < c; j++) {
			ans += a[i][j];
		}
	ans += 2; // 공기 청정기 제거

	cout << ans << '\n';
}