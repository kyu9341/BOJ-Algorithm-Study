#include<iostream>

using namespace std;
const int MAX = 1000000;

int prime[MAX]; // �Ҽ����� ���� �迭
bool check[MAX + 1]; // check�� �ε����� �Ҽ��� ��
int pn = 0; // �Ҽ��� ����

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 2; i <= MAX; i++) // �����佺�׳׽��� ü
	{
		if (check[i] == false)  // �������� �ʾҴٸ�(�Ҽ����)
		{
			prime[pn++] = i; // �Ҽ� �迭�� �߰�
			for (int j = i + i; j <= MAX; j += i) // i*i ���� ������ �ϸ� ������ ������ �Ѿ� ��Ÿ�� ������ ��
			{
				check[j] = true;
			}
		}
	}

	while (true)
	{
		int n;
		cin >> n;
		if (n == 0)
			return 0;

		for (int i = 1; i < pn ; i++) // 3���� ����
		{
			if (!check[n - prime[i]]) // n - prime[i] �� �Ҽ��� ����
			{
				cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
				break;
			}
		}
	}
	return 0;
}