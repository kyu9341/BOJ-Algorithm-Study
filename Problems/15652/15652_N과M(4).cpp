#include<iostream>

using namespace std;
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
		a[index] = i; // �ߺ� ���
		go(index + 1, i, n, m); // index 1�����ϸ� ���
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	go(0, 1, n, m);
}