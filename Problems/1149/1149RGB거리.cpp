#include<iostream>
#include<algorithm>
using namespace std;

int rgb[1001][3];
int d[1001][3]; // d[i][j] = i�� ���� �� j�� ĥ���� ��, 1~i�� ���� ĥ�ϴ� ����� �ּڰ�

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) // �� ���� ���� ��� �Է�
		for (int j = 0; j < 3; j++)
			cin >> rgb[i][j];

	for (int i = 1; i <= n; i++) // ��������� �ּ� ��뿡 ���� ���� ����� �߰�
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + rgb[i][0]; // r�� �տ� �� �� �ִ� ���� g, b
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + rgb[i][1]; // g�� �տ� �� �� �ִ� ���� r, b
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + rgb[i][2]; // b�� �տ� �� �� �ִ� ���� r, g
	}

	cout << min({ d[n][0], d[n][1], d[n][2] }) << '\n';
}