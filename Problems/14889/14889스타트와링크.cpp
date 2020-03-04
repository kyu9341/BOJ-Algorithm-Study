#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int s[21][21]; // 인원 별 능력치
int n; // 전체 인원 수
int go(int index, vector<int>& first, vector<int>& second) // index : 현재 인덱스, first : 첫번째 팀, second : 두번째 팀
{
	if (index == n) // 답을 구한 경우
	{
		if (first.size() != n / 2) return -1; // 잘못된 경우라면 -1 리턴
		if (second.size() != n / 2) return -1;
		int t1 = 0; // 팀 별 능력치 합계
		int t2 = 0; 
		for(int i = 0; i < n / 2; i++)
			for (int j = 0; j < n / 2; j++)
			{
				if (i == j) continue;
				t1 += s[first[i]][first[j]]; // 첫번째 팀의 s[i][j], s[j][i]를 모두 더함
				t2 += s[second[i]][second[j]];
			}
		int diff = t1 - t2;
		if (diff < 0) diff = -diff;
		
		return diff;
	}
	int ans = -1;
	first.push_back(index); // index번째 사람을 첫 번째 팀에 들어가는 경우
	int t1 = go(index + 1, first, second);
	if (ans == -1 || (t1 != -1 && t1 < ans))
	{
		ans = t1;
	}
	first.pop_back();
	second.push_back(index); // 두 번째 팀에 들어가는 경우
	int t2 = go(index + 1, first, second);
	if (ans == -1 || (t2 != -1 && t2 < ans))
	{
		ans = t2;
	}
	second.pop_back();
	return ans;
}

int main(void)
{
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	vector<int> first, second;
	cout << go(0, first, second) << '\n';
}