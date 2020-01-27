#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	int n; // �Է� 10���� ��
	int b; // b����
	cin >> n >> b;
	string result = ""; // ��� ���ڿ�
	
	while (n > 0)
	{
		int r = n % b; // remainder
		if (r < 10)
			result += (char)(r + '0'); // ����ȯ
		else
			result += (char)(r - 10 + 'A'); // 10 �̻��� ���� ��� �ƽ�Ű �ڵ�� ��ȯ(A~Z)
		n /= b; // ���� 0���� ũ�ٸ� ��� ����
	}

	reverse(result.begin(), result.end()); // ��� ���ڿ��� ������ ���
	cout << result << '\n';
}