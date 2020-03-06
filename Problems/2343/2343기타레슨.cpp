#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int n, m;

bool check(int blue) // ũ�Ⱑ blue�� ��緹�̷� ��ȭ�ϸ� m�� ������ ��緹�̰� �������� �Ǻ�
{
	int sum = 0;
	int cnt = 1; // ������ �׷� ī��Ʈ
	for (int i = 0; i < n; i++)
	{
		if (sum + a[i] <= blue) // ���ݱ����� ���� ���ϸ� ��緹�� ũ�⺸�� ū�� Ȯ��
			sum += a[i];
		else // ��緹�� ũ�⺸�� ũ�ٸ�
		{
			sum = a[i]; // ���ݱ��� �� �ʱ�ȭ, ���� ����
			cnt++; // ��緹�� ���� + 1
		}
	}
	return cnt <= m; // ���� ��緹�� ũ��� ������ ���� �� �ִ��� �Ǻ�
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}	
		
	int left = *max_element(a, a + n); // ���� ũ���� �ִ�(��� �ϳ��� ������ ��ƾ� ��)
	int right = sum;
	int ans = sum;

	while (left <= right) // ��緹�� ũ�⸦ �������� �̺� Ž��
	{
		int mid = (left + right) / 2; // ��緹���� ũ��
		if (check(mid)) // ���� ��緹���� ũ��� �����ϴٸ�
		{
			if (ans > mid)
				ans = mid;
			right = mid - 1; // ������ �ּڰ��� �ִ��� Ȯ��
		}
		else
			left = mid + 1; // ��緹�� ũ�⸦ Ű���� Ȯ��
	}
	cout << ans << '\n';
}