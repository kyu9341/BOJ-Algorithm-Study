#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

void change(vector<int>& a, int now) // i-1, i, i+1�� ������ �Լ�
{
	for (int i = now - 1; i <= now + 1; i++)
	{
		if (i >= 0 && i < a.size()) // ���� ������
			a[i] = 1 - a[i]; // 0 -> 1, 1 -> 0
	}
}

pair<bool, int> go(vector<int> a, vector<int>& b) // a�� b�� ������, ���ٸ� �� ������ �������� ����(a�� �������� ����)
{
	int ans = 0;
	
	for (int i = 0; i < a.size() - 1; i++) 
	{
		if (a[i] != b[i]) // ���� �ε����� �ٸ���
		{
			change(a, i + 1); // i+1�� ����ġ�� ������.(0���� ������ ����)
			ans++; // ������ Ƚ�� count
		}
	}
	
	if (a == b) // ���� �� �� ���Ͱ� ���ٸ�
	{
		return { true, ans };
	}
	else
	{
		return { false, ans };
	}


}

int main(void)
{
	int n;
	cin >> n;
	string str;
	vector<int> a(n);
	vector<int> b(n);

	cin >> str;
	for (int i = 0; i < n; i++)
		a[i] = str[i] - '0';
	cin >> str;
	for (int i = 0; i < n; i++)
		b[i] = str[i] - '0';

	auto m1 = go(a, b); // 0���� ������ �ʴ� ���
	change(a, 0); // 0���� ������
	auto m2 = go(a, b); // 0���� ������ ���

	if (m2.first) m2.second++; // 0���� ������ ��� ���Խ�����

	if (m1.first && m2.first) // 0���� �����ų� ������ �ʰų� ��� ������ ���
	{
		cout << min(m1.second, m2.second) << '\n'; // �ּڰ� ���
	}
	else if (m1.first)
	{
		cout << m1.second << '\n';
	}
	else if (m2.first)
	{
		cout << m2.second << '\n';
	}
	else
	{
		cout << -1 << '\n';
	}

}