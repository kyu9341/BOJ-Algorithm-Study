#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	int n; // ������ ũ��
	int count[1000001] = {0}; // �� ������ ������ ������ ī��Ʈ�� �迭
	
	cin >> n;

	vector<int> a(n);
	vector<int> res(n);
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		count[a[i]]++;
	}
	
	s.push(0); // ���� 
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
			s.push(i);
		while (!s.empty() && count[a[i]] > count[a[s.top()]]) // ������ ������ �� - ������ top������ �ε��� ���� ũ��
		{
			res[s.top()] = a[i]; // ���ū���̹Ƿ� ����
			s.pop();
		}
		s.push(i);
	}

	while (!s.empty())
	{
		res[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << '\n';

	


	return 0;
}