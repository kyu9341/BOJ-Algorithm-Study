#include<iostream>

using namespace std;
bool check[10];
int a[10];
void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		go(index + 1, i + 1, n, m); // ���� �ݺ��� ������ ���� ����
	}				// �׻� �� ū ���� �ڿ� ��
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	go(0, 1, n, m);
}