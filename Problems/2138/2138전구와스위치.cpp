#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

void change(vector<int>& a, int now) // i-1, i, i+1을 뒤집는 함수
{
	for (int i = now - 1; i <= now + 1; i++)
	{
		if (i >= 0 && i < a.size()) // 범위 내에서
			a[i] = 1 - a[i]; // 0 -> 1, 1 -> 0
	}
}

pair<bool, int> go(vector<int> a, vector<int>& b) // a와 b가 같은지, 같다면 몇 번만에 가능한지 리턴(a를 변경하지 않음)
{
	int ans = 0;
	
	for (int i = 0; i < a.size() - 1; i++) 
	{
		if (a[i] != b[i]) // 현재 인덱스가 다르면
		{
			change(a, i + 1); // i+1의 스위치를 누른다.(0번은 누르지 않음)
			ans++; // 누르는 횟수 count
		}
	}
	
	if (a == b) // 연산 후 두 벡터가 같다면
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

	auto m1 = go(a, b); // 0번을 누르지 않는 경우
	change(a, 0); // 0번을 누른다
	auto m2 = go(a, b); // 0번을 누르는 경우

	if (m2.first) m2.second++; // 0번을 누르는 경우 포함시켜줌

	if (m1.first && m2.first) // 0번을 누르거나 누르지 않거나 모두 가능한 경우
	{
		cout << min(m1.second, m2.second) << '\n'; // 최솟값 출력
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