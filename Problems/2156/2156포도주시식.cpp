#include<iostream>
#include<algorithm>
using namespace std;
int d[10001][3]; // d[i][j] = i번째 포도주까지의 최대 마시는 양, a[i]는 j번째 연속해서 마신 포도주
int a[10001];
int main(void)
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	for (int i = 1; i <= n; i++)
	{
		d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] }); // 마시지 않은 경우 이전 값들 중 최댓값 저장
		d[i][1] = d[i - 1][0] + a[i]; // 한 번 연속해서 마시는 경우 마시지 않은 상태에 현재 인덱스의 포도주 양을 추가
		d[i][2] = d[i - 1][1] + a[i]; // 두 번째 연속해서 마시는 경우 한 번 연속해서 마신 상태에 현재 인덱스의 포도주 양 추가
	}

	cout << max({ d[n][0], d[n][1], d[n][2] });
}