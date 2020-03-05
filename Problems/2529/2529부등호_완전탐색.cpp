#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;
vector<string> ans; // ���� �ĺ����� ������ ����
bool check[10];
int n;
char a[20]; // �ε�ȣ�� �Է¹��� �迭

bool ok(string num) // �ϼ��� ���ڿ��� �ε�ȣ�� �����ϴ��� �Ǻ�
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '<')
		{
			if (num[i] > num[i + 1]) return false;
		}
		else if (a[i] == '>')
		{
			if (num[i] < num[i + 1]) return false;
		}
	}
	return true;
}

void go(int index, string num)
{
	if (index == n + 1)
	{
		if(ok(num))
			ans.push_back(num);
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (check[i]) continue; // �ߺ� ����
		check[i] = true;
		go(index + 1, num + to_string(i)); // ���ڿ��� ����
		check[i] = false;
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	go(0, "");

	auto minmax = minmax_element(ans.begin(), ans.end());

	cout << *minmax.second << '\n'; // �ִ�
	cout << *minmax.first << '\n'; // �ּڰ�

}