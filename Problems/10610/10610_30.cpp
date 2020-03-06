#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int main(void)
{
	string num;
	cin >> num;

	sort(num.begin(), num.end(), [](int a, int b) { // �������� ����
		return a > b;
		});

	do
	{	
		int tmp = stoi(num); // ������ ��ȯ
		if (tmp % 30 == 0) // 30�� ����̸�
		{
			cout << tmp << '\n'; // ��� �� ����
			exit(0);
		}
		// ���� ���� ������ 30�� ����� �ִ�
	} while (prev_permutation(num.begin(), num.end())); // ���� ����

	cout << -1 << '\n'; // 30�� ����� ���� ���
}