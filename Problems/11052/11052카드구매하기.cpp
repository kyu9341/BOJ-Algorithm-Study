#include<iostream>

using namespace std;
int d[1001];
int p[10001];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> p[i]; // Pi ют╥б
	
	for (int i = 1; i <= n; i++) // d[n] = max(d[n - i] + p[i]) (1 <= i <= n)
	{ 
		for (int j = 1; j <= i; j++)
		{
			int temp = d[i - j] + p[j];
			if (d[i] < temp)
				d[i] = temp;
		}

	}
	cout << d[n] << '\n';
}