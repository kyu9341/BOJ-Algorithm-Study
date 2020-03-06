#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
	int n, m, k;
	cin >> n >> m >> k;

	while (k > 0) // 인턴 인원을 하나씩 결정한다.
	{ // 여, 남 2 : 1 비율을 맞추며 인원 조정
		if (m * 2 > n) 
		{
			m--; k--;
		}
		else if (m * 2 == n)
		{
			m--; k--;
		}
		else
		{
			n--; k--;
		}
	}

	int ans = 0;
	while (n > 1 && m > 0) // 인턴 인원을 제외한 후 팀 결성
	{
		m--; n -= 2;
		ans++;
	}

	cout << ans << '\n';
}