#include<iostream>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	int i = 2; // 2���� ��������
	while(true)
	{
		if (n % i == 0) // ������ �������� i ���
		{
			cout << i << '\n';
			n /= i;
		}
		else
			i++; // �������� ������ 1�� ����
		
		if (i > n || n == 0) 
			break;

	}
}