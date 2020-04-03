#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
string s, t;

string eraseB(string t) // �� �� �ڸ��� B�� ����� ���ڿ��� ������ �Լ�
{
	t.erase(t.begin(), t.begin() + 1);
	reverse(t.begin(), t.end());
	return t;
}
string eraseA(string t) // ������ �ڸ��� A�� ����� �Լ�
{
	t.erase(t.end() - 1, t.end());
	return t;
}

void go(string str)
{
	int size_str = str.size();
	if (s.size() == size_str) // �� ���ڿ��� ũ�Ⱑ ���ٸ�
	{
		if (s == str) // ���ڿ��� ��
		{
			cout << 1 << '\n'; // ������ 1 ��� �� ����
			exit(0);
		}
		return;
	}

	if (str[0] == 'A' && str[size_str - 1] == 'B')
		return; // �� ���� A�̸鼭 �� �ڰ� B��� ������ �߸��� ���

	if (str[0] == 'B') // �� �� ���ڰ� B�� ���
		go(eraseB(str)); // B�� ����� �����´�

	if (str[size_str - 1] == 'A') // �� �� ���ڰ� A�� ���
		go(eraseA(str)); // A�� �����.
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;

	go(t);

	cout << 0 << '\n';

}