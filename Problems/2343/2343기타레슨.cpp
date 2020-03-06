#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
const int MAX = 100000;
int a[MAX + 1];
int n, m;

bool check(int blue) // 크기가 blue인 블루레이로 녹화하면 m개 이하의 블루레이가 나오는지 판별
{
	int sum = 0;
	int cnt = 1; // 마지막 그룹 카운트
	for (int i = 0; i < n; i++)
	{
		if (sum + a[i] <= blue) // 지금까지의 수를 더하면 블루레이 크기보다 큰지 확인
			sum += a[i];
		else // 블루레이 크기보다 크다면
		{
			sum = a[i]; // 지금까지 합 초기화, 새로 시작
			cnt++; // 블루레이 개수 + 1
		}
	}
	return cnt <= m; // 현재 블루레이 크기로 개수를 맞출 수 있는지 판별
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}	
		
	int left = *max_element(a, a + n); // 레슨 크기의 최댓값(적어도 하나의 레슨을 담아야 함)
	int right = sum;
	int ans = sum;

	while (left <= right) // 블루레이 크기를 기준으로 이분 탐색
	{
		int mid = (left + right) / 2; // 블루레이의 크기
		if (check(mid)) // 현재 블루레이의 크기로 가능하다면
		{
			if (ans > mid)
				ans = mid;
			right = mid - 1; // 가능한 최솟값이 있는지 확인
		}
		else
			left = mid + 1; // 블루레이 크기를 키워서 확인
	}
	cout << ans << '\n';
}