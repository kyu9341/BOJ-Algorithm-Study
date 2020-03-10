#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
int n, m;

int gapMaxMin(vector<int>& k)
{
	auto p = minmax_element(k.begin(), k.end());
	return *p.second - *p.first;
}

bool calc(vector<int>& a, int mid)
{
	vector<int> tmp;
	int cnt = 1; // 구간의 개수(마지막 구간 + 1)
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(a[i]);
		int gap = gapMaxMin(tmp); // 구간 점수의 최댓값
		if (gap > mid) // 현재 구간 점수보다 큰 경우
		{ 
			cnt++; // 구간 수 + 1
			tmp.clear(); // 구간 초기화
			tmp.push_back(a[i]);
		}
	}
	return cnt <= m; // m개 이하의 구간으로 나눌 수 있는지
}

int main(void)
{
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int right = *max_element(a.begin(), a.end()); // 배열의 최댓값
	int left = 0; 
	int ans = right;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		
		if (calc(a, mid)) // 가능한 경우 
		{
			if(ans > mid)
				ans = mid;
			right = mid - 1; // 가능한 최솟값 확인
		}
		else
			left = mid + 1;

	}
	cout << ans << '\n';
}