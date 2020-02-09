#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		a[i] = i + 1;

	do
	{
		for (auto x : a)
			cout << x << ' ';
		cout << '\n';
	} while (next_permutation(a.begin(), a.end()));
}