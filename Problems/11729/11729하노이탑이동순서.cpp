#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;

void go(int n, int from, int by, int to) // n개의 원판을 from에서 by를 거쳐 to로 이동시킴
{
	if (n == 1) cout << from << ' ' << to << '\n';
	else
	{
		go(n - 1, from, to, by); // n - 1개의 원반을 기둥 3을 거쳐 2로 옮긴다.
		cout << from << ' ' << to << '\n'; // 기둥 1에서 1개의 원반을 기둥 3으로 옮긴다.
		go(n - 1, by, from, to); // 기둥 2에서 n - 1개의 원반을 기둥 3으로 옮긴다.
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	cout << (1 << n) - 1 << '\n'; // 횟수는 2^n - 1 번

	go(n, 1, 2, 3);
}