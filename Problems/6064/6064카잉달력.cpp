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
		x--; // x�� y���� 1�� ���ش�.
		y--; // ������ ������ ���ϰ� �ϱ� ����
		bool ok = false; // <x:y>�� ��ȿ�� ǥ������ Ȯ��
		for (int k = x; k < n * m; k+=m)
		{
			if (k % n == y)
			{
				cout << k + 1 << '\n'; // ���� x, y���� 1�� ���� ��������Ƿ� 1���Ͽ� ���
				ok = true; // ��ȿ�� ���
				break;
			}
		}
		
		if (!ok) // ��ȿ�� ��찡 ���� �� -1���
			cout << -1 << '\n';
		
	}

}