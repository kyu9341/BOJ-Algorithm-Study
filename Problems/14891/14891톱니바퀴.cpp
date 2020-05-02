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

// 톱니바퀴를 회전시키는 함수
void rotate(int num, int dir) { 
	// 시계 방향 회전
	if (dir == 1) {
		int tmp = a[num - 1][7];
		for (int i = 7; i >= 1; i--) {
			a[num - 1][i] = a[num - 1][i - 1];
		}
		a[num - 1][0] = tmp;
	}
	// 반 시계 방향 회전
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
		int right = num; // 오른쪽 톱니바퀴 확인
		int left = num; // 왼쪽 톱니바퀴 확인
		int right_dir = dir; // 오른쪽 톱니바퀴의 회전방향
		int left_dir = dir; // 왼쪽 톱니바퀴의 회전방향

		// 왼쪽으로 이동하며 함께 회전하는 톱니바퀴를 구한다.
		while (left > 1 && a[left - 1][6] != a[left - 2][2]) {
				left--;
		}
		// 톱니바퀴 회전
		for (int i = num; i > left; i--) {
			left_dir *= -1; // 이전 톱니바퀴와 반대 방향으로 회전
			rotate(i - 1, left_dir);
		}

		// 오른쪽으로 이동하며 함께 회전하는 톱니바퀴를 구한다.
		while (right < 4 && a[right - 1][2] != a[right][6]) {
			right++;
		}
		// 톱니바퀴 회전
		for (int i = num; i < right; i++) {
			right_dir *= -1;  // 이전 톱니바퀴와 반대 방향으로 회전
			rotate(i + 1, right_dir);
		}

		rotate(num, dir); // 현재 회전시키는 톱니바퀴 회전
	}
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (a[i][0] == 1) {
			ans += pow(2, i); // 점수 구하기
		}
	}
	
	cout << ans << '\n';
}