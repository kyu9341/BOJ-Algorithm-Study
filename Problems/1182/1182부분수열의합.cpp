#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a[21];
int main(void)
{
	int n, s;
	int sum;
	
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	// n���� �̷���� ���� -> 0 ~ (n - 1) ���� Ȯ��
	int ans = 0;
	for (int i = 1; i < (1 << n); i++) // ��Ʈ����ũ ���
	{
		sum = 0;
		for (int k = 0; k < n; k++) // ��� ��츦 Ȯ��
		{
			if (i & (1 << k)) // ex) i�� 101 �ΰ�� 1, 100 �� ���
				sum += a[k]; // ��� �κм����� ���� ����
		}
		if (s == sum)
			ans++;
	}
	cout << ans << '\n';
}