#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());
	
	int ans = 0;
	int now = 0; // ���ݱ����� �ð�
	for (int i = 0; i < n; i++)
	{
		ans += now + a[i]; // ���������� ��  + �̹��� �ɸ� �ð�
		now += a[i];
	}

	cout << ans << '\n';
}