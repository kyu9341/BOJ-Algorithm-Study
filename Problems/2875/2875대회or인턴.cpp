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

	while (k > 0) // ���� �ο��� �ϳ��� �����Ѵ�.
	{ // ��, �� 2 : 1 ������ ���߸� �ο� ����
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
	while (n > 1 && m > 0) // ���� �ο��� ������ �� �� �Ἲ
	{
		m--; n -= 2;
		ans++;
	}

	cout << ans << '\n';
}