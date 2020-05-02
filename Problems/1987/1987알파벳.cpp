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