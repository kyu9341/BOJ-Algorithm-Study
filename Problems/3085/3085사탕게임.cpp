#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int check(vector<string>& v) // 가장 긴 사탕의 연속 부분을 리턴
{
	int n = v.size();
	int ans = 1;
	// 먼저 가로 부분을 체크
	for (int i = 0; i < n; i++)
	{
		int cnt = 1; // 초기값
		for (int j = 1; j < n; j++)
		{
			if (v[i][j] == v[i][j - 1])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt) // 비교를 반복문 안에서 수행해야 함
				ans = cnt;
		}
		cnt = 1;
		// 다음 세로 부분 체크
		for (int j = 1; j < n; j++)
		{
			if (v[j][i] == v[j - 1][i])
				cnt++;
			else
				cnt = 1;
			if (ans < cnt) 
				ans = cnt;
		}
	}
	return ans;
}

int main(void)
{
	int n;
	cin >> n;

	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = check(v);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	// 가로로 바꾸어 보며 최댓값을 구한다.
			if (j + 1 < n) // 가로 범위를 넘지 않는 한에서
			{
				swap(v[i][j], v[i][j + 1]); // 우측에 있는 값과 교환
				int temp = check(v);
				swap(v[i][j], v[i][j + 1]); // 다시 되돌려 놓는다.
				if (ans < temp)
					ans = temp;
			}
			// 세로로 바꾸어 보며 최댓값을 구한다.
			if (i + 1 < n) // 세로 범위를 넘지 않는 한에서
			{
				swap(v[i][j], v[i + 1][j]);
				int temp = check(v);
				swap(v[i][j], v[i + 1][j]);
				if (ans < temp)
					ans = temp;
			}
		}

	}

	cout << ans << '\n';

}