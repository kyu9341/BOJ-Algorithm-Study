#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
	int n, m;
	cin >> n >> m;
	
	int ans = 0;
	if (n >= 3) // 상하로 두 칸씩 이동 가능한 경우
	{
		if (m >= 7)
			ans = m - 2;
		else if (m < 7 && m > 4)
			ans = 4;
		else
			ans = m;
	}
	else // n < 3
	{
		if (n == 1 || m <= 2)
			ans = 1;
		else if (m <= 7)
			ans = (m + 1) / 2;
		else
			ans = 4; // 그 이상은 모두 4칸(2, 3번 밖에 사용하지 못하므로)
	}

	cout << ans << '\n';
}