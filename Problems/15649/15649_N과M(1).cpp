#include<iostream>

using namespace std;
bool check[10]; // ����� ������ üũ
int a[10]; // ����� ������ �迭

void go(int index, int n, int m) // index : 0, 1, 2, .. , m - 1 ���� �϶� ���� �ε���
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i]; // ���
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
		
	for (int i = 1; i <= n; i++)
	{
		if (check[i]) continue; // �ߺ� ����
		check[i] = true; // �̹� ���� ���� true
		a[index] = i;
		go(index + 1, n, m); // �ε����� 1������Ű�� ���
		check[i] = false;
	}
	
}

int main(void)
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	go(0, n, m);
}