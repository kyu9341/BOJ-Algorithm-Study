#include<iostream>
#include<stack>
#include<vector>

using namespace std;
/*
	���� �� ���� ū ���鼭 ���������� ���� ����� �� = ��ū��
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	stack<int> s; // ���� ���� ��ū���� �ƴ� ���� �ε����� ���� ����

	cin >> n;
	vector<int> a(n);
	vector<int> res(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	s.push(0); // ù��° ���� 0���� �ʱ�ȭ
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
		{
			s.push(i); // ������ ����ִٸ� ���� �ε����� push
		}
		while (!s.empty() && a[i] > a[s.top()]) // ������ ������� �ʰ� ���� ������ ���Ұ� ���� ��ū���� ������ ���� ������ ũ��
		{
			res[s.top()] = a[i]; // a[s.top()]�� ��ū���� a[i]
			s.pop();
		}
		s.push(i); // ��ū���� ���� Ȯ������ ���� ��(=���� ������ ���� because �������� Ȯ�� �����ϹǷ�)�� �ε����� push
	}
	while (!s.empty()) // ���� ������ ������ ��ū���� ������ ���� ������ -1
	{
		res[s.top()] = -1;
		s.pop();
	}
	
	for (int i = 0; i < n; i++)
	{
		cout << res[i] << ' ';
	}
	cout << '\n';
	return 0;
}

