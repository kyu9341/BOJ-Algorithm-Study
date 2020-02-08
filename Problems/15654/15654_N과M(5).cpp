#include<iostream>
#include<algorithm>
using namespace std;
int a[10]; // 입력 배열
int out[10]; // 출력 배열
void go(int index, int n, int m)
{
	if (m == index)
	{
		for (int i = 0; i < m; i++)
		{
			cout << out[i];
			if (i != m)	cout << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++)
	{
		out[index] = a[i];
		go(index + 1, n, m);
	}
}

int main(void)
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n); // 오름차순으로 출력하기 위해 먼저 정렬
	go(0, n, m);
	
}