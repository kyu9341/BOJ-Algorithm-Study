#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; // testcase
	cin >> t;

	while (t--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		x--; // x와 y에서 1씩 빼준다.
		y--; // 나머지 연산을 편하게 하기 위해
		bool ok = false; // <x:y>가 유효한 표현이지 확인
		for (int k = x; k < n * m; k+=m)
		{
			if (k % n == y)
			{
				cout << k + 1 << '\n'; // 먼저 x, y에서 1을 빼고 계산했으므로 1더하여 출력
				ok = true; // 유효한 경우
				break;
			}
		}
		
		if (!ok) // 유효한 경우가 없을 시 -1출력
			cout << -1 << '\n';
		
	}

}