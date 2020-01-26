#include<iostream>
#include<string>

using namespace std;
string eight[8] = { "000", "001", "010", "011", "100", "101", "110", "111" }; // 8���� 0~7 �� ���� ��µ� 2����

int main(void)
{
	string n;
	cin >> n;
	
	int size = n.size();
	bool start = true; // ù ��° �� ���� �Ǻ�

	if (n[0] - '0' == 0 && size == 1) // �Է��� 0 �ΰ�� 0��� �� ����
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < size; i++)
	{
		int position = n[i] - '0'; // ���� �ڸ��� 8����
		if (start == true && position < 4) // ù ��° �� && 4���� ���� (2����)2�ڸ��� ��� ó��
		{
			if (position == 0) // �� �տ� 0�� �Էµ� ��� ����
				continue;
			else if (position == 1)
				cout << "1";
			else if (position == 2)
				cout << "10";
			else if (position == 3)
				cout << "11";
			start = false;
		}
		else
		{
			cout << eight[position];
			start = false;
		}
			
	}
	cout << '\n';
}