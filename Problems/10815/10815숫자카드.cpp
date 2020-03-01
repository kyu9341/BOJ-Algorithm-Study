#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 500000;
int a[MAX];
int n, m; // 가지고 있는 카드의 개수 n, 찾아야 할 카드의 개수 m

bool find(int num) // 이분 탐색으로 원소가 존재하는지 판단
{
	int left = 0;
	int right = n - 1;

	while (left <= right) // left > right 가 되면 종료
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			return true;
		}
		else if (a[mid] > num) // 중간 원소보다 작으면 오른쪽 절반을 날림
		{
			right = mid - 1;
		}
		else if (a[mid] < num) // 중간 원소보다 크면 왼쪽 절반을 날림
		{
			left = mid + 1;
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		if (find(num))
			cout << '1';
		else
			cout << '0';
		if(i != m - 1)
			cout << ' ';
	}
	cout << '\n';
}