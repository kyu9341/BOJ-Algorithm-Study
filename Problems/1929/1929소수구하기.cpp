#include<iostream>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	bool check[1000001] = { false }; // 각 숫자의 소수 여부를 체크할 bool배열
	int m, n; // 소수 범위 (1 ≤ M ≤ N ≤ 1,000,000)
	cin >> m >> n;
	check[1] = true; // 1은 소수가 아님
	//  에라토스테네스의 체
	for (int i = 2; i*i <= n; i++) // i^2이 n을 넘어가면 i의 배수는 이미 모두 지워짐
	{
		if(!check[i])
			for (int j = i; j*i <= n; j++) // i*i이상의 i의 배수를 모두 지워줌
			{
				if (i * j > 1000000)
					break;
				check[i * j] = true; // 소수가 아니면 true
	
			}
	}
	for (int i = m; i <= n; i++)
	{
		if (!check[i])
			cout << i << '\n';
	}
	
}