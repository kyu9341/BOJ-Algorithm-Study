#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

string eraseB(string t) // 마지막 자리의 B를 지우고 문자열을 뒤집는 함수
{
	reverse(t.begin(), t.end());
	t.erase(t.begin(), t.begin() + 1);
	return t;
}
string eraseA(string t) // 마지막 자리의 A를 지우는 함수
{
	t.erase(t.end() - 1, t.end());
	return t;
}

int main(void)
{
	string s, t;
	cin >> s >> t;
	int size_S = s.size();

	while (t.size() > size_S) // t와 s의 크기가 같아질 때까지 반복
	{
		int last_T = t.size() - 1;
		if (t[last_T] == 'A') // t의 마지막 문자가 A라면 A를 지움
			t = eraseA(t);
		else if (t[last_T] == 'B') // B라면 B를 지우고 뒤집음
			t = eraseB(t);

	}

	if (t == s) cout << 1 << '\n'; // 크기가 같아졌을 때, 문자열이 같다면 s를 t로 바꿀 수 있음
	else cout << 0 << '\n';

}