#include<iostream>
#include<algorithm>
using namespace std;
int a[10]; // �Է� �迭
int out[10]; // ��� �迭
bool check[10]; // �ߺ� üũ
void go(int index, int n, int m)
{
	if (m == index)
	{
		for (int i = 0; i < m; i++)
		{
			cout << out[i];
			if (i != m)	cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (check[i]) continue; // ������ ���� ���̸� �Ѿ
		out[index] = a[i];
		check[i] = true; // �ߺ� üũ
		go(index + 1, n, m);
		check[i] = false;
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n); // ������������ ����ϱ� ���� ���� ����
	go(0, n, m);
	
}