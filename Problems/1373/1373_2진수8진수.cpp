#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string n;
	cin >> n;
	int size = n.size();
	if (size % 3 == 1) { // 3���� ���� �������� 1�̸� 3���� ���� ��� �� 1�ڸ��� ����
		cout << n[0]; // 1�ڸ��� ���´ٴ� ���� 1�� ���´ٴ� ���̹Ƿ� �� �տ� 1���
	}
	else if (size % 3 == 2) { // 3���� ���� ��� �� 2�ڸ��� ����
		cout << (n[0] - '0') * 2 + (n[1] - '0'); // ���� 2�ڸ� ����Ͽ� �� �տ� ���
	}
	for (int i = size % 3; i < size; i += 3) { // �������� ���� ��� ó���� �κ� �� 3���� ��� ó��
		cout << (n[i] - '0') * 4 + (n[i + 1] - '0') * 2 + (n[i + 2] - '0');
	}
	cout << '\n';
}