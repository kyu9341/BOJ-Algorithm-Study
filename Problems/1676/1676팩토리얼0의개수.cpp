#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	// ���丮���� 0�� ������ n!�� ���μ������Ͽ� ���� 2�� 5�� ������ ���� �� �ִ�.
	// n!������ 2�� ������ �׻� 5�� �������� �����Ƿ� 5�� ������ �����ش�.
	int n;
	cin >> n;
	int count = 0;
	
	for (int i = n; i > 0; i--)
	{
		int tmp = i;
		while (tmp % 5 == 0) // 5�� ���� count
		{
			tmp /= 5; // 5�� �ϳ� �̻� ���ڷ� ������ �� ó��
			count++;
		}
	}
	cout << count << '\n';
}