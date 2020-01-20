#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main()
{
	string input; // �Է� ���ڿ� 
	stack<char> s;

	getline(cin, input);
	int size = input.size();
	int raser[100000] = {}; // ����⿡ �߻�� �������� ��
	int res = 0;

	for (int i = 0; i < size; i++)
	{
		if (input[i] == '(' && input[i + 1] == ')') // �������� ���
		{
			for (int j = 1; j <= s.size(); j++)
			{
				raser[j]++; // ������ ������(������ ����� ��) ��� 1�� ����
			}
			i++; // ���� �� ���� Ȯ�������� ��ĭ �Ѿ
		}
		else // ������� ���� or ���� ���
		{
			if (input[i] == '(')
			{
				s.push(input[i]);
			}
			else if (input[i] == ')') // ��ȣ�� ���� �� ����
			{
				res += raser[s.size()] + 1; // �ϳ��� ����⿡�� n + 1���� ������ ����
				raser[s.size()] = 0; // �ʱ�ȭ
				s.pop();
			}
		}

	}
	
	cout << res << '\n';


	return 0;
}