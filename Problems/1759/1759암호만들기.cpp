#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(void)
{
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) // �ĺ� ���� �Է�
		cin >> a[i];
	sort(a.begin(), a.end());

	vector<int> d;
	for (int i = 0; i < c - l; i++) // 0�� 1�� ������ �̿��� ������ ��츦 ����
		d.push_back(0);
	for (int i = 0; i < l; i++)
		d.push_back(1);

	vector<vector<char>> ans; 

	do {
		vector<char> now;
		int vowel = false; // ���� ���� ����
		int consonant = 0; // ���� ���� ī��Ʈ
		for (int i = 0; i < c; i++)
		{
			if (d[i] == 1)
			{
				if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') // ������ ���
				{
					vowel = true;
					now.push_back(a[i]);
				}
				else
				{
					consonant++; // ���� ����
					now.push_back(a[i]);
				}
					
			}	
		}
		if (vowel && consonant >= 2) // ������ �ְ� ������ 2�� �̻��� ��쿡�� �߰�
			ans.push_back(now);
	} while (next_permutation(d.begin(), d.end()));

	sort(ans.begin(), ans.end()); // ������ ���
	for (auto &v : ans)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
		cout << '\n';
	}
}