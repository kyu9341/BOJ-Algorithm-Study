#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int alphabet[26] = {0}; // �� ���ĺ� ������ ���� �迭

	cin >> str;
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		alphabet[str[i] - 'a']++; // 'a'�� �ƽ�Ű �ڵ� ���� ���־� �ش��ϴ� ���ĺ��� �ε����� ������
	}
	
	for (auto x : alphabet)
		cout << x << ' ';

	cout << '\n';

	return 0;
}