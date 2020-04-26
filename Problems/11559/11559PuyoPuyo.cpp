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

void fall() { // �ѿ並 ����߸��� �Լ�
	for (int j = 0; j < m; j++) {
		while (true) {
			bool ok = false;
			// �� ������ ���� ���� ����� ���� �࿡ �ѿ䰡 �ִ� ��� 
			// �ѿ並 �� ĭ ������.
			for (int i = n - 1; i >= 1; i--) {
				if (a[i][j] == '.' && a[i - 1][j] != '.') {
					a[i][j] = a[i - 1][j];
					a[i - 1][j] = '.';
					ok = true;
				}
			}
			if (!ok) break; // ���̻� ���� �ѿ䰡 ������ ����
		}
	}

}


void dfs(int x, int y, char pre) {
	check[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		// ���� ������ ���� �ѿ�� ���� ���̰� �湮���� ���� ���
		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			if (!check[nx][ny] && pre == a[nx][ny]) {
				idx++;
				dfs(nx, ny, a[x][y]);
			}
		}
	}

}

void print() { // Ȯ�ο� ����Լ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << a[i][j];
		}
		cout << '\n';
	}
}


// dfs�� 4�� �̻��� �ѿ䰡 ��ģ ��� �ѿ並 �����ϴ� �Լ�
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
		// ���� ���� �Ʒ����� Ȯ��
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j < m; j++) {
				idx = 1;
				memset(check, false, sizeof(check)); // check�ʱ�ȭ
				if (a[i][j] != '.') { // �ѿ䰡 �ִ°�츸 dfs����
					dfs(i, j, a[i][j]);
					if(idx >= 4){
						ok = true;
						remove(); // 4�� �̻� ���� �ѿ� ����
					}
				}
			}
		}
		if (!ok) break; // �� �̻� 4�� �̻� ���ΰ��� ������ ����
		fall(); // ����߸���.
		ans++; // �� ���尡 ������ ���� Ƚ�� ī��Ʈ
	}

	cout << ans << '\n';


}