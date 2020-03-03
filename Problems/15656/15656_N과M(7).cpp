#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<queue>
#include<string>

using namespace std;
int a[10];
int out[10]; // 출력 배열

void go(int n, int m, int index)
{
	if (index == m) // index가 m이 되면 out배열 모두 출력
	{
		for (int i = 0; i < m; i++)
		{
			cout << out[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}
		

	for (int i = 0; i < n; i++) // 중복 허용
	{
		out[index] = a[i];
		go(n, m, index + 1);
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	go(n, m, 0);
}