#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;
const int MAX = 1000;
int d[MAX + 1][MAX + 1]; // d[s][clipboard]의 상태에 되기 까지 걸리는 시간(초)

int main(void)
{
	int n;
	cin >> n; // 만들어야 할 이모티콘 수

	memset(d, -1, sizeof(d)); // -1로 초기화 : -1은 방문하기 전

	queue<pair<int, int>> q; // s, clipboard
	q.push(make_pair(1, 0));
	d[1][0] = 0; // 초기값, 이모티콘 수는 1, 클립보드에는 0개, 걸리는 시간 0초

	while (!q.empty())
	{
		int s = q.front().first;
		int c = q.front().second;
		q.pop();

		if (d[s][s] == -1) // 복사하는 경우, 클립보드에 s를 복사한다.
		{ // 이모티콘 수가 s개이고 클립보드에 s개가 있는경우를 탐색하지 않았다면
			q.push(make_pair(s, s));
			d[s][s] = d[s][c] + 1; // 이전 상태에서 1초를 추가
		}
		
		if (s + c <= n && d[s + c][c] == -1) // 붙여넣기를 하는 경우
		{
			q.push(make_pair(s + c, c)); // 화면에 c개의 이모티콘이 추가됨
			d[s + c][c] = d[s][c] + 1;
		}

		if (s - 1 >= 0 && d[s - 1][c] == -1) // 이모티콘 하나를 삭제하는 경우
		{
			q.push(make_pair(s - 1, c));
			d[s - 1][c] = d[s][c] + 1;
		}
	
	}

	int ans = -1;
	for (int i = 0; i <= n; i++) 
	{
		if (d[n][i] != -1) // -1이 아닌 최솟값을 구한다.
		{
			if (ans == -1 || ans > d[n][i])
				ans = d[n][i];
		}
	}
	

	cout << ans << '\n';
	
}