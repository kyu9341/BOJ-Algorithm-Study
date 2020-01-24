#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	int count[4] = { 0 }; // 각 문자열 성분을 카운트할 배열

	int n = 100;

	while (n--)
	{
		getline(cin, str);
		int size = str.size();

		if (size == 0) break;  // 입력을 안하면 종료

		for (int i = 0; i < size; i++)
		{
			if (str[i] >= 'a' && str[i] <= 'z') // 소문자 count
				count[0]++;
			else if (str[i] >= 'A' && str[i] <= 'Z') // 대문자 count
				count[1]++;
			else if (str[i] >= '0' && str[i] <= '9') // 숫자 count
				count[2]++;
			else if (str[i] == ' ' || str[i] == '\t') // 공백 count
				count[3]++;
		}

		for (auto& x : count) // 출력 및 초기화
		{
			cout << x << ' ';
			x = 0;
		}

		cout << '\n';
	}

}

