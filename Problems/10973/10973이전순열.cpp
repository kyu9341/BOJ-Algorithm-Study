#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	bool ok = prev_permutation(a.begin(), a.end()); // ���� ������ ������ false����
	if (ok)
	{
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
	}
	else
		cout << -1;
	
	cout << '\n';
}