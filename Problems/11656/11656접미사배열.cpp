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
		substr = str[i] + substr; // ��� ���̻縦 ���Ϳ� ����
		v.push_back(substr);
	}
	sort(v.begin(), v.end()); // ���ĺ� ������ ���� default : ��������

	for (auto x : v)
		cout << x << '\n';
}