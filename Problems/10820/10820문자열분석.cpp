#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	int count[4] = { 0 }; // �� ���ڿ� ������ ī��Ʈ�� �迭

	int n = 100;

	while (n--)
	{
		getline(cin, str);
		int size = str.size();

		if (size == 0) break;  // �Է��� ���ϸ� ����

		for (int i = 0; i < size; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z') // �ҹ��� count
				count[0]++;
			else if (str[i] >= 'A' && str[i] <= 'Z') // �빮�� count
				count[1]++;
			else if (str[i] >= '0' && str[i] <= '9') // ���� count
				count[2]++;
			else if (str[i] == ' ' || str[i] == '\t') // ���� count
				count[3]++;
		}

		for (auto& x : count) // ��� �� �ʱ�ȭ
		{
			cout << x << ' ';
			x = 0;
		}

		cout << '\n';
	}

}

