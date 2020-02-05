#include<iostream>

using namespace std;
bool broken[10];

int possible(int c)
{
	int len = 0;
	if (c == 0) // 0일때 예외처리(c가 0으로 넘어왔다면 아래의 while문에 들어가지 않으므로 따로 처리)
	{
		if (broken[c]) return 0;
		else return 1;
	}
	while (c > 0)
	{
		if (broken[c % 10]) return 0; // 부서진 버튼이 있는 경우 false리턴
		c /= 10;
		len++; // 채널의 길이
	}
	return len; // 부서진 버튼이 없는 경우 채널의 길이를 리턴
}

int main(void)
{
	int n, m; // 채널 : n, 고장난 버튼 개수 : m
	cin >> n >> m;

	while(m--)
	{
		int temp;
		cin >> temp;
		broken[temp] = true; // 고장난 버튼은 true
	}

	int ans = n - 100; // 초기값 지정 n이 101이나 102같은 경우 
			// 숫자 버튼으로 이동하는 것보다 + 나 - 만으로 이동하는 것이 최소이기 때문
	if (ans < 0) ans = -ans;

	for (int c = 0; c <= 1000000; c++)
	{
		int len = possible(c); // 부서진 버튼이 있다면 0, 없다면 채널의 길이
		if (len > 0)
		{
			int tmp = c - n; // 숫자로 이동한 채널에서 목표 채널과의 차이를 구함. 이것이 + or - 버튼으로 이동할 횟수
			if (tmp < 0) tmp = -tmp; // 절댓값
			if (ans > len + tmp) // len은 자릿수이므로 숫자를 누른 횟수 
				ans = len + tmp; // 더 작다면 최솟값 변경
		}
	}

	cout << ans << '\n';

}