#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<climits>

using namespace std;
int op[4];
bool check[11];
int n;
int max_ans = -INT_MAX + 1; // �ִ��� �����ϼ��� ����
int min_ans = INT_MAX;

void go(vector<int>& a, int index, int plus, int minus, int multi, int div, int res)
{
	if (index == n) // �ʿ��� �������� ������ ��������
	{
		if (max_ans < res) max_ans = res; // �ִ�
		if (min_ans > res) min_ans = res; // �ּ�
		return;
	}

	// �� �������� ���� 0���� Ŭ ��, ���
	if (plus > 0) go(a, index + 1, plus - 1, minus, multi, div, res + a[index]);
	if (minus > 0) go(a, index + 1, plus, minus - 1, multi, div, res - a[index]);
	if (multi > 0) go(a, index + 1, plus, minus, multi - 1, div, res * a[index]);
	if (div > 0) go(a, index + 1, plus, minus, multi, div - 1, res / a[index]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < 4; i++)
		cin >> op[i];
	
	go(a, 1, op[0], op[1], op[2], op[3], a[0]);

	cout << max_ans << '\n';
	cout << min_ans << '\n';
	
}