#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<queue>

using namespace std;
int n;
int op[4]; // +, -, *, / 

int calc(vector<int>& a, vector<int> &d) // 현재 연산자의 순서로 결과를 구하는 함수
{
	int result = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (d[i] == 0)
			result += a[i + 1];
		else if (d[i] == 1)
			result -= a[i + 1];
		else if (d[i] == 2)
			result *= a[i + 1];
		else
			result /= a[i + 1];
	}
	return result;

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	vector<int> d;

	for (int i = 0; i < 4; i++) // 각 연산자의 수만큼 벡터에 추가
	{	// 0 : +, 1 : -, 2 : *, 3 : /
		while (op[i] > 0)
		{
			d.push_back(i);
			op[i]--;
		}
	}
	vector<int> ans;
	do
	{
		ans.push_back(calc(a, d));
	} while (next_permutation(d.begin(), d.end())); // 모든 순열을 확인

	auto res = minmax_element(ans.begin(), ans.end()); // 최대, 최소 구하기
	cout << *res.second << '\n';
	cout << *res.first << '\n';

}