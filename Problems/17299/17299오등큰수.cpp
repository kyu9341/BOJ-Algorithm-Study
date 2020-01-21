#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main()
{
	int n; // 수열의 크기
	int count[1000001] = {0}; // 각 수열의 원소의 개수를 카운트할 배열
	
	cin >> n;

	vector<int> a(n);
	vector<int> res(n);
	stack<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		count[a[i]]++;
	}
	
	s.push(0); // 스택 
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
			s.push(i);
		while (!s.empty() && count[a[i]] > count[a[s.top()]]) // 원소의 개수로 비교 - 스택의 top원소의 인덱스 보다 크면
		{
			res[s.top()] = a[i]; // 우등큰수이므로 저장
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