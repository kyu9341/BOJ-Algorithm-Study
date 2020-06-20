#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
const int MAX = 1000 + 1;
int n, l;
int a[MAX][3];

int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) 
		cin >> a[i][0] >> a[i][1] >> a[i][2]; // d, r, g 입력

	int sec = 0;
	int dist = 0;
	int i = 0;
	while (true) {
		if (dist == a[i][0]) { // 현재 위치에 신호등이 있는지 확인
			int tmp = sec % (a[i][1] + a[i][2]); // 현재 신호 사이클 확인
			if (tmp <= a[i][1]) { // 빨간불인 경우
				sec += a[i][1] - tmp; // 대기시간 추가
			}
			i++;
		}
		sec++;
		dist++;
		if (dist == l) {
			break;
		}
	}

	cout << sec << '\n';

}