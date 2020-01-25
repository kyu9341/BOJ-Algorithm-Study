#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) // ��Ŭ���� ȣ����
{
	if (b == 0)	return a;
	else return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		long long sum = 0; // long long������ ����

		// �ϳ��� �׽�Ʈ ���̽��� ���Ҹ� ������ ���� ����
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				sum += gcd(v[i], v[j]);   // �ִ����� : ��Ŭ���� ȣ���� ���

		cout << sum << '\n';
	}
}