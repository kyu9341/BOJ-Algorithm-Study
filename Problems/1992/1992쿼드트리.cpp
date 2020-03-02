#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>

using namespace std;
int a[100][100];
string ans = "";

bool check(int x, int y, int n) // ũ�Ⱑ n * n�� ������ Ȯ���ϴ� �Լ�
{
	for(int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
		{
			if (a[x][y] != a[i][j])
				return false;
		}
	return true;
}

void go(int x, int y, int n)
{
	if (check(x, y, n)) // ���� ũ���� ���� Ȯ��
	{
		ans += a[x][y]; // ��� 0�Ǵ� 1�θ� �̷�����ִٸ� ��� ���ڿ��� ����
		return;
	}
	else
	{
		ans += '('; // �ܰ迡�� ��ȣ ����
		int m = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				go(x + m * i, y + m * j, m); // 4���� �Ͽ� ���
			}
		ans += ')';
	}
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
			a[i][j] = str[j];
	}

	go(0, 0, n);
	cout << ans << '\n';
}