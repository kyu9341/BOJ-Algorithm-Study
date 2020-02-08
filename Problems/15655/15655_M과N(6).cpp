#include<iostream>
#include<algorithm>
using namespace std;
int a[10]; // �Է� �迭
int out[10]; // ���� �迭
void go(int index, int start, int n, int m)
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
	for (int i = start; i < n; i++)
	{
		out[index] = a[i];
		go(index + 1, i + 1, n, m);
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n); // ������������ �����ϱ� ���� ���� ����
	go(0, 0, n, m);

}
