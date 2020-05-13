#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>

using namespace std;
const int MAX = 50;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int a[MAX][MAX];
int visited[MAX][MAX]; // ���� ��ġ���� �ּҷ� ���� �ٲپ�� �ϴ� ����
int n;

struct place {
	int x;
	int y;

	place(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

void bfs() {
	queue<place> q;
	q.push(place(0, 0));
	visited[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < n && ny < n) { // ���� ������
				if (a[nx][ny] == 1) { // �� ���� ���
					// ���� �湮���� �ʾҰų� �� ���� Ƚ���� �̵� ������ ���
					if (visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y]) { 
						visited[nx][ny] = visited[x][y];
						q.push(place(nx, ny));
					}
				}
				else { // ���� ���� ���
					// ���� �湮���� �ʾҰų� �� ���� Ƚ���� �̵� ������ ���
					if (visited[nx][ny] == -1 || visited[nx][ny] > visited[x][y] + 1) {
						visited[nx][ny] = visited[x][y] + 1;
						q.push(place(nx, ny));
					}
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	cin.ignore();
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++)
			a[i][j] = str[j] - '0';
	}

	memset(visited, -1, sizeof(visited));
	bfs();

	cout << visited[n - 1][n - 1] << '\n';

}