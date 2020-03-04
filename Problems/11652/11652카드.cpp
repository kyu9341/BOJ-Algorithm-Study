#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
const int MAX = 100000;
long long a[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);

	int max_cnt = 1;
	int cnt = 1;
	long long ans = a[0]; // �ʱ�ȭ (�ִ밡 ����������� ���� ���� �� ���)
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1])
		{
			cnt++;
			if (max_cnt < cnt)
			{
				max_cnt = cnt;
				ans = a[i];
			}
		}
		else
		{
			cnt = 1;
		}
	}
	cout << ans << '\n';

}