#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
const int MAX = 1000 + 1;
int compo[MAX][4];
int inspect[301];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b, c;
	cin >> a >> b >> c;
	// 2로 초기화 (알 수 없음)
	fill(inspect + 1, inspect + a + b + c + 1, 2);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> compo[i][0] >> compo[i][1] >> compo[i][2] >> compo[i][3];
		if (compo[i][3] == 1) {
			for (int j = 0; j <= 2; j++)
				inspect[compo[i][j]] = 1; // 합격이면 모두 정상
		}
	}

	for (int i = 0; i < n; i++) { // 두 부품은 합격이지만 결과가 불합격인 경우 나머지 부품은 고장
		if (compo[i][3] == 0) {
			if (inspect[compo[i][0]] == 1 && inspect[compo[i][1]] == 1) {
				inspect[compo[i][2]] = 0;
			}
			else if (inspect[compo[i][1]] == 1 && inspect[compo[i][2]] == 1) {
				inspect[compo[i][0]] = 0;
			}
			else if (inspect[compo[i][0]] == 1 && inspect[compo[i][2]] == 1) {
				inspect[compo[i][1]] = 0;
			}
		}
	}
	// 그 외 부품은 알 수 없음
	for (int i = 1; i <= a + b + c; i++) {
		cout << inspect[i] << '\n'; // 결과 출력
	}


}