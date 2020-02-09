#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	while (true) 
	{
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> s(k);

		for (int i = 0; i < k; i++)
			cin >> s[i];
		sort(s.begin(), s.end()); // 입력 수열 정렬

		vector<int> d;
		for (int i = 0; i < 6; i++) // 1은 뽑는 경우 0은 뽑지 않는 경우로하여 해결한다.
			d.push_back(1);	// 6개를 뽑으므로 1을 6번 삽입
		for (int i = 0; i < k - 6; i++)
			d.push_back(0);

		vector<vector<int>> ans; // 출력 벡터

		do {
			vector<int> current;
			for (int i = 0; i < k; i++)
			{
				if (d[i] == 0) continue; // 1인 것만 삽입
				current.push_back(s[i]);
			}
			ans.push_back(current);
		} while (prev_permutation(d.begin(), d.end())); // d에 1을 먼저 삽입했으므로 마지막 순열, 따라서 이전순열을 구하며 반복

		for (auto v : ans) // 2중 벡터 출력
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}