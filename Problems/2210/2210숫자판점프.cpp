#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<set>

using namespace std;
const int MAX = 5;
int a[MAX][MAX];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
set<string> s;

void dfs(int x, int y, int index, string number) {
	if (index == 5) {
		if(s.find(number) == s.end()) // 중복이 아니면 삽입
			s.insert(number);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < MAX && ny < MAX) {
			dfs(nx, ny, index + 1, number + to_string(a[nx][ny]));
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			cin >> a[i][j];

	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++) 
			dfs(i, j, 0, to_string(a[i][j]));
		
	cout << s.size() << '\n';

}