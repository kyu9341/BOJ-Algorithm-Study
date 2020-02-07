#include<iostream>

using namespace std;
bool check[10];
int a[10];
void go(int index, int start, int n, int m)
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i];
			if (i != m) cout << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= n; i++)
	{
		a[index] = i;
		go(index + 1, i + 1, n, m); // 다음 반복을 시작할 수를 지정
	}				// 항상 더 큰 수가 뒤에 옴
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	go(0, 1, n, m);
}