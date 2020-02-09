#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	while (true) 
	{
		int k;
		cin >> k;
		if (k == 0) break;
		vector<int> s(k);

		for (int i = 0; i < k; i++)
			cin >> s[i];
		sort(s.begin(), s.end()); // �Է� ���� ����

		vector<int> d;
		for (int i = 0; i < 6; i++) // 1�� �̴� ��� 0�� ���� �ʴ� �����Ͽ� �ذ��Ѵ�.
			d.push_back(1);	// 6���� �����Ƿ� 1�� 6�� ����
		for (int i = 0; i < k - 6; i++)
			d.push_back(0);

		vector<vector<int>> ans; // ��� ����

		do {
			vector<int> current;
			for (int i = 0; i < k; i++)
			{
				if (d[i] == 0) continue; // 1�� �͸� ����
				current.push_back(s[i]);
			}
			ans.push_back(current);
		} while (prev_permutation(d.begin(), d.end())); // d�� 1�� ���� ���������Ƿ� ������ ����, ���� ���������� ���ϸ� �ݺ�

		for (auto v : ans) // 2�� ���� ���
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << ' ';
			cout << '\n';
		}
		cout << '\n';
	}
}