#include<iostream>

using namespace std;
bool check[10]; // 사용한 수인지 체크
int a[10]; // 결과를 저장할 배열

void go(int index, int n, int m) // index : 0, 1, 2, .. , m - 1 까지 일때 현재 인덱스
{
	if (index == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << a[i]; // 출력
			if (i != m - 1) cout << ' ';
		}
		cout << '\n';
		return;
	}
		
	for (int i = 1; i <= n; i++)
	{
		if (check[i]) continue; // 중복 제거
		check[i] = true; // 이미 뽑은 것은 true
		a[index] = i;
		go(index + 1, n, m); // 인덱스를 1증가시키고 재귀
		check[i] = false;
	}
	
}

int main(void)
{ 
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	go(0, n, m);
}