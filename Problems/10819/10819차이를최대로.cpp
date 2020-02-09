#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int calculation(vector<int>& a, int n);

int main(void)
{
	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 0;
	do
	{
		int temp = calculation(a, n); // ��� ��츦 Ž���� �ִ��� ���Ѵ�.
		if (ans < temp)
			ans = temp;
	} while (next_permutation(a.begin(), a.end()));
	cout << ans << '\n';
}

int calculation(vector<int>& a, int n) // |A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]| �� �����ִ� �Լ�
{
	int result = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int temp = a[i] - a[i + 1];
		if (temp < 0) temp = -temp;
		result += temp;
	}
	return result;
}
