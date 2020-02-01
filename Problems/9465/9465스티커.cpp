
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int score[2][100002];
int d[3][100001]; // d[i][j] = 2j ������ ������ �ִ밪 (i = 0 �� ���� ��ƼĿ�� ���� �ʴ� ���, i = 1, i = 2�� ���� �̹��� �� ��ƼĿ�� ��)
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; //testcase
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				cin >> score[i][j]; // �Է�

		for (int j = 1; j <= n; j++)
		{
			d[0][j] = max({ d[0][j - 1], d[1][j - 1], d[2][j - 1] }); // �̹� ���� �ƹ��͵� ���� ���� ���
			d[1][j] = max({ d[0][j - 1], d[2][j - 1] }) + score[1][j]; // �̹� ���� 1���� ��ƼĿ�� ���� ���
			d[2][j] = max({ d[0][j - 1], d[1][j - 1] }) + score[0][j]; // �̹� ���� 2���� ��ƼĿ�� ���� ���			
		}

		cout << max({ d[0][n], d[1][n], d[2][n] }) << '\n';

	}
}