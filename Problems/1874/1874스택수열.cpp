#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void)
{
	stack<int> s;
	int n; // �׽�Ʈ ���̽� ��
	string ans; // ����� ���ڿ�

	cin >> n; 

	int m = 0; // ������ �ִ�

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;

		if (x > m) // x �� ���ÿ� ���Դ� �ִ񰪺��� ū ���
		{
			while (x > m)
			{
				s.push(++m); // ���ÿ� push
				ans += '+';
			}
			s.pop();
			ans += '-';
		}
		else
		{
			bool found = false;  // x �� �� ���� ��� ���� ������ �� ���� ���� ������ �Ǻ�
			if (!s.empty())
			{
				if (s.top == x) // ������ ���� ������ �̷� �� ����
					found = true;
				s.pop();
				ans += '-';
			}

			if (!found)
			{
				cout << "NO" << '\n';
				return 0;
			}
				
		}
		
	}

	for (auto x : ans)
		cout << x << '\n';

	return 0;
}