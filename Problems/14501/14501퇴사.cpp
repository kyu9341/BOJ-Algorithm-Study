#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int ans = 0;
void go(int n, vector<int>& t, vector<int>& p, int day, int sum)
{
	if (day == n + 1)
	{
		if (ans < sum) ans = sum; // �ݾ��� �ִ�
		return;
	}
	if (day > n + 1) return; // �Ұ����� ���
	
	go(n, t, p, day + t[day], sum + p[day]); // day�Ͽ� ����� �ϴ� ���
	go(n, t, p, day + 1, sum); // ���� �ʴ� ���
}
int main(void)
{
	int n;
	cin >> n;
	
	vector<int> t(n + 1); // ��� �Ϸῡ �ɸ��� �Ⱓ
	vector<int> p(n + 1); // �ݾ�

	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	go(n, t, p, 1, 0);
	cout << ans << '\n';
}