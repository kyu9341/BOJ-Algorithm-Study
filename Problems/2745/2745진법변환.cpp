#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main(void)
{
	int b; // b����
	string n; // �� n

	cin >> n;
	cin >> b;

	int result = 0;

	for (int i = n.size() - 1, j = 1; i >= 0; i--, j*=b) // b���� �� n�� �ڿ������� Ȯ��, j�� �ڸ����� ���� ��������
	{
		if((int)(n[i] -'0') < 10)
			result += (int)(n[i] - '0') * j; // ����ȯ �� ����
		else
		{
			result += ((int)(n[i] - 'A') + 10) * j; // 10���� ū ��� ó��
		}
	}
	cout << result << '\n';
}