#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, b, c; // 100�� * 100���� �ִ��̹Ƿ� long long
	cin >> n;

	vector<long long> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> b >> c;
	long long ans = n; // �� �������� ������ 1��
	for (int i = 0; i < n; i++)
	{
		a[i] -= b;
		if (a[i] <= 0) continue; // �� ������ 1������ ��� ���� ������ ���
		long long s = a[i] / c;
		long long r = a[i] % c;

		ans += r == 0 ? s : s + 1; // �������� 0�� �ƴϸ� 1�� �߰�
	}

	cout << ans << '\n';
}