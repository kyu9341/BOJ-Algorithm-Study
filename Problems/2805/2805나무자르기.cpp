#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<long long>& a, long long m, long long h) // ���ܱ��� ���� h�� ������ �߶� m�̻��� ���� �� �ִ��� Ȯ���ϴ� �Լ�
{
	long long cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] - h > 0) // h �� ������ ���̺��� ������ �߸��� ����
		{
			cnt += a[i] - h;
		}
	}
	return cnt >= m; // �ڸ� ������ ������ ���� m�̻��̸� ��
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long m;
	cin >> n >> m;

	vector<long long> a(n);
	long long maxlen = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (maxlen < a[i])	maxlen = a[i];
	}

	long long left = 0;
	long long right = maxlen; // ���� ������ �ִ�
	long long ans = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		if (check(a, m, mid)) // ���� ���̷� ������ ���� m�� ���� �� �ִ��� Ȯ��
		{	
			if (ans < mid) 
				ans = mid; // �����ϴٸ� ���� ���ܱ� ���� ����
			left = mid + 1; // �ִ��� ���ؾ��ϹǷ� �� ���� �ø� �� �ִ��� Ȯ��
		}
		else
		{
			right = mid - 1; // �Ұ����ϴٸ� ���ܱ� ���̸� ����
		}
	}
	cout << ans << '\n';
}