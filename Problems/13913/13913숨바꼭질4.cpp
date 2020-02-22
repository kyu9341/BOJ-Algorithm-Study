#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>

using namespace std;
const int MAX = 100000;
bool check[MAX + 1];
int sec[MAX + 1];
int record[MAX + 1]; // ��� ���İ����� ����� �迭
stack<int> s;
int n, k;

void print_record(int k)
{
	if (record[k] == -1) // ó�� ��ġ�� ã����
	{
		s.push(n); // �������� ��ġ
		while (!s.empty())
		{
			cout << s.top() << ' '; // ������ ���� ��� ���
			s.pop();
		}
		cout << '\n';
		return;
	}
	s.push(k); // ���ÿ� �־� ������ ���
	print_record(record[k]);
}

int main(void)
{
	cin >> n >> k;

	queue<int> q;
	q.push(n);
	check[n] = true;
	sec[n] = 0; // �������� ��ġ���� ����
	record[n] = -1; // �ʱ� ��ġ ���� 0�����ϸ� 0���� �����ϴ� ��쿡 ���ܹ߻�

	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		if (node - 1 >= 0)
		{
			if (check[node - 1] == false) // x - 1�� ���
			{
				q.push(node - 1);
				check[node - 1] = true;
				sec[node - 1] = sec[node] + 1;
				record[node - 1] = node; // ���� ��ġ�� ����Ѵ�.
			}
		}
		if (node + 1 <= MAX)
		{
			if (check[node + 1] == false) // x + 1�� ���
			{
				q.push(node + 1);
				check[node + 1] = true;
				sec[node + 1] = sec[node] + 1;
				record[node + 1] = node;
			}
		}
		if (node * 2 <= MAX)
		{
			if (check[node * 2] == false) // x * 2�� ���
			{
				q.push(node * 2);
				check[node * 2] = true;
				sec[node * 2] = sec[node] + 1;
				record[node * 2] = node;
			}
		}

	}

	cout << sec[k] << '\n';
	print_record(k);
}
