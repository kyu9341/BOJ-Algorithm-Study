#include<iostream>

using namespace std;
bool broken[10];

int possible(int c)
{
	int len = 0;
	if (c == 0) // 0�϶� ����ó��(c�� 0���� �Ѿ�Դٸ� �Ʒ��� while���� ���� �����Ƿ� ���� ó��)
	{
		if (broken[c]) return 0;
		else return 1;
	}
	while (c > 0)
	{
		if (broken[c % 10]) return 0; // �μ��� ��ư�� �ִ� ��� false����
		c /= 10;
		len++; // ä���� ����
	}
	return len; // �μ��� ��ư�� ���� ��� ä���� ���̸� ����
}

int main(void)
{
	int n, m; // ä�� : n, ���峭 ��ư ���� : m
	cin >> n >> m;

	while(m--)
	{
		int temp;
		cin >> temp;
		broken[temp] = true; // ���峭 ��ư�� true
	}

	int ans = n - 100; // �ʱⰪ ���� n�� 101�̳� 102���� ��� 
			// ���� ��ư���� �̵��ϴ� �ͺ��� + �� - ������ �̵��ϴ� ���� �ּ��̱� ����
	if (ans < 0) ans = -ans;

	for (int c = 0; c <= 1000000; c++)
	{
		int len = possible(c); // �μ��� ��ư�� �ִٸ� 0, ���ٸ� ä���� ����
		if (len > 0)
		{
			int tmp = c - n; // ���ڷ� �̵��� ä�ο��� ��ǥ ä�ΰ��� ���̸� ����. �̰��� + or - ��ư���� �̵��� Ƚ��
			if (tmp < 0) tmp = -tmp; // ����
			if (ans > len + tmp) // len�� �ڸ����̹Ƿ� ���ڸ� ���� Ƚ�� 
				ans = len + tmp; // �� �۴ٸ� �ּڰ� ����
		}
	}

	cout << ans << '\n';

}