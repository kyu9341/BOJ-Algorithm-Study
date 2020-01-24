#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	int res = 1;
	for (int i = n; i > 0; i--)
	{
		res *= i;
	}
	cout << res << '\n';
}