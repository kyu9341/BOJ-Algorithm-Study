#include<iostream>
#include<algorithm>
using namespace std;
int tri[501][501];
int d[501][501]; // d[i][j] = 크기가 i인 삼각형의 최대가 되는 경로에 있는 수의 합, j는 현재 인덱스
	// 즉, d[i][j] = i행 j열 이 선택되었을 때, 최대 합
int main(void)
{
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> tri[i][j];
	
	d[1][1] = tri[1][1]; // 초기값 지정

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++) 
		{
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + tri[i][j]; // 좌측 상단과 우측 상단의 값 중 큰 값에 현재 값을 더함
		}
	}

	int maxSum = 0;
	for (int i = 1; i <= n; i++)
	{
		maxSum = max(maxSum, d[n][i]);
	}
	cout << maxSum << '\n';
}