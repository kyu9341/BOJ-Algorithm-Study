#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;
const int MAX = 10000;
int cnt[MAX + 1]; // �� ���� ���� ī��Ʈ

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;

	// ��� ����

	int num;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		cnt[num]++;
	}
	for (int i = 1; i <= MAX; i++)
	{
		while (cnt[i]--)
			cout << i << '\n';
	}

}