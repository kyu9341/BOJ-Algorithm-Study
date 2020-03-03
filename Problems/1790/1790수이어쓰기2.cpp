#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>
using namespace std;

long long calc(int n) // n������ ���� ��� �̾� ���� ��, �� ���� ����
{
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++)
	{ // start : �ڸ����� ù ��, len : ����
		int end = start * 10 - 1;
		if (end >= n)
			ans += (long)((n - start + 1) * len);
		else
			ans += (long)((end - start + 1) * len); // ���� �ڸ��������� ���� ����
	}
	return ans;
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;

	if (calc(n) < k) // n���� �̾� �� ���� ���̰� k���� ������ �Ұ���
	{
		cout << -1 << '\n';
		return 0;
	}
	int left = 1;
	int right = n;
	int ans = 0;
	while (left <= right) // �̺� Ž��
	{ // � �������� �̾� ��� k��° ���� �������� Ȯ��
		int mid = (left + right) / 2;
		long long len = calc(mid);
		if (k > len)
		{
			left = mid + 1;
		}
		else
		{
			ans = mid;
			right = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = calc(ans);
	// l - k�� ���ؼ� ������ ���� ���̿��� ����.
	cout << s[s.size() - (l - k) - 1] << '\n';
}