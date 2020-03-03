#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<int>& a, int n, int l)
{
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		cnt += a[i] / l; // ������ �ִ� ������ ���� l�� �ڸ��� �� ���� ���� �� �ִ��� Ȯ��
	}
	return cnt >= n; // ���� �� �ִ� ������ ������ n�̻��̸� ��
}

int main(void)
{
	int k, n;
	cin >> k >> n;

	vector<int> a(k);

	long long right = 0;
	for (int i = 0; i < k; i++)
	{
		cin >> a[i];
		if (right < a[i])
			right = a[i]; // ���� ������ �ִ�
	}

	long long ans = 0;
	long long left = 1;
	
	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (check(a, n, mid)) // ���� ���̷� n���� ������ ���� �� �ִ��� Ȯ��
		{
			ans = mid; // ���� ���̸� �����ϰ�
			left = mid + 1; // �� ū ���̷� ���� �� �ִ��� Ȯ��
		}
		else // ���� ���̷� n���� ���� �� ���ٸ� ���̸� �ٿ��� Ȯ��
		{
			right = mid - 1;
		}

	}

	cout << ans << '\n';

}