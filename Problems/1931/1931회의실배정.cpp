#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
struct Meeting
{
	int begin, end;
};
bool compare(Meeting u, Meeting v) // 비교 함수
{
	if (u.end == v.end) return u.begin < v.begin; // 끝나는 시간이 같다면 시작 시간순
	else return u.end < v.end; // 끝나는 시간이 빠른 순으로 정렬
}

int main(void)
{
	int n;
	cin >> n;
	vector<Meeting> a(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i].begin >> a[i].end;
	}
	sort(a.begin(), a.end(), compare); // 회의가 끝나는 시간이 빠른 순으로 정렬

	int now = 0; // 회의가 끝난 시간
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (now <= a[i].begin) // 이전 회의가 끝난 시간과 다음 회의 시작 시간 비교
		{
			now = a[i].end; // 회의 끝난 시간 갱신
			ans++; 
		}
	}
	cout << ans << '\n';
}