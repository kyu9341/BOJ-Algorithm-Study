#include<iostream>
using namespace std;
long long d[91][2]; // d[i][j] = ���� ���� j�� i�ڸ� ��ģ���� ����

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	d[1][1] = 1;
	d[1][0] = 0; // 0���� �����ϴ� ���� ��ģ���� �ƴ�
	for (int i = 2; i <= n; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 1][1];
		d[i][1] = d[i - 1][0];
	}
	cout << d[n][0] + d[n][1] << '\n';
}