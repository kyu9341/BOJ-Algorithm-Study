#include<iostream>

using namespace std;

int main(void)
{
	int e, s, m;
	cin >> e >> s >> m;

	int E, S, M;
	E = S = M = 1; // 1씩 증가시켜 볼 변수

	int year = 1; // 우리 연도
	while (true)
	{
		if (E == e && S == s && M == m) // 일치하는 가장 빠른 년도에 끝
			break;
		E++;
		S++;
		M++;
		if (E > 15) // 15넘으면 초기화 1
			E = 1;
		if (S > 28) // 28넘으면 초기화 1
			S = 1;
		if (M > 19) // 19넘으면 초기화 1
			M = 1;
		year++;

	}
	cout << year << '\n';
}
