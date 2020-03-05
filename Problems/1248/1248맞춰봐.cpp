#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
char s[11][11];
vector<int> v;
int n;

bool ok(int index) // index��° ������ ������ �����ϴ��� Ȯ��
{
	int sum = 0;
	for (int i = index; i >= 0; i--) // i�� �׻� j(index)���� �۰ų� ����
	{
		sum += v[i]; // �� ����

		if (s[i][index] == '-' && sum >= 0) return false;
		if (s[i][index] == '+' && sum <= 0) return false;
		if (s[i][index] == '0' && sum != 0) return false;

	}
	return true;
}

void go(int index)
{
	if (index == n) // ���� ���� ���
	{
		for (int i = 0; i < n; i++)
			cout << v[i] << ' ';
		cout << '\n';
		exit(0); // ���α׷� ����
	}

	for (int i = -10; i <= 10; i++)
	{
		v.push_back(i);
		if (ok(index)) go(index + 1); // ������ �����ϴ� ��츸 ��� ����
		v.pop_back();
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			cin >> s[i][j];

	go(0);

}