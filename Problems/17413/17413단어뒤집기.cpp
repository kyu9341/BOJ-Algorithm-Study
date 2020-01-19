#include<iostream>
#include<string>
#include<stack>

using namespace std;

void sprint(stack<char>& s) // ������ ����� ������ ����ϴ� �Լ�
{
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}

int main()
{
	string str; // �Է� ���ڿ�
	stack<char> s;

	getline(cin, str);
	bool tag = false; // �±� �������� �˻�

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '<') // '<'�� ������ ������ ������� �ʴٸ� ������ ��� ���
		{
			sprint(s);
			cout << str[i];
			tag = true; // �±� ���� �Ǵ�
		}
		else if (str[i] == '>')
		{
			cout << str[i];
			tag = false;
		}
		else if(tag)
		{
			cout << str[i]; // �±� ������ ��� �״�� ���
		}
		else
		{
			if (str[i] == ' ') // ������ ���� ��� ������ ���
			{
				sprint(s);
				cout << str[i]; // ���� ���
			}
			else
				s.push(str[i]); // �ƴ϶�� ���ÿ� push
		}

	}
	sprint(s); // ������ �����ִٸ� ��� ���
	cout << '\n';

	return 0;
}