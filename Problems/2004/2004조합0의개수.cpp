#include<iostream>
#include<algorithm>

using namespace std;

pair<long long, long long> zeros(long long n)
{
	long long two = 0;
	long long five = 0;
	for (long long i = 5; i <= n; i *= 5) // 5�� ���� ī��Ʈ
		five += n / i;
	for (long long i = 2; i <= n; i *= 2) // 2�� ���� ī��Ʈ
		two += n / i;
	return {two, five};
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	pair<long long, long long> resM, resN, resNM;
	long long two = 0, five = 0;
	resM = zeros(m);
	resN = zeros(n);
	resNM = zeros(n - m);

	two = resN.first - resM.first - resNM.first; // n�� 2�� �������� m�� (n-m)�� 2�� ������ ����
	five = resN.second - resM.second - resNM.second;  // n�� 5�� �������� m�� (n-m)�� 5�� ������ ����

	cout << min(two, five) << '\n';
	return 0;
}

