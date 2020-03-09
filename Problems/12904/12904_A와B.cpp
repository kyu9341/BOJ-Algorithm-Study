#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

string eraseB(string t) // ������ �ڸ��� B�� ����� ���ڿ��� ������ �Լ�
{
	reverse(t.begin(), t.end());
	t.erase(t.begin(), t.begin() + 1);
	return t;
}
string eraseA(string t) // ������ �ڸ��� A�� ����� �Լ�
{
	t.erase(t.end() - 1, t.end());
	return t;
}

int main(void)
{
	string s, t;
	cin >> s >> t;
	int size_S = s.size();

	while (t.size() > size_S) // t�� s�� ũ�Ⱑ ������ ������ �ݺ�
	{
		int last_T = t.size() - 1;
		if (t[last_T] == 'A') // t�� ������ ���ڰ� A��� A�� ����
			t = eraseA(t);
		else if (t[last_T] == 'B') // B��� B�� ����� ������
			t = eraseB(t);

	}

	if (t == s) cout << 1 << '\n'; // ũ�Ⱑ �������� ��, ���ڿ��� ���ٸ� s�� t�� �ٲ� �� ����
	else cout << 0 << '\n';

}