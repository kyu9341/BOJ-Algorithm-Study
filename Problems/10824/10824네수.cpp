#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string a, b, c, d;
	// ���ڿ��� �Է¹޾� ���ڿ� ���� �� ���� ��ȯ�Ͽ� ���� ���� �� ���
	cin >> a >> b >> c >> d;
	string ab; 
	ab = a + b;
	string cd;
	cd = c + d;

	long long result = stoll(ab) + stoll(cd); // ���ڿ��� long long ������ �ٲٴ� �Լ�
	// �� ���� ������ (1 �� A, B, C, D �� 1,000,000) �̹Ƿ�
	cout << result << '\n';
}