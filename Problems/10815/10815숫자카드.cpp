#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 500000;
int a[MAX];
int n, m; // ������ �ִ� ī���� ���� n, ã�ƾ� �� ī���� ���� m

bool find(int num) // �̺� Ž������ ���Ұ� �����ϴ��� �Ǵ�
{
	int left = 0;
	int right = n - 1;

	while (left <= right) // left > right �� �Ǹ� ����
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			return true;
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

	return false;
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
		if (find(num))
			cout << '1';
		else
			cout << '0';
		if(i != m - 1)
			cout << ' ';
	}
	cout << '\n';
}