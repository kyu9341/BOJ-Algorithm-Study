#include<iostream>
#include<algorithm>
#include<vector>
#include<climits> // INT_MAX ���

using namespace std;
int w[11][11];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> w[i][j];

	vector<int> d(n);
	for (int i = 0; i < n; i++) // next_permutation�� ����ϱ� ���� �迭
		d[i] = i; // �ε����� �����ϱ� ���� ���

	int ans = INT_MAX;
	do {
		int sum = 0;
		bool ok = true; // ���� �ִ� ���
		for (int i = 0; i < n - 1; i++)
		{
			if (w[d[i]][d[i + 1]] == 0) ok = false; // �̾����� ���� ���� ���
			else
				sum += w[d[i]][d[i + 1]]; // ���� ������ ��� ����
		}
		if (ok && w[d[n - 1]][d[0]] != 0) // �������� ���(��� ���� �ְ� ���������� ���ư��� �浵 �ִ� ���)
		{
			sum += w[d[n - 1]][d[0]]; // ������ ���ư��� �� ����
			ans = min(ans, sum);
		}

	} while (next_permutation(d.begin(), d.end()));

	cout << ans << '\n';
}
