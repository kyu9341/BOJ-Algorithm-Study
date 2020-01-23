#include<iostream>
#include<string>

using namespace std;

int main()
{
	int alphabet[26]; // 알파벳의 처음 등장 위치를 저장할 배열
	string str;

	for (auto& x : alphabet) // 모든 값을 -1로 초기화
		x = -1;

	cin >> str;
	int size = str.size();
	for (int i = 0; i < size; i++)
	{
		if (alphabet[str[i] - 'a'] != -1) // -1 즉, 이전에 등장했던 알파벳인 경우 넘어감(처음 위치를 구하는 것이므로)
			continue;
		alphabet[str[i] - 'a'] = i; // 각 알파벳의 해당 인덱스에 현재 문자열의 인덱스를 저장
	}

	for (auto x : alphabet)
		cout << x << ' ';
	cout << '\n';

	return 0;
}