#include<iostream>

using namespace std;
int go(int sum, int goal)
{
	if (sum > goal) return 0;	// 1, 2, 3���� ���ϴ� ���� ���� �� ���� ���
	if (sum == goal) return 1;  // ���� ���
	int count = 0;
	for (int i = 1; i <= 3; i++)
		count += go(sum + i, goal);
	return count;
}
int main(void)
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		cout << go(0, n) << '\n';
	}
}