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
int tmp[MAX][MAX]; // �ѹ��� Ȯ���� �̷������ �ϱ� ���� ����� �ӽ� �迭

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int r, c, t;
vector<int> cleaner; // ����û���� ��ġ

void print() { // ��� �Լ�
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
	// ��ĭ ����û���� ����
	for (int i = cleaner[0] - 1; i > 0; i--) { // 0�� �Ʒ��� �̵�
		a[i][0] = a[i - 1][0];	
	}
	for (int i = 0; i < c - 1; i++) { // 0�� �������� �̵�
		a[0][i] = a[0][i + 1];
	}
	for (int i = 0; i < cleaner[0]; i++) { // c - 1�� ���� �̵�
		a[i][c - 1] = a[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) { // ����û���� ���κ� �� ���������� �̵�
		a[cleaner[0]][i] = a[cleaner[0]][i - 1];
	}
	a[cleaner[0]][1] = 0;

	// �Ʒ�ĭ ����û���� ����
	for (int i = cleaner[1] + 1; i < r - 1; i++) { // 0�� ���� �̵�
		a[i][0] = a[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) { // r - 1�� �������� �̵�
		a[r - 1][i] = a[r - 1][i + 1];
	}
	for (int i = r - 1; i > cleaner[1]; i--) { // c - 1�� �Ʒ��� �̵�
		a[i][c - 1] = a[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) { // ����û���� �Ʒ��κ� �� ���������� �̵�
		a[cleaner[1]][i] = a[cleaner[1]][i - 1];
	}
	a[cleaner[1]][1] = 0;
}

void spread() {
	// �̼����� Ȯ��
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
				a[x][y] -= sum; // Ȯ��� �縸ŭ ����
			}
		}
	}

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			a[x][y] += tmp[x][y]; // Ȯ��� ���� �ѹ��� ������
			tmp[x][y] = 0; // tmp �ʱ�ȭ
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
			if (a[i][j] == -1) cleaner.push_back(i); // ���� û���� ��ġ ����
		}
	while (t--) {
		spread(); // Ȯ��
		wind(); // �̵�
	}

	int ans = 0;
	for(int i =0; i < r; i++)
		for (int j = 0; j < c; j++) {
			ans += a[i][j];
		}
	ans += 2; // ���� û���� ����

	cout << ans << '\n';
}