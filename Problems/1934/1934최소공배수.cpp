#include<iostream>

using namespace std;

int GCD(int, int);

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; // �׽�Ʈ ���̽� ��
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		int gcd = GCD(a, b);
		int lcm = (a * b) / gcd; // a*b = gcd * lcm ���� ����

		cout << lcm << '\n';
	}

}

int GCD(int a, int b) // �ִ� ����� ���ϴ� �Լ�
{
	if (b == 0) // ��Ŭ���� ȣ���� - GCD(a, b) -> a%b = r
		return a; // GCD(b, r) -> r = 0 �϶�, b�� �ִ�����
	else return GCD(b, a % b);
}