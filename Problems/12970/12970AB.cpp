#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<queue>

using namespace std;

int countAB(string ab) // ������ AB���� üũ
{
	int ans = 0;
	for (int i = 0; i < ab.size(); i++)
	{
		if (ab[i] == 'A')
		{
			for (int j = i;j < ab.size(); j++)
			{
				if (ab[j] == 'B')
					ans++;
			}
		}
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int m = n / 2;

	if (k > m * (n - m))
	{
		cout << -1 << '\n';
		return 0;
	}

	string ab = "";
	for (int i = 0; i < n; i++) // B�� ��� ä���.
		ab += 'B';

	if (k == 0) // 0�� �� ���� ó��
	{
		ab[n - 1] = 'A';
		cout << ab << '\n';
		return 0;
	}

	int b = n; // A, B�� ���� �ʱ�ȭ
	int a = 0;
	while (true)
	{
		if (a * b >= k)
		{
			for (int i = 0; i < a - 1; i++) // �տ������� A�� ���� - 1 ���� A�� ä���.
				ab[i] = 'A';

			int c = (a - 1) * b; // A�� ���� - 1 * B�� ������ ���� (�������� �� A�� ������ ����)
			int r = k - c; // ������ A�� �̿��Ͽ� ä������ ���� ����
			ab[(n - 1) - r] = 'A'; // ������ �ε������� r�� �տ� A�� �ִ´�.

			break;
		}
		else
		{
			b--; // A, B�� ���� ����
			a++;
		}
	}

	cout << ab << '\n';
	
}