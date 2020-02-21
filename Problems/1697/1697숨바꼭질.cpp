
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1]; // �湮 ���� �Ǵ�
int sec[MAX + 1]; // n��° �������� �ð�

int main(void)
{
	int n, k;
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	sec[n] = 0; // �������� ��ġ���� ����

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (node - 1 >= 0) // x - 1�� ���
		{
			if (check[node - 1] == false)
			{
				q.push(node - 1);
				check[node - 1] = true;
				sec[node - 1] = sec[node] + 1;
			}
		}
		if (node + 1 <= MAX) //  x + 1�� ���
		{
			if (check[node + 1] == false)
			{
				q.push(node + 1);
				check[node + 1] = true;
				sec[node + 1] = sec[node] + 1;
			}
		}
		if (node * 2 <= MAX) // x * 2�� ���
		{
			if (check[node * 2] == false)
			{
				q.push(node * 2);
				check[node * 2] = true;
				sec[node * 2] = sec[node] + 1;
			}
		}
	}

	cout << sec[k] << '\n';
}
