#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<string>
#include<utility>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);

	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			if (i == 0 || i == str.size() - 1) // 맨 앞 또는 맨 뒤 공백이면 건너뜀
				continue;
			else
				ans++;
		}
	}
	if (str == " ") // 공백만 입력되는 경우 예외처리
		cout << 0 << '\n';
	else
		cout << ans + 1 << '\n'; // 맨 앞, 맨 뒤가 아닌 공백의 수 + 1이 단어의 개수
}