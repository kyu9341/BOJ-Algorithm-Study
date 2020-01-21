#include<iostream>
#include<stack>
#include<vector>

using namespace std;
/*
	현재 수 보다 큰 수면서 오른쪽으로 가장 가까운 수 = 오큰수
*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	stack<int> s; // 다음 수가 오큰수가 아닌 수의 인덱스를 담을 스택

	cin >> n;
	vector<int> a(n);
	vector<int> res(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	s.push(0); // 첫번째 원소 0으로 초기화
	for (int i = 1; i < n; i++)
	{
		if (s.empty())
		{
			s.push(i); // 스택이 비어있다면 현재 인덱스를 push
		}
		while (!s.empty() && a[i] > a[s.top()]) // 스택이 비어있지 않고 현재 수열의 원소가 아직 오큰수를 구하지 못한 수보다 크면
		{
			res[s.top()] = a[i]; // a[s.top()]의 오큰수는 a[i]
			s.pop();
		}
		s.push(i); // 오큰수를 아직 확인하지 못한 수(=현재 수열의 원소 because 다음번에 확인 가능하므로)의 인덱스를 push
	}
	while (!s.empty()) // 위의 과정이 끝나고 오큰수를 구하지 못한 수들은 -1
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

