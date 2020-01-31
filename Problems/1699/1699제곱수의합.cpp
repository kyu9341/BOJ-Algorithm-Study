#include<iostream>
#include<vector>
using namespace std;
// int d[100001];
int main(void)
{
	int n;
	cin >> n;

	vector<int> d(n + 1);
	// (n - i^2) + i^2 = n -> d[n] =  n - i^2�� �ּ� ���� + 1
	for (int i = 1; i <= n; i++)
	{
		d[i] = i; // ��� 1^2���� ǥ���ϴ� ��찡 �ִ�
		for (int j = 1; j*j <= i; j++) // d[n] = min(d[n - i*i]) + 1
		{
			if (d[i] > d[i - j * j] + 1)
				d[i] = d[i - j * j] + 1;
		}
		
	}
	cout << d[n] << '\n';
}