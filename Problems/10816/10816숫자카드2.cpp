#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;
const int MAX = 500000;
int a[MAX];
int n, m; // 가지고 있는 카드의 개수 n, 찾아야 할 카드의 개수 m

int lower_bound(int num) // 크거나 같은 수 중 첫 번째 수
{
	int ans = 0;
	int left = 0;
	int right = n - 1;

	while (left <= right) // left > right 가 되면 종료
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			ans = mid;
			right = mid - 1; // 크거나 같은 첫번째 수를 찾기 위해 왼쪽으로 이동
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

	return ans;
}

int upper_bound(int num) // num보다 큰 수 중 첫번째 수
{
	int left = 0;
	int right = n - 1;
	int ans = 0;

	while (left <= right) // left > right 가 되면 종료
	{
		int mid = (left + right) / 2;
		if (a[mid] == num)
		{
			ans = mid + 1;
			left = mid + 1; // 큰 수 중 첫번째 수를 찾기 위해 오른쪽으로 이동
		}
		else if (a[mid] < num)
		{
			left = mid + 1;
		}
		else if (a[mid] > num)
		{
			right = mid - 1;
		}
	}
	return ans;
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

		cout << upper_bound(num) - lower_bound(num);
		if (i != m - 1)
			cout << ' ';
	}
	cout << '\n';
}