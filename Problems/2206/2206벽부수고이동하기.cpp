#include<algorithm>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int MAX = 1000;
int a[MAX][MAX];
int dist[MAX][MAX][2];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

int n, m;

int bfs() {

	queue<pair<pair<int, int>, int>> q;
	q.push({ {0, 0}, 0 });
	dist[0][0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int check = q.front().second; // ���� �ν����� ����

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
				// �ߺ��� �ƴ� ��츸 Ȯ��
				if (dist[nx][ny][check] == -1) {
					if (a[nx][ny] == 0) { // ���� ��ġ�� �̵� �����ϴٸ� �׳� �̵�
						q.push({ { nx, ny }, check }); 
						dist[nx][ny][check] = dist[x][y][check] + 1;
					}
					else if(a[nx][ny] == 1 && check == 0){ // ���� ��ġ�� ���ε� ���� �μ��� �ʾҴٸ�
						q.push({ {nx, ny}, 1 }); // ���� �μ��� �̵��ϴ� ��� �߰�
						dist[nx][ny][1] = dist[x][y][0] + 1;
					}
				}
			}
		}
		// ���� �μ��� ���� �μ��� �ʴ� ��� ��� ������ �� �ִٸ� ������ �� ����
		if (dist[n - 1][m - 1][0] != -1 && dist[n - 1][m - 1][1] != -1) {
			return min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
		}
	}
	// �Ѵ� �������� ���ߴٸ� -1, �ϳ��� �����ߴٸ� �� �Ÿ��� ����
	return max(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;

	vector<pair<int, int>> wall;

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			a[i][j] = input[j] - '0';
		}
	}
	memset(dist, -1, sizeof(dist));

	cout << bfs() << '\n';
	
}