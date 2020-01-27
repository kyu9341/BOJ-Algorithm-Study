#include<iostream>

using namespace std;
const int MAX = 1000000;
int prime[MAX]; // �Ҽ��� ���� �迭
bool check[MAX + 1]; // �ε����� �Ҽ��̸� false�� �迭
int pn = 0; // �Ҽ��� ����
int main(void)
{
	int n; // testcase
	cin >> n;
	check[1] = true; // 1�� �Ҽ��� �ƴ�

	for (int i = 2; i < MAX; i++) // �����佺�׳׽��� ü
	{
		if (check[i] == false) // ���� (�Ҽ��� �ƴ϶��)�Ǻ����� �ʾҴٸ�
		{
			prime[pn++] = i; // �Ҽ��̸� prime�� ����
			for (int j = i + i; j < MAX; j += i) // i*i�� �ϸ� ���� ������ ��� �� ���� 
			{
				check[j] = true; // �Ҽ��� ����� ��� ����
			}
		}
	}

	while (n--)
	{
		int num;
		cin >> num;

		int count = 0; // ��Ƽ�� ��
		for (int i = 0; prime[i] < num; i++) // �Ҽ��� ���� �Է� �� ���� ��������
		{
			if (!check[num - prime[i]]) // n - b = a(�Ҽ�)���
			{
				// cout << num << " = " << num - prime[i] << " + " << prime[i] << '\n';
				count++;
			}
		}
		if (!check[num / 2]) // num / 2 �� �Ҽ���� - ��, 6 = 3 + 3 �� ���� �ߺ��� �߻����� �ʴ� ��Ƽ���� �����ϴ� ���
			cout << count / 2 + 1 << '\n'; // �ߺ��� �����ϰ� 1�� ����
		else
			cout << count / 2 << '\n'; // �ߺ� ����
		
	}
}