#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<queue>

using namespace std;
string s, t;

string eraseB(string t) // 맨 앞 자리의 B를 지우고 문자열을 뒤집는 함수
{
	t.erase(t.begin(), t.begin() + 1);
	reverse(t.begin(), t.end());
	return t;
}
string eraseA(string t) // 마지막 자리의 A를 지우는 함수
{
	t.erase(t.end() - 1, t.end());
	return t;
}

void go(string str)
{
	int size_str = str.size();
	if (s.size() == size_str) // 두 문자열의 크기가 같다면
	{
		if (s == str) // 문자열을 비교
		{
			cout << 1 << '\n'; // 같으면 1 출력 후 종료
			exit(0);
		}
		return;
	}

	if (str[0] == 'A' && str[size_str - 1] == 'B')
		return; // 맨 앞이 A이면서 맨 뒤가 B라면 무조건 잘못된 경우

	if (str[0] == 'B') // 맨 앞 문자가 B인 경우
		go(eraseB(str)); // B를 지우고 뒤집는다

	if (str[size_str - 1] == 'A') // 맨 뒤 문자가 A인 경우
		go(eraseA(str)); // A를 지운다.
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s >> t;

	go(t);

	cout << 0 << '\n';

}