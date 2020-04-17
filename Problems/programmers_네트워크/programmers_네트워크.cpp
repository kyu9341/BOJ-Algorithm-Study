#include <string>
#include <vector>

using namespace std;
bool check[200]; // Ž���� ������� �Ǻ��ϱ� ���� �迭
vector<int> a[200]; // ��Ʈ��ũ ���� ������ �����ϱ� ���� ����

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
				a[i].push_back(j); // ����
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (!check[i]) { // ���� ������� ���� ��常 Ž��
			answer++; // ��Ʈ��ũ�� ���� ī��Ʈ
			dfs(i, n);
		}
	}

	return answer;
}