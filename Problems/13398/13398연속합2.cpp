#include<iostream>
#include<algorithm>
using namespace std;
int d[100001]; // d[i]�� i��° ���� ������ ������
int d2[100001]; // d[i]�� i��° ������ �����ϴ� ������
int a[100001]; // �Է� ����
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1, j = 0; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++) // i��° ���� ������ �ִ� �������� ���Ѵ�.
	{
		d[i] = a[i];
		if (d[i - 1] + a[i] > a[i]) //  i-1������ �ִ� �����տ� ���� ���� ���� ���� ���� ������ �� ū�� ��
			d[i] = d[i - 1] + a[i];
		
	}

	for (int i = n; i >= 1; i--) // i��° ���� �����Ͽ� n���� ������ �ִ� �������� ���Ѵ�.
	{
		d2[i] = a[i];
		if (i == n)	continue; // i + 1�� �����ϸ� �ȵǹǷ�
		if (d2[i] < d2[i + 1] + a[i]) // i�� n - 1���� �����ϸ� ��
			d2[i] = d2[i + 1] + a[i];

	}

	int ans = d[1];
	for(int i = 1; i <= n; i++)	// ���� �������� ���� ���� �����Ƿ� 
		ans = max(ans, d2[i]);	// �������� �ʴ� ��� ������ ���س��´�.
	   
	for (int i = 0; i <= n; i++)
		ans = max(ans, d[i - 1] + d2[i + 1]);
	cout << ans << '\n';
}