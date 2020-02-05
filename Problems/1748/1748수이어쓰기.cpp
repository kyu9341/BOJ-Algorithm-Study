#include<iostream>
#include<cmath>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++)
	{	// start�� *10�� �����ϹǷ� 10, 100, 1000 .. (�ڸ����� ����)
		int end = start * 10 - 1; // end�� 99, 999, 9999 ... (�ڸ����� ������)
		if (end > n) // �Է� ������ Ŀ����
			end = n;
		ans += (long long)(end - start + 1) * len; // �ڸ����� ������ �ڸ����� ����
	}
	cout << ans << '\n';
}