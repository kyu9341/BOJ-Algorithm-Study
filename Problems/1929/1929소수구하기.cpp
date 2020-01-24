#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool check[1000001] = { false }; // �� ������ �Ҽ� ���θ� üũ�� bool�迭
	int m, n; // �Ҽ� ���� (1 �� M �� N �� 1,000,000)
	cin >> m >> n;
	check[1] = true; // 1�� �Ҽ��� �ƴ�
	//  �����佺�׳׽��� ü
	for (int i = 2; i*i <= n; i++) // i^2�� n�� �Ѿ�� i�� ����� �̹� ��� ������
	{
		if(!check[i])
			for (int j = i; j*i <= n; j++) // i*i�̻��� i�� ����� ��� ������
			{
				if (i * j > 1000000)
					break;
				check[i * j] = true; // �Ҽ��� �ƴϸ� true
	
			}
	}
	for (int i = m; i <= n; i++)
	{
		if (!check[i])
			cout << i << '\n';
	}
	
}