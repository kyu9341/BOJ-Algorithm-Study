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
		a[index] = i;
		go(index + 1, i + 1, n, m); // ���� �ݺ��� ������ ���� ����
	}				// �׻� �� ū ���� �ڿ� ��
}

void go2(int index, int selected, int n, int m) // go2 : index��� ���� ����� �����Ұ��� ������ ����
//  index : ���� �ڿ��� // selected : , ���ݱ��� ������ ���� ����
{		
	if (selected == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}
	if (index > n) return; // index�� n���� Ŀ���� ��� ����
	a[selected] = index;		// index�� ����� �߰��ϴ� ���
	go2(index + 1, selected + 1, n, m);
	a[selected] = 0;			// index�� ����� �߰����� �ʴ� ���
	go2(index + 1, selected, n, m);
}


int main(void)
{
	int n, m;
	cin >> n >> m;

	go2(1, 0, n, m);
	// go(0, 1, n, m);
}