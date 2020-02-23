#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>

using namespace std;
const int MAX = 1000;
int d[MAX + 1][MAX + 1]; // d[s][clipboard]�� ���¿� �Ǳ� ���� �ɸ��� �ð�(��)

int main(void)
{
	int n;
	cin >> n; // ������ �� �̸�Ƽ�� ��

	memset(d, -1, sizeof(d)); // -1�� �ʱ�ȭ : -1�� �湮�ϱ� ��

	queue<pair<int, int>> q; // s, clipboard
	q.push(make_pair(1, 0));
	d[1][0] = 0; // �ʱⰪ, �̸�Ƽ�� ���� 1, Ŭ�����忡�� 0��, �ɸ��� �ð� 0��

	while (!q.empty())
	{
		int s = q.front().first;
		int c = q.front().second;
		q.pop();

		if (d[s][s] == -1) // �����ϴ� ���, Ŭ�����忡 s�� �����Ѵ�.
		{ // �̸�Ƽ�� ���� s���̰� Ŭ�����忡 s���� �ִ°�츦 Ž������ �ʾҴٸ�
			q.push(make_pair(s, s));
			d[s][s] = d[s][c] + 1; // ���� ���¿��� 1�ʸ� �߰�
		}
		
		if (s + c <= n && d[s + c][c] == -1) // �ٿ��ֱ⸦ �ϴ� ���
		{
			q.push(make_pair(s + c, c)); // ȭ�鿡 c���� �̸�Ƽ���� �߰���
			d[s + c][c] = d[s][c] + 1;
		}

		if (s - 1 >= 0 && d[s - 1][c] == -1) // �̸�Ƽ�� �ϳ��� �����ϴ� ���
		{
			q.push(make_pair(s - 1, c));
			d[s - 1][c] = d[s][c] + 1;
		}
	
	}

	int ans = -1;
	for (int i = 0; i <= n; i++) 
	{
		if (d[n][i] != -1) // -1�� �ƴ� �ּڰ��� ���Ѵ�.
		{
			if (ans == -1 || ans > d[n][i])
				ans = d[n][i];
		}
	}
	

	cout << ans << '\n';
	
}