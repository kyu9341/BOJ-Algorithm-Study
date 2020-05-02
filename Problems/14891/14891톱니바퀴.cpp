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

int a[4][8];

// ��Ϲ����� ȸ����Ű�� �Լ�
void rotate(int num, int dir) { 
	// �ð� ���� ȸ��
	if (dir == 1) {
		int tmp = a[num - 1][7];
		for (int i = 7; i >= 1; i--) {
			a[num - 1][i] = a[num - 1][i - 1];
		}
		a[num - 1][0] = tmp;
	}
	// �� �ð� ���� ȸ��
	else if (dir == -1) {
		int tmp = a[num - 1][0];
		for (int i = 0; i < 7; i++) {
			a[num - 1][i] = a[num - 1][i + 1];
		}
		a[num - 1][7] = tmp;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++)
			a[i][j] = str[j] - '0';
	}

	int n;
	cin >> n;

	while (n--) {
		int num, dir;
		cin >> num >> dir;
		int right = num; // ������ ��Ϲ��� Ȯ��
		int left = num; // ���� ��Ϲ��� Ȯ��
		int right_dir = dir; // ������ ��Ϲ����� ȸ������
		int left_dir = dir; // ���� ��Ϲ����� ȸ������

		// �������� �̵��ϸ� �Բ� ȸ���ϴ� ��Ϲ����� ���Ѵ�.
		while (left > 1 && a[left - 1][6] != a[left - 2][2]) {
				left--;
		}
		// ��Ϲ��� ȸ��
		for (int i = num; i > left; i--) {
			left_dir *= -1; // ���� ��Ϲ����� �ݴ� �������� ȸ��
			rotate(i - 1, left_dir);
		}

		// ���������� �̵��ϸ� �Բ� ȸ���ϴ� ��Ϲ����� ���Ѵ�.
		while (right < 4 && a[right - 1][2] != a[right][6]) {
			right++;
		}
		// ��Ϲ��� ȸ��
		for (int i = num; i < right; i++) {
			right_dir *= -1;  // ���� ��Ϲ����� �ݴ� �������� ȸ��
			rotate(i + 1, right_dir);
		}

		rotate(num, dir); // ���� ȸ����Ű�� ��Ϲ��� ȸ��
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i][0] == 1) {
			ans += pow(2, i); // ���� ���ϱ�
		}
	}
	
	cout << ans << '\n';
}