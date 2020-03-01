#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 1000000;
int a[MAX];
int b[MAX];
int res[MAX * 2];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i];

	int idx_res = 0; // res의 인덱스
	int idx_a = 0, idx_b = 0; // a와 b의 인덱스

	while (idx_a < n && idx_b < m) // a와 b 중 하나가 모두 확인했다면 나온다.
	{
		if (a[idx_a] < b[idx_b]) // a와 b의 원소 중 작은 것을 먼저 res에 저장
			res[idx_res++] = a[idx_a++];
		else
			res[idx_res++] = b[idx_b++];
	}
	
	while (idx_a < n) // 아직 a와 b중 모든 원소를 확인하지 못한 배열은 나머지 원소를 그대로 res에 삽입
		res[idx_res++] = a[idx_a++]; // 이미 정렬된 a, b이므로
	while (idx_b < m)
		res[idx_res++] = b[idx_b++];

	for (int i = 0; i < idx_res; i++)
		cout << res[i] << ' ';
	cout << '\n';

}