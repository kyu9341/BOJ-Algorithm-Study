#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	reverse(a.begin(), a.end());

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (k / a[i] > 0)
		{
			cnt += k / a[i]; // ���� ū ������ ��ġ�� ���� ��ŭ ����
			k %= a[i];  // ���� �������� ����
		}
	}

	cout << cnt << '\n';
}