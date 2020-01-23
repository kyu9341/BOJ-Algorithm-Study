#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	int alphabet[26] = {0}; // 각 알파벳 개수를 담을 배열

	cin >> str;
	int size = str.size();

	for (int i = 0; i < size; i++)
	{
		alphabet[str[i] - 'a']++; // 'a'의 아스키 코드 값을 빼주어 해당하는 알파벳의 인덱스를 맞춰줌
	}
	
	for (auto x : alphabet)
		cout << x << ' ';

	cout << '\n';

	return 0;
}