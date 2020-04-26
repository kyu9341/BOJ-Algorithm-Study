#include <string>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100;
long long mod = 1000000007;
long long d[MAX + 1][MAX + 1];

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	// 초기값 설정
	d[1][1] = 1;
	d[1][2] = 1;
	d[2][1] = 1;

	// 물에 잠긴 위치 표시
	for (int i = 0; i < puddles.size(); i++) {
		d[puddles[i][0]][puddles[i][1]] = -1;
	}
	
	// d[m][n] = (m, n)까지 오는 최단 거리의 개수
	// d[m][n] = d[m - 1][n] + d[m][n - 1]
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (d[i][j] == -1) 
				d[i][j] = 0;
			else if(d[i][j] == 0)
				d[i][j] = d[i - 1][j] + d[i][j - 1];
			d[i][j] %= mod;
		}
	}

	answer = d[m][n] % mod;


	return answer;
}