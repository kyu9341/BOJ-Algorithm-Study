#include <string>
#include <vector>

using namespace std;
bool check[200]; // 탐색된 노드인지 판별하기 위한 배열
vector<int> a[200]; // 네트워크 연결 정보를 저장하기 위한 벡터

void dfs(int node, int n) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		int next = a[node][i];
		if (!check[next]) {
			dfs(next, n);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (computers[i][j]) {
				a[i].push_back(j); // 연결
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) { // 아직 연결되지 않은 노드만 탐색
			answer++; // 네트워크의 개수 카운트
			dfs(i, n);
		}
	}

	return answer;
}