#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

void go(int n, int from, int by, int to) // n���� ������ from���� by�� ���� to�� �̵���Ŵ
{
	if (n == 1) cout << from << ' ' << to << '\n';
	else
	{
		go(n - 1, from, to, by); // n - 1���� ������ ��� 3�� ���� 2�� �ű��.
		cout << from << ' ' << to << '\n'; // ��� 1���� 1���� ������ ��� 3���� �ű��.
		go(n - 1, by, from, to); // ��� 2���� n - 1���� ������ ��� 3���� �ű��.
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // Ƚ���� 2^n - 1 ��

	go(n, 1, 2, 3);
}