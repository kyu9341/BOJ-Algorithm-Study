#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;

bool check(vector<int>& a, int c, int dist) // ������ ������ ������ �Ÿ��� ���� ����(dist)�̻��� ��찡 c�̻����� �Ǻ��ϴ� �Լ�
{
	int cnt = 1; // ������ ���� + 1���� �������� ����
	int last = a[0];
	for(int house : a)
	{
		if (house - last >= dist) // ������ �����⸦ ��ġ�ߴ� ���� �Ÿ� ��
		{
			cnt++;
			last = house; // �����⸦ ��ġ�� ���� ���� ����
		}
	}
	return cnt >= c; // ���� ������ ������ ������ �Ÿ��� dist�̻��� ��찡 c�� �̻��̸� ��
}

int main(void)
{
	int n, c;
	cin >> n >> c;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end()); // �������� ����
	
	int right = a[n - 1] - a[0]; // ���� �ָ� ������ �� ���� ����
	int left = 1;
	int ans = 1;

	while (left <= right)
	{
		int mid = (left + right) / 2; // ������ �� �������� �Ÿ�
		if (check(a, c, mid))
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << ans << '\n';
}