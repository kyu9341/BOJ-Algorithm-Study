#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<utility>


using namespace std;
int r, c;
int ans = 0;

void zigzag(int x, int y, int n) // ������׷� �湮�ϴ� �Լ�
{
	if (n == 2) // 2�� 2���� �� ���
	{
		for(int i = x; i < x + n; i++)
			for (int j = y; j < y + n; j++)
			{
				if (i == r && j == c) // r, c�� �����ϸ� ��� �� ����
				{
					cout << ans << '\n';
					return;
				}
				ans++; // 1�� ����
			}
		return;
	}

	int m = n / 2;
	for (int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			zigzag(x + m * i, y + m * j, m); // n / 2�� �ǳʶٸ� ���

}

int main(void)
{
	int n;
	cin >> n >> r >> c;
	n = (1 << n);
	zigzag(0, 0, n); // 0, 0 ���� Ž�� n�� 2^n
}