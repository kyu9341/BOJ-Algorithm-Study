#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string init; // �ʱ� ���ڿ�
	int n; // �Է��� ��ɾ� ����
	stack<char> s1, s2; // ���� ����, ������ ����
	// Ŀ���� �� ������ �߰����� ���
	getline(cin, init);
	cin >> n;
	cin.ignore();

	for (auto x : init)
	{
		s1.push(x); // �ʱ� ���ڿ��� ���� ���ÿ� ��� push
	}

	while (n--)
	{
		string cmd;
		getline(cin, cmd);
		if (cmd == "L" && !s1.empty()) // Ŀ���� �������� �� ĭ �ű�� ���
		{
			s2.push(s1.top()); // ���� ������ top���Ҹ� ������ �������� �ű�
			s1.pop();
		}
		if(cmd == "D" && !s2.empty()) // Ŀ���� �������� �� ĭ �ű�� ���
		{
			s1.push(s2.top()); // ������ ������ top���Ҹ� ���� �������� �ű�
			s2.pop();
		}
		if (cmd == "B" && !s1.empty()) // Ŀ�� ������ ���Ҹ� ����
		{
			s1.pop();
		}
		if (cmd[0] == 'P') // Ŀ���� ���ʿ� ���� ����
		{
			s1.push(cmd[2]);
		}
	}

	while (!s1.empty()) // ������ �ֻ��� ���Һ��� ����� �����ϹǷ�
	{					// ���� �������� ���� ������ ���Ҹ� ��� �ű�
		s2.push(s1.top());
		s1.pop();
	}

	while (!s2.empty()) // ���� ���� ������ ���Ҹ� ���ʷ� ���
	{
		cout << s2.top();
		s2.pop();
	}
	cout << '\n';

	return 0;
}
