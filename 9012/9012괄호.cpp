#include<iostream>
#include<string>
#include<stack>

using namespace std;
string distinction(string str);

int main()
{
	int n; // �׽�Ʈ ���̽� ��
	string str; // �Ǻ��� ���ڿ�

	cin >> n;
	cin.ignore();

	while (n--)
	{
		getline(cin, str);
		cout << distinction(str) << '\n';
	}
	
	return 0;
}

string distinction(string str) // ���ڿ��� VPS���� �Ǻ��ϴ� �Լ�
{
	stack<char> s;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(') // '(' �� ��� push
		{
			s.push(str[i]);
		}
		else
		{
			if (s.empty()) // �� ���ÿ� ')' �� �Էµ� ��� NO ����
			{
				return "NO";
			}
			s.pop(); // �� ������ �ƴϸ� pop
		}
	}
	if (s.empty()) // �ݺ����� ������ �� �����̶�� VPS�� �´�
		return "YES"; 
	else
		return "NO";
}