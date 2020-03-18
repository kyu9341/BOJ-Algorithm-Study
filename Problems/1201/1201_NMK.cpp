#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<climits>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;

	if (n < m + k - 1 || n > m * k) // �Ұ����� ���� ó��
	{
		cout << -1 << '\n';
		return 0;
	}

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = i + 1;
	vector<int> s; // ������ ���� ������ ������ ����
	s.push_back(0); // ù ������ ����
	s.push_back(k); // ù ������ ��
	n -= k; // ���� ���� ����
	m--; // ���� ���� ��

	int q = m == 0 ? 1 : n / m; // ���� ������ ���ٸ� 1
	int r = m == 0 ? 0 : n % m;
	
	for (int i = 0; i < m; i++) // ���� ���� �� ��ŭ
	{ // r(������)�� 0�� �ɶ����� �� ������ 1�� �߰��Ѵ�.
		s.push_back(s.back() + q + (r > 0 ? 1 : 0));  // ������ ���ҿ� ���� ���� ũ�⸸ŭ ���Ͽ� �߰�
		if (r > 0) r--; // ������ ����
	}

	for (int i = 0; i < s.size() - 1; i++)
		reverse(a.begin() + s[i], a.begin() + s[i + 1]); // s�� ����� �������� ������ ������
	
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << ' ';
	cout << '\n';
}