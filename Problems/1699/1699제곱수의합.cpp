#include<iostream>
#include<vector>
using namespace std;
// int d[100001];
int main(void)
{
	int n;
	cin >> n;

	vector<int> d(n + 1);
	// (n - i^2) + i^2 = n -> d[n] =  n - i^2의 최소 개수 + 1
	for (int i = 1; i <= n; i++)
	{
		d[i] = i; // 모두 1^2으로 표현하는 경우가 최대
		for (int j = 1; j*j <= i; j++) // d[n] = min(d[n - i*i]) + 1
		{
			if (d[i] > d[i - j * j] + 1)
				d[i] = d[i - j * j] + 1;
		}
		
	}
	cout << d[n] << '\n';
}