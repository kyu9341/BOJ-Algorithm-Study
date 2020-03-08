#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>

using namespace std;

int alpha[26]; // ���ĺ��� �ش��ϴ� ���ڸ� ������ �迭
int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
	int m = letters.size(); // �ߺ����� ���ĺ��� ��
	int sum = 0;
	for (int i = 0; i < m; i++) {
		alpha[letters[i] - 'A'] = d[i]; // A : 0 ���� �ش��ϴ� ���ĺ��� ���� ����
	}
	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x - 'A']; // ���ĺ��� �ش��ϴ� ���ڸ� ������ ���
		}
		sum += now; // �� ���ڿ� ����
	}
	return sum;
}

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	vector<string> a(n);
	vector<char> letters;

	while (n--)
	{
		string str;
		getline(cin, str);
		a.push_back(str);		
		for (int i = 0; i < str.size(); i++)
			letters.push_back(str[i]); // ���ڿ��� ��� ���ڸ� ����
	}
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end()); // ������ �ߺ� ���� ����
	// �ߺ��� ������ �� ������ ũ��� �Էµ� ������ �� ����
	int m = letters.size();
	vector<int> d; // �� ���ڿ� ������ ���ڸ� ����
	for (int i = 9; i > 9 - m; i--) // ���� �ִ�� ����� ���� ���� ū ������ ������ ũ�⸸ŭ �߰�
		d.push_back(i);

	int ans = 0;
	do
	{
		int now = calc(a, letters, d);
		if (ans < now) ans = now;
	} while (prev_permutation(d.begin(), d.end())); // 9���� ���������Ƿ� ���� ������ Ȯ��

	cout << ans << '\n';
}