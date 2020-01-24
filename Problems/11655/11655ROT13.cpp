#include<iostream>
#include<string>

using namespace std;

int main(void)
{
	string str;
	getline(cin, str);

	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z'))
		{
			
			if (str[i] + 13 > 'z') // 아스키 코드는 127번까지 있는데 s이상의 알파벳에 13을 더하면 범위를 벗어남
				cout << char(str[i] - 13); // 넘어가지 않는 선에서 처리
			else
				cout << char(str[i] + 13);
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (str[i] + 13 > 'Z')
				cout << char(str[i] - 13);
			else
				cout << char(str[i] + 13);

		}
		else
		{
			cout << str[i];
		}
	}
}