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
	if (n >= 3) // ���Ϸ� �� ĭ�� �̵� ������ ���
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
			ans = 4; // �� �̻��� ��� 4ĭ(2, 3�� �ۿ� ������� ���ϹǷ�)
	}

	cout << ans << '\n';
}