#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			
			if (str[i] + 13 > 'z') // �ƽ�Ű �ڵ�� 127������ �ִµ� s�̻��� ���ĺ��� 13�� ���ϸ� ������ ���
				cout << char(str[i] - 13); // �Ѿ�� �ʴ� ������ ó��
			else
				cout << char(str[i] + 13);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] + 13 > 'Z')
				cout << char(str[i] - 13);
			else
				cout << char(str[i] + 13);

		}
		else
		{
			cout << str[i];
		}
	}
}