#include<iostream>
#include<vector>
// LIS ����
using namespace std;
void go(int);
int a[1001];
int v[1001]; // �������� ���� �迭
int d[1001]; // d[i] = a[1], ... a[i] ���� ���� ��, a[i]�� ���� ���������� �ϴ� LIS�� ����

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // ������ ũ��
	cin >> n;
	for (int i = 1; i <= n; i++) // ���� �Է�
		cin >> a[i];

	int p = 1; // �������� ������ �ε���
	int max = 1;
	for (int i = 1; i <= n; i++)
	{
		d[i] = 1; // ��� d[i]�� �ʱⰪ�� 1
		v[i] = -1; // �ʱⰪ�� -1
		for (int j = 1; j < i; j++)
		{										// ������ ������ ���� �� ũ�鼭
			if (d[i] < d[j] + 1 && a[i] > a[j]) // i���� ���� LIS�߿��� ���� �� LIS�� 1�� ���ϸ� d[i]
			{
				d[i] = d[j] + 1;
				v[i] = j; // ����Ǵ� �ε����� ���� / ��, d�� ���� ��� �ε����� ���� ���ϴ��� ����
			}
		}
		if (max < d[i]) // ��� d[i] �� �ִ��� ����
		{
			max = d[i];
			p = i; // �ִ��� ������ �ε������� ������ ����
		}
	}
	cout << max << '\n';
	go(p);
	cout << '\n';
}

void go(int p) // ������ �Լ�
{
	if (p == -1)
		return;
	go(v[p]);
	cout << a[p] << ' '; // �������� a�� ���
}