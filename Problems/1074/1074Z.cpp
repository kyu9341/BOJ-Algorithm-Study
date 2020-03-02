#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<utility>


using namespace std;
int r, c;
int ans = 0;

void zigzag(int x, int y, int n) // 지그재그로 방문하는 함수
{
	if (n == 2) // 2행 2열이 된 경우
	{
		for(int i = x; i < x + n; i++)
			for (int j = y; j < y + n; j++)
			{
				if (i == r && j == c) // r, c에 도착하면 출력 후 리턴
				{
					cout << ans << '\n';
					return;
				}
				ans++; // 1씩 증가
			}
		return;
	}

	int m = n / 2;
	for (int i = 0; i < 2; i++)
		for(int j = 0; j < 2; j++)
			zigzag(x + m * i, y + m * j, m); // n / 2씩 건너뛰며 재귀

}

int main(void)
{
	int n;
	cin >> n >> r >> c;
	n = (1 << n);
	zigzag(0, 0, n); // 0, 0 부터 탐색 n은 2^n
}