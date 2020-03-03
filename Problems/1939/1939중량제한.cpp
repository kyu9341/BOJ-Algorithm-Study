#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;
const int MAX = 10000;
vector<pair<int, int>> a[MAX + 1];
bool check[MAX + 1]; // 방문 여부

bool dfs(int node, int weight, int target) // dfs를 통해 현재 중량 제한을 만족하는 길이 있는지 확인
{
	check[node] = true; // 방문 처리
	if (check[target]) return true;

	for (int i = 0; i < a[node].size(); i++) // 연결된 섬 모두 확인
	{
		int next = a[node][i].first;
		int w = a[node][i].second;
		if (!check[next] && w >= weight) // 중량 제한을 만족하고 방문하지 않은 경우
		{
			if (dfs(next, weight, target)) return true; // 목표 공장을 찾았다면 true리턴
		}
	}
	return false; // 모두 방문했지만 목표 공장을 찾지 못한 경우 false
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	int maxWeight = 0;
	for (int i = 0; i < m; i++) // 섬과 다리 입력
	{
		int u, v, w;
		cin >> u >> v >> w;
		a[u].push_back(make_pair(v, w));
		a[v].push_back(make_pair(u, w));
		if (maxWeight < w) // 중량 제한의 최댓값 저장
			maxWeight = w;
	}
	int start, end; // 출발 공장, 도착 공장
	cin >> start >> end;

	int left = 1;
	int right = maxWeight;
	int ans = 0;

	while (left <= right) // 이분 탐색
	{
		memset(check, false, sizeof(check)); // check배열 초기화
		int mid = (left + right) / 2; // 중량 제한
		if (dfs(start, mid, end)) // 현재 중량 제한을 만족하는 길이 있는 경우
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << ans << '\n';

}