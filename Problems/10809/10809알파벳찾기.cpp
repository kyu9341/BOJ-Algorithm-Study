#include<iostream>
#include<string>

using namespace std;

int main()
{
	int alphabet[26]; // ���ĺ��� ó�� ���� ��ġ�� ������ �迭
	string str;

	for (auto& x : alphabet) // ��� ���� -1�� �ʱ�ȭ
		x = -1;

	cin >> str;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (alphabet[str[i] - 'a'] != -1) // -1 ��, ������ �����ߴ� ���ĺ��� ��� �Ѿ(ó�� ��ġ�� ���ϴ� ���̹Ƿ�)
			continue;
		alphabet[str[i] - 'a'] = i; // �� ���ĺ��� �ش� �ε����� ���� ���ڿ��� �ε����� ����
	}

	for (auto x : alphabet)
		cout << x << ' ';
	cout << '\n';

	return 0;
}