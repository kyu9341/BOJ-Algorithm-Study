#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;
int a[10];
int out[10]; // ��� �迭

void go(int n, int m, int index)
{
	if (index == m) // index�� m�� �Ǹ� out�迭 ��� ���
	{
		for (int i = 0; i < m; i++)
		{
			cout << out[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}
		

	for (int i = 0; i < n; i++) // �ߺ� ���
	{
		out[index] = a[i];
		go(n, m, index + 1);
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	go(n, m, 0);
}