#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
const int MAX = 20;
int s[MAX + 1][MAX + 1];

int select(int n, int index, vector<int> &a, vector<int> &b)
{

	if (index == n) // 정답을 구한 경우
	{
		if (a.size() == 0 || b.size() == 0) // 팀에는 최소 한 명이상 있어야 함.
			return -1;

		int diff = -1;
		int teamA = 0;
		int teamB = 0;
		if (a.size() == 1)  teamA = a[0]; // 팀원이 한명인 경우
		else
		{
			for (int i = 0; i < a.size(); i++)
				for(int j = 0; j < a.size(); j++)
				teamA += s[a[i]][a[j]]; // 같은 팀에 속했을 때의 더해지는 능력치 누적
		}
		if (b.size() == 1)  teamB = b[0]; // 팀원이 한명인 경우
		else
		{
			for (int i = 0; i < b.size(); i++)
				for(int j = 0; j < b.size(); j++)
				teamB += s[b[i]][b[j]]; // 같은 팀에 속했을 때의 더해지는 능력치 누적
		}
		diff = teamA - teamB;
		if (diff < 0) diff = -diff;

		return diff;
	}

	int ans = -1;
	a.push_back(index); // index번째 사람을 a팀에 넣는 경우
	int resA = select(n, index + 1, a, b);
	if (ans == -1 || (resA != -1 && resA < ans)) // 잘못된 경우가 아닐때, 최솟값을 구한다.
		ans = resA;
	a.pop_back(); // 한 명을 뺀다

	b.push_back(index); // index번째 사람을 b팀에 넣는 경우
	int resB = select(n, index + 1, a, b);
	if (ans == -1 || (resB != -1 && resB < ans))
		ans = resB;
	b.pop_back();

	return ans;
}

int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	vector<int> a;
	vector<int> b;

	int ans = select(n, 0, a, b);
	cout << ans << '\n';
}