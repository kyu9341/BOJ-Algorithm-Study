#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; // �׽�Ʈ ���̽� ��
	string str; // �Է� ���ڿ�

	cin >> n;
	cin.ignore();
	//cin.get();
	// �� �� �ϳ��� �������. cin >> n ���� getline() �Է��� ���� �� 
	// ���ۿ� �����ִ� ���๮�ڸ� ó�����־�� ������ ���� ���������� �Է��� ����

	stack<char> s;


	while (n--)
	{
		getline(cin, str); 
		str += '\n'; // std::string -> getline() �Լ��� ��� ���� �����ڸ� �ɾ���� �ʴ´ٸ� ����('\n')�ε�
		// \n ���������� �ϳ��� �Է����� �޾Ƶ��̰� \n�� ������. �� ���������� \n���� �Է����� �޾Ƶ鿩��
		// �Ʒ��� ���ǿ��� ���������� ó���� �����ϹǷ� �߰����ֵ��� ��.

		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != ' ' && str[i] != '\n') // ���⳪ ���๮�ڰ� �ƴ� ��� push
			{
				s.push(str[i]);
			}
			else
			{
				while (!s.empty()) // ���� �Ǵ� ���๮�ڸ� ���� ��� ������� ���ÿ� �Էµ� ���� ��� ��� �� pop
				{
					cout << s.top();
					s.pop();
				}
				cout << str[i]; // �Էµ� ���� or ���๮�ڸ� ���
			}

		}
	}

	return 0;
}

