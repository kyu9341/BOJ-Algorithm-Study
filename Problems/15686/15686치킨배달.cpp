#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<climits>
#include<cmath>
#include<cstdlib>

using namespace std;
const int MAX = 51;
bool check[13];
int n, m;
int ans = INT_MAX;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;

int getDist(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

int minDist(vector<int> &selected) { // ������ ġŲ �Ÿ��� ���ϴ� �Լ�
	int sum = 0;
	for (int i = 0; i < home.size(); i++) {
		int min = MAX * MAX;
		for (int j = 0; j < selected.size(); j++) {
			int nowDist = getDist(home[i].first, home[i].second, chicken[selected[j]].first, chicken[selected[j]].second);
			if (nowDist < min) {
				min = nowDist;
			}
		}
		sum += min;
	}
	return sum;
}

void go(int index, int start, vector<int> &selected) {
	if (index == m) {
		ans = min(ans, minDist(selected));
		return;
	}

	for (int i = start; i < chicken.size(); i++) { // ���� ������ �ϳ���
		if (check[i]) continue; // �ߺ� ����
		check[i] = true;
		selected.push_back(i);
		go(index + 1, i + 1, selected);
		selected.pop_back();
		check[i] = false;
	}
}


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			if (input == 2) {
				chicken.push_back(make_pair(i, j));
			}
			if (input == 1) {
				home.push_back(make_pair(i, j));
			}
		}
	vector<int> selected;
		
	go(0, 0, selected);
	
	cout << ans << '\n';

}