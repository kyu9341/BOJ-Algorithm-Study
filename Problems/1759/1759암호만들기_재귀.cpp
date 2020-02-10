#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

bool check(string password) // ������� ��ȣ�� ���� �ΰ� ���� �ϳ� �̻��� �����ϴ� ��ȣ���� Ȯ���ϴ� �Լ�
{
	int ja = 0;
	int mo = 0;

	for (auto x : password)
	{
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
		{
			mo++;
		}
		else
		{
			ja++;
		}
	}
	if (ja >= 2 && mo >= 1)
		return true;
	else
		return false;
}

void go(int n, vector<char>& a, string password, int i) // n : ��ȣ���ĺ� ��, a�� ����� �� �ִ� ���ĺ� ����, password : ��� ��ȣ, i : �ε���
{
	if (password.length() == n) // ��ȣ ���ĺ� ���� �� ä���� ���
	{
		if (check(password))
		{
			cout << password << '\n';
		}
		return;
	}
	if (i >= a.size()) return; // ��� a�� ���ĺ��� ����ߴµ� ��й�ȣ�� ������ ���� ���
	go(n, a, password + a[i], i + 1); // a[i] ���ĺ��� ����ϴ� ���
	go(n, a, password, i + 1); // a[i] ���ĺ��� ������� �ʴ� ���
}


int main(void)
{
	int l, c;
	cin >> l >> c;
	vector<char> a(c);
	for (int i = 0; i < c; i++) // �ĺ� ���� �Է�
		cin >> a[i];
	sort(a.begin(), a.end());
	
	string password = "";

	go(l, a, password, 0);

}