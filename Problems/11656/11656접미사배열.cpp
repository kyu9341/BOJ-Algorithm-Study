#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	string substr = "";
	vector<string> v;

	cin >> str;
	for (int i = str.size() - 1; i >= 0; i--)
	{
		substr = str[i] + substr; // 모든 접미사를 벡터에 담음
		v.push_back(substr);
	}
	sort(v.begin(), v.end()); // 알파벳 순으로 정렬 default : 오름차순

	for (auto x : v)
		cout << x << '\n';
}