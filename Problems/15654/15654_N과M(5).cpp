#include<iostream>
#include<algorithm>
using namespace std;
int a[10]; // 입력 배열
int out[10]; // 출력 배열
bool check[10]; // 중복 체크
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
		if (check[i]) continue; // 이전에 나온 수이면 넘어감
		out[index] = a[i];
		check[i] = true; // 중복 체크
		go(index + 1, n, m);
		check[i] = false;
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