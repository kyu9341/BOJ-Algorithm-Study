#include<iostream>

using namespace std;

int main(void)
{
	int n; // test case ��
	cin >> n;
	int count = 0; // �Ҽ��� ����
	while (n--)
	{
		int num;
		bool check = true;
		cin >> num;
		if (num == 1) check = false; // 1�� �Ҽ��� �ƴ�
		for (int i = 2; i*i <= num; i++) // ��Ʈ n ������ Ȯ���Ͽ� ������������ ������ �Ҽ�
		{
			if (num % i == 0)
				check = false;
		}
		if (check)
			count++;
	}
	cout << count << '\n';

}