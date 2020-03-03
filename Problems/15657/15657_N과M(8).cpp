#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int a[10];
int out[10]; // ��� �迭

void go(int n, int m, int start, int index)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << out[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++) // �񳻸��������� �����ϱ� ���� start���� ���
	{
		out[index] = a[i];
		go(n, m, i, index + 1);
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);
	
	go(n, m, 0, 0);
}