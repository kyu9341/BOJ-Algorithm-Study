#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 500000;
int a[MAX];
int n, m; // ������ �ִ� ī���� ���� n, ã�ƾ� �� ī���� ���� m

int lower_bound(int num) // ũ�ų� ���� �� �� ù ��° ��
{
	int ans = 0;
	int left = 0;
	int right = n - 1;

	while (left <= right) // left > right �� �Ǹ� ����
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			ans = mid;
			right = mid - 1; // ũ�ų� ���� ù��° ���� ã�� ���� �������� �̵�
		}
		else if (a[mid] > num) // �߰� ���Һ��� ������ ������ ������ ����
		{
			right = mid - 1;
		}
		else if (a[mid] < num) // �߰� ���Һ��� ũ�� ���� ������ ����
		{
			left = mid + 1;
		}
	}

	return ans;
}

int upper_bound(int num) // num���� ū �� �� ù��° ��
{
	int left = 0;
	int right = n - 1;
	int ans = 0;

	while (left <= right) // left > right �� �Ǹ� ����
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			ans = mid + 1;
			left = mid + 1; // ū �� �� ù��° ���� ã�� ���� ���������� �̵�
		}
		else if (a[mid] < num)
		{
			left = mid + 1;
		}
		else if (a[mid] > num)
		{
			right = mid - 1;
		}
	}
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;

		cout << upper_bound(num) - lower_bound(num);
		if (i != m - 1)
			cout << ' ';
	}
	cout << '\n';
}